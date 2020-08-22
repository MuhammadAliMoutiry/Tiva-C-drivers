################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/bin/arm-none-eabi-gcc-7.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"D:/Muhammad_Ali/Courses/IMT/arm/ARM_WS/TivaSDK/System/01-LIB/01-STD_TYPES" -I"D:/Muhammad_Ali/Courses/IMT/arm/ARM_WS/TivaSDK/System/02-MCAL/02-GPIO" -I"D:/Muhammad_Ali/Courses/IMT/arm/ARM_WS/TivaSDK/System/01-LIB/02-BIT_MATH" -I"D:/Muhammad_Ali/Courses/IMT/arm/ARM_WS/TivaSDK/System/02-MCAL/01-SYSCTRL" -I"D:/Muhammad_Ali/Courses/IMT/arm/ARM_WS/TivaSDK" -I"C:/ti/ccs920/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major-win32/arm-none-eabi/include" -O0 -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


