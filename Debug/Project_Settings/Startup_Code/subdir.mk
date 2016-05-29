################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Settings/Startup_Code/startup.c \
../Project_Settings/Startup_Code/system_MK60D10.c 

S_UPPER_SRCS += \
../Project_Settings/Startup_Code/startup_MK60D10.S 

OBJS += \
./Project_Settings/Startup_Code/startup.o \
./Project_Settings/Startup_Code/startup_MK60D10.o \
./Project_Settings/Startup_Code/system_MK60D10.o 

C_DEPS += \
./Project_Settings/Startup_Code/startup.d \
./Project_Settings/Startup_Code/system_MK60D10.d 

S_UPPER_DEPS += \
./Project_Settings/Startup_Code/startup_MK60D10.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MK60DN512VLQ10" -I"../Sources" -I../Board -I../Sources/Utilities -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/system/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/hal/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/drivers/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/osa/inc" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MK60D10/include" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/inc" -I"C:\Users\yangs\OneDrive\文档\竞赛\飞思卡尔\2016年\开发环境\SDK_1.3_MK60DN512xxx10/platform/utilities/src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


