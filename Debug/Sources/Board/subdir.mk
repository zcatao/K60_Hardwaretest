################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Board/Hardware_init.c \
../Sources/Board/board.c \
../Sources/Board/gpio_pins.c \
../Sources/Board/pin_mux.c 

OBJS += \
./Sources/Board/Hardware_init.o \
./Sources/Board/board.o \
./Sources/Board/gpio_pins.o \
./Sources/Board/pin_mux.o 

C_DEPS += \
./Sources/Board/Hardware_init.d \
./Sources/Board/board.d \
./Sources/Board/gpio_pins.d \
./Sources/Board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Board/%.o: ../Sources/Board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK60DN512VLQ10" -I"../Sources" -I../Sources/Board -I../Sources/Utilities -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/system/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/hal/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/drivers/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/osa/inc" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK60D10/include" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


