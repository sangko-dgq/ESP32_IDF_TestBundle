# Additional clean files

file(REMOVE_RECURSE
  "bootloader/bootloader.bin"
  "bootloader/bootloader.elf"
  "bootloader/bootloader.map"
  "config/sdkconfig.cmake"
  "config/sdkconfig.h"
  "esp-idf/esptool_py/flasher_args.json.in"
  "esp-idf/mbedtls/x509_crt_bundle"
  "flash_app_args"
  "flash_bootloader_args"
  "flash_project_args"
  "flasher_args.json"
  "idf_t2_lcdST7789.bin"
  "idf_t2_lcdST7789.map"
  "ldgen_libraries"
  "ldgen_libraries.in"
  "project_elf_src_esp32.c"
  "x509_crt_bundle.S"
)
