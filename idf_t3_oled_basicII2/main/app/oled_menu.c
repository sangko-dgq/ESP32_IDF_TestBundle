#include "oled_menu.h"

#define OLED_Hight 64			// 定义OLED屏幕高度
#define OLED_Width 128			// 定义OLED屏幕宽度
#define OLED_Rectangle_Hight 20 // 定义选择框的高度
#define MENU_LEVEL 3			// 菜单级别，支持三级菜单
#define MENU_MODE 0				// 显示模式，0为文本，1为图像

MENU_t menu;				   // 当前菜单
MENU_t *prev_menu[MENU_LEVEL]; // 存储上一级菜单指针

// 一级菜单项目
MENU_Item_t menu_item[] =
	{
		{"Item1", Item1_Callback},
		{"Item2", Item2_Callback},
		{"Item3", Item3_Callback},
		{"Item4", Item4_Callback},
		{"Item5", Item5_Callback},
		{"Item6", Item6_Callback},
};

// 二级菜单项目
MENU_Item_t second_menu_item[] =
	{
		{"second_Item1", SUB1_Callback},
		{"second_Item2", SUB2_Callback},
		{"second_Item3", SUB3_Callback},
};

// 三级菜单项目
MENU_Item_t third_menu_item[] =
	{
		{"third_Item1", Third1_Callback},
		{"third_Item2", Third2_Callback},
		{"third_Item3", Third3_Callback},
		{"third_Item4", Third4_Callback},
};

// 释放所有动态分配的内存
void MENU_FreeMemory(void)
{
#if MENU_LEVEL >= 2
	if (menu.sub2_menu != NULL)
	{
#if MENU_LEVEL >= 3
		if (menu.sub2_menu->sub3_menu != NULL)
		{
			free(menu.sub2_menu->sub3_menu);
		}
#endif
		free(menu.sub2_menu);
	}
	for (int i = 0; i < MENU_LEVEL; i++)
	{
		if (prev_menu[i] != NULL)
		{
			free(prev_menu[i]);
		}
	}
#endif
}

void delay_ms(uint32_t ms)
{
	vTaskDelay(ms / portTICK_PERIOD_MS);
}

// 一级菜单回调函数
void Item1_Callback(void)
{
	MENU_INPUT(0, menu, menu.sub2_menu, 0, 1); // 进入二级菜单
}

void Item2_Callback(void)
{
	menu.cur_item = 1;
}

void Item3_Callback(void)
{
	// 可添加具体功能
}

void Item4_Callback(void)
{
	// 可添加具体功能
}

void Item5_Callback(void)
{
	// 可添加具体功能
}

void Item6_Callback(void)
{
	// 可添加具体功能
}

// 二级菜单回调函数
void SUB1_Callback(void)
{
	MENU_INPUT(0, menu, menu.sub2_menu->sub3_menu, 0, 2); // 进入三级菜单
}

void SUB2_Callback(void)
{
	// 可添加具体功能
}

void SUB3_Callback(void)
{
	// 可添加具体功能
}

// 三级菜单回调函数
void Third1_Callback(void)
{
	// 可添加具体功能
}

void Third2_Callback(void)
{
	// 可添加具体功能
}

void Third3_Callback(void)
{
	// 可添加具体功能
}

void Third4_Callback(void)
{
	// 可添加具体功能
}

// 初始化菜单
int MENU_Init(void)
{
	// 初始化当前菜单
	menu.item = menu_item;
	menu.item_num = sizeof(menu_item) / sizeof(menu_item[0]);
	menu.cur_item = 0;
	menu.menu_flag = 0;

#if MENU_LEVEL >= 2
	menu.sub2_menu = (MENU_t *)malloc(sizeof(MENU_t)); // 分配二级菜单内存
	if (menu.sub2_menu == NULL)
	{
		MENU_FreeMemory();
		return -1; // 内存分配失败
	}
	menu.sub2_menu->item = second_menu_item;
	menu.sub2_menu->item_num = sizeof(second_menu_item) / sizeof(second_menu_item[0]);
	menu.sub2_menu->cur_item = 0;

#if MENU_LEVEL >= 3
	menu.sub2_menu->sub3_menu = (MENU_t *)malloc(sizeof(MENU_t)); // 分配三级菜单内存
	if (menu.sub2_menu->sub3_menu == NULL)
	{
		MENU_FreeMemory();
		return -1; // 内存分配失败
	}
	menu.sub2_menu->sub3_menu->item = third_menu_item;
	menu.sub2_menu->sub3_menu->item_num = sizeof(third_menu_item) / sizeof(third_menu_item[0]);
	menu.sub2_menu->sub3_menu->cur_item = 0;
#endif
#endif
	return 0;
}

