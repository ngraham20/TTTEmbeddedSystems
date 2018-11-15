################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.o: ../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407G_DISC1 -DDEBUG -DSTM32F407xx -DUSE_HAL_DRIVER -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ili9325" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/s25fl512s" -I"C:/Users/loder/workspace/TTTFinal/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/cs43l22" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ili9341" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ampire480272" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/n25q512a" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/s5k5cag" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/mfxstm32l152" -I"C:/Users/loder/workspace/TTTFinal/CMSIS/device" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/n25q128a" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ts3510" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/st7735" -I"C:/Users/loder/workspace/TTTFinal/HAL_Driver/Inc/Legacy" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/lis302dl" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/otm8009a" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/stmpe1600" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/Common" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ov2640" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/l3gd20" -I"C:/Users/loder/workspace/TTTFinal/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/loder/workspace/TTTFinal/HAL_Driver/Inc" -I"C:/Users/loder/workspace/TTTFinal/Utilities" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/stmpe811" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/lis3dsh" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/wm8994" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/n25q256a" -I"C:/Users/loder/workspace/TTTFinal/inc" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ls016b8uy" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ft6x06" -I"C:/Users/loder/workspace/TTTFinal/Utilities/STM32F4-Discovery" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/exc7200" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/st7789h2" -I"C:/Users/loder/workspace/TTTFinal/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/ampire640480" -I"C:/Users/loder/workspace/TTTFinal/Utilities/Components/lsm303dlhc" -I"C:/Users/loder/workspace/TTTFinal/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


