################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
software_stack/ti15_4stack/nv/crc.o: C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/nv/crc.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1270/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/defines/sensor.opt"  -mcpu=cortex-m33 -mfloat-abi=hard -mfpu=fpv5-sp-d16 -mlittle-endian -Oz -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/Release" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/sensor" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/clock" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/GUI" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/GUI/UGUI" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/sensor/link_controller" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/defines" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/osal_port" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/low_level/cc13xx" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/apps/sensor" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/nv" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/cui" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/cui" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/software_stack/ti15_4stack/osal" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/apps" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/boards" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/util" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/stack/src" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/stack/tirtos/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/heapmgr" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/services/saddr" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/services/sdata" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/crypto" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/platform" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/rf" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/fh" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/high_level" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/rom" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/inc/cc13xx" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/tracer" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4/driverlib" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/third_party/mbedtls/ti" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/third_party/mbedtls/include" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/kernel/tirtos7/packages" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/posix/ticlang" -DxTIMAC_ROM_IMAGE_BUILD -DBoard_EXCLUDE_NVS_EXTERNAL_FLASH -gdwarf-3 -fdiagnostics-show-option -fshort-enums -munaligned-access -funsigned-char -fcommon -ffunction-sections -fno-strict-aliasing -MMD -MP -MF"software_stack/ti15_4stack/nv/crc.d_raw" -MT"software_stack/ti15_4stack/nv/crc.o" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/Release/syscfg" -std=gnu9x $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

software_stack/ti15_4stack/nv/nvocmp.o: C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/nv/nvocmp.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1270/ccs/tools/compiler/ti-cgt-armllvm_3.2.2.LTS/bin/tiarmclang.exe" -c @"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/defines/sensor.opt"  -mcpu=cortex-m33 -mfloat-abi=hard -mfpu=fpv5-sp-d16 -mlittle-endian -Oz -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/Release" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/sensor" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/clock" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/GUI" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/GUI/UGUI" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/sensor/link_controller" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/defines" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/osal_port" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/low_level/cc13xx" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/apps/sensor" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/nv" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/common/cui" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/application/cui" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/software_stack/ti15_4stack/osal" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/apps" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/boards" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/util" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/stack/src" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/stack/tirtos/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/common/heapmgr" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/services/saddr" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/services/sdata" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/crypto" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/platform" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/hal/rf" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/fh" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/high_level" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/rom" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/inc/cc13xx" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/ti154stack/tracer" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4/driverlib" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/devices/cc13x4_cc26x4/inc" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/third_party/mbedtls/ti" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/third_party/mbedtls/include" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/kernel/tirtos7/packages" -I"C:/ti/simplelink_cc13xx_cc26xx_sdk_7_41_00_17/source/ti/posix/ticlang" -DxTIMAC_ROM_IMAGE_BUILD -DBoard_EXCLUDE_NVS_EXTERNAL_FLASH -gdwarf-3 -fdiagnostics-show-option -fshort-enums -munaligned-access -funsigned-char -fcommon -ffunction-sections -fno-strict-aliasing -MMD -MP -MF"software_stack/ti15_4stack/nv/nvocmp.d_raw" -MT"software_stack/ti15_4stack/nv/nvocmp.o" -I"C:/Users/hzaib/Documents/Freelance Projects/Mughees proj/Ring ding project/watch workspace/sensor_watch/Release/syscfg" -std=gnu9x $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