// 菜单按键扫描
void MENU_KeyScan(uint8_t key)
{
	switch (key)
	{
	case 0:
		MENU_Mode_chang();
		break;
	case 1:
		if (menu.cur_item > 0)
		{
			menu.cur_item--;
			MENU_Mode_chang();
		}
		break;
	case 2:
		if (menu.menu_flag < MENU_LEVEL - 1)
		{
			if (menu.menu_flag == 0)
			{
				MENU_INPUT(0, menu, menu.sub2_menu, 0, 1); // 进入二级菜单
			}
			else if (menu.menu_flag == 1)
			{
				MENU_INPUT(0, menu, menu.sub2_menu->sub3_menu, 0, 2); // 进入三级菜单
			}
		}
		break;
	case 3:
		if (menu.cur_item < menu.item_num)
		{
			menu.item[menu.cur_item].func(); // 执行当前项回调函数
		}
		break;
	case 4:
		MENU_RETURN();
		break;
	case 5:
		if (menu.cur_item < menu.item_num - 1)
		{
			menu.cur_item++;
			MENU_Mode_chang();
		}
		break;
	default:
		break;
	}
}

// 进入子菜单
void MENU_INPUT(uint8_t cur_item_ok, MENU_t menu_ok, MENU_t *sub_menu_ok, uint8_t cur_item_next_ok, uint8_t menu_flag_ok)
{
	if (menu_flag_ok < MENU_LEVEL)
	{
		prev_menu[menu_flag_ok] = (MENU_t *)malloc(sizeof(MENU_t));
		if (prev_menu[menu_flag_ok] == NULL)
		{
			return; // 内存分配失败
		}
		*prev_menu[menu_flag_ok] = menu_ok; // 保存当前菜单状态
	}
	menu = *sub_menu_ok;			  // 切换到子菜单
	menu.cur_item = cur_item_next_ok; // 设置当前项为0
	menu.menu_flag = menu_flag_ok;	  // 设置菜单级别

	MENU_Mode_chang();
}

// 返回上一级菜单
void MENU_RETURN(void)
{
	if (menu.menu_flag > 0)
	{
		menu = *prev_menu[menu.menu_flag]; // 返回上一级菜单
		menu.cur_item = 0;
		menu.menu_flag--;
		free(prev_menu[menu.menu_flag + 1]); // 释放当前菜单的上一级菜单内存
		prev_menu[menu.menu_flag + 1] = NULL;
	}
	MENU_Mode_chang();
}

