from PIL import Image
import os

# 配置参数
WIDTH = 128
HEIGHT = 64
FRAME_BUFFER_SIZE = WIDTH * HEIGHT // 8  # 1024 字节 (128x64 像素，每字节8位)
INPUT_DIR = "./frames"
OUTPUT_FILE = "./main/aniBuf.c"
OUTPUT_HEADER = "aniBuf.h"

def drawPixel(x, y, colour, buffer):
    """在缓冲区中设置像素值"""
    # 边界检查
    if x < 0 or x >= WIDTH or y < 0 or y >= HEIGHT:
        return
    
    byte_index = (y // 8) * WIDTH + x
    if 0 <= byte_index < len(buffer):
        if colour == 1:
            buffer[byte_index] |= 1 << (y % 8)
        else:
            buffer[byte_index] &= ~(1 << (y % 8))

def process_frame(image_path):
    """处理单个帧图像并转换为字节缓冲区"""
    try:
        buffer = [0] * FRAME_BUFFER_SIZE
        with Image.open(image_path) as im:
            im = im.convert('RGBA')
            width, height = im.size
            px = im.load()
            
            # 处理每个像素
            for y in range(min(height, HEIGHT)):
                for x in range(min(width, WIDTH)):
                    # 检查像素是否为暗色 (非白色)
                    r, g, b, a = px[x, y]
                    if r < 250 and g < 250 and b < 250:
                        # 应用偏移 (可根据需要调整)
                        drawPixel(x + 32, y, 1, buffer)
        return buffer
    except Exception as e:
        print(f"处理帧 {image_path} 时出错: {e}")
        return None

def main():
    """主函数：处理所有帧并生成C数组文件"""
    # 确保输出目录存在
    os.makedirs(os.path.dirname(OUTPUT_FILE), exist_ok=True)
    
    # 获取并排序帧文件
    try:
        files = sorted(os.listdir(INPUT_DIR))
        frame_files = [f for f in files if os.path.isfile(os.path.join(INPUT_DIR, f))]
        
        if not frame_files:
            print("错误：在输入目录中未找到图像文件")
            return
        
        print(f"找到 {len(frame_files)} 个帧文件")
        
        # 生成输出字符串
        output = [f"#include \"{OUTPUT_HEADER}\"\n\n"]
        output.append(f"const unsigned char bufferAnimation[{len(frame_files)}][{FRAME_BUFFER_SIZE}]={{\n")
        
        # 处理每个帧
        for i, file in enumerate(frame_files):
            file_path = os.path.join(INPUT_DIR, file)
            buffer = process_frame(file_path)
            
            if buffer is not None:
                output.append("  {")
                # 每行输出16个字节，提高可读性
                for j, byte in enumerate(buffer):
                    output.append(f"{byte},")
                    if (j + 1) % 16 == 0:
                        output.append("\n   ")
                output[-1] = output[-1].rstrip()  # 移除最后一个逗号后的空格
                output.append("},\n")
                print(f"已处理帧 {i+1}/{len(frame_files)}: {file}")
        
        # 完成输出
        if output[-1].endswith(",\n"):
            output[-1] = output[-1][:-2] + "\n"  # 移除最后一个逗号
        output.append("};\n")
        
        # 写入文件
        with open(OUTPUT_FILE, "w") as f:
            f.write(''.join(output))
        
        print(f"成功生成文件: {OUTPUT_FILE}")
        
    except Exception as e:
        print(f"处理过程中发生错误: {e}")

if __name__ == "__main__":
    main()