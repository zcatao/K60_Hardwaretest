################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Utilities/fsl_debug_console.c \
../Sources/Utilities/fsl_misc_utilities.c \
../Sources/Utilities/print_scan.c 

OBJS += \
./Sources/Utilities/fsl_debug_console.o \
./Sources/Utilities/fsl_misc_utilities.o \
./Sources/Utilities/print_scan.o 

C_DEPS += \
./Sources/Utilities/fsl_debug_console.d \
./Sources/Utilities/fsl_misc_utilities.d \
./Sources/Utilities/print_scan.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Utilities/%.o: ../Sources/Utilities/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK60DN512VLQ10" -I"../Sources" -I../Sources/Board -I../Sources/Utilities -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/system/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/hal/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/drivers/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/osa/inc" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK60D10/include" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