// 文本菜单显示
void MENU_Text_Display(void)
{
	uint8_t i;				  // 菜单文本循环变量
	uint8_t x = 0, y = 0;	  // 显示起始坐标
	uint8_t menu_display = 0; // 显示标志位
	uint16_t pos;			  // 移动位置
	char str[20];			  // 菜单文本字符串

	OLED_Clear(); // 清屏

	static uint8_t old_item = 0;							  // 上一次选择项
	uint8_t old_y = y + old_item * OLED_Rectangle_Hight;	  // 上一次选择项位置
	uint8_t new_y = y + menu.cur_item * OLED_Rectangle_Hight; // 当前选择项位置

	uint8_t visiable_items = (menu.item_num < 3) ? menu.item_num : 3;  // 动态计算屏幕可见菜单项目数
	uint8_t start_index = (menu.cur_item < 2) ? 0 : menu.cur_item - 2; // 根据当前选择项计算起始索引

	if (start_index + visiable_items > menu.item_num)
	{ // 防止越界
		start_index = menu.item_num - visiable_items;
	}

	for (i = 0; i < visiable_items; i++)
	{
		if (start_index + i < menu.item_num)
		{ // 防止越界
			sprintf(str, "%s", menu.item[start_index + i].name);
			OLED_ShowString(x + 5, y + i * OLED_Rectangle_Hight + 2, str, OLED_8X16); // 显示静态菜单文本
		}
	}

	OLED_DrawRectangle(x, new_y, OLED_Width, OLED_Rectangle_Hight, OLED_UNFILLED); // 绘制选择框

	if (menu.cur_item >= 3)
	{
		pos = 26;		  // 选择框固定位置
		menu_display = 1; // 显示滚动屏幕标志位置1
	}

	if (old_item != menu.cur_item)
	{
		for (pos = old_y; pos != new_y; pos += (new_y > old_y) ? 2 : -2)
		{
			OLED_Clear();
			for (i = 0; i < visiable_items; i++)
			{
				if (start_index + i < menu.item_num)
				{ // 防止越界
					sprintf(str, "%s", menu.item[start_index + i].name);
					OLED_ShowString(x + 5, y + i * OLED_Rectangle_Hight + 2, str, OLED_8X16); // 显示静态菜单文本
				}
			}
			if (menu_display == 1)
			{
				OLED_DrawRectangle(x, pos - (OLED_Rectangle_Hight * (menu.cur_item - 2)), OLED_Width, OLED_Rectangle_Hight, OLED_UNFILLED); // 固定滚动显示选择框
			}
			else
			{
				OLED_DrawRectangle(x, pos, OLED_Width, OLED_Rectangle_Hight, OLED_UNFILLED); // 动态显示移动选择框
				OLED_Update();
			}
			delay_ms(20);
		}
		old_item = menu.cur_item; // 更新显示项
	}
	OLED_Update();
}

// 图像菜单显示
void MENU_Image_Display(uint8_t image_index) // 修正拼写错误
{
	static uint8_t old_item = 0;
	const uint8_t *image_data_level_1[] = {ear, game, chess, fish, badminton, music};
	const uint8_t *image_data_level_2[] = {book, tool, brush};
	const uint8_t *image_data_level_3[] = {caravan, shopping, telephone, telescope};
	const uint8_t **image_data;

	switch (menu.menu_flag)
	{
	case 0:
		image_data = image_data_level_1;
		break;
	case 1:
		image_data = image_data_level_2;
		break;
	case 2:
		image_data = image_data_level_3;
		break;
	default:
		image_data = image_data_level_1;
		image_index = 0;
		break;
	}

	size_t image_data_size;
	switch (menu.menu_flag)
	{
	case 0:
		image_data_size = sizeof(image_data_level_1) / sizeof(image_data_level_1[0]);
		break;
	case 1:
		image_data_size = sizeof(image_data_level_2) / sizeof(image_data_level_2[0]);
		break;
	case 2:
		image_data_size = sizeof(image_data_level_3) / sizeof(image_data_level_3[0]);
		break;
	default:
		image_data_size = sizeof(image_data_level_1) / sizeof(image_data_level_1[0]);
		break;
	}

	if (image_index < image_data_size)
	{
		OLED_Clear(); // 清屏
		OLED_ShowImage(32, 0, 64, 64, image_data[image_index]);
		OLED_ShowImage(0, 16, 32, 32, left);
		OLED_ShowImage(96, 16, 32, 32, right);
		OLED_Update();

		if (old_item != menu.cur_item)
		{
			if (menu.cur_item < old_item)
			{
				OLED_ClearArea(0, 16, 32, 32);
				OLED_Update();
				delay_ms(200);
				OLED_ShowImage(0, 16, 32, 32, left);
			}
			else if (menu.cur_item > old_item)
			{
				OLED_ClearArea(96, 16, 32, 32);
				OLED_Update();
				delay_ms(200);
				OLED_ShowImage(96, 16, 32, 32, right);
			}
			OLED_Update();
		}
		old_item = menu.cur_item;
	}
}

// 菜单显示模式切换
void MENU_Mode_chang(void)
{
#if MENU_MODE == 0
	MENU_Text_Display();
#endif

#if MENU_MODE == 1
	MENU_Image_Display(menu.cur_item);
#endif
}