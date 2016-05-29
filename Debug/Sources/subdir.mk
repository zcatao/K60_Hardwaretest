################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/main.c \
../Sources/user_i2c_irq.c \
../Sources/user_pit_irq.c \
../Sources/user_uart_irq.c 

OBJS += \
./Sources/main.o \
./Sources/user_i2c_irq.o \
./Sources/user_pit_irq.o \
./Sources/user_uart_irq.o 

C_DEPS += \
./Sources/main.d \
./Sources/user_i2c_irq.d \
./Sources/user_pit_irq.d \
./Sources/user_uart_irq.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK60DN512VLQ10" -I"../Sources" -I../Board -I../Sources/Utilities -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/system/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/hal/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/drivers/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/osa/inc" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK60D10/include" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


