################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USER/Src/packet_parser.c 

OBJS += \
./USER/Src/packet_parser.o 

C_DEPS += \
./USER/Src/packet_parser.d 


# Each subdirectory must supply rules for building sources it contributes
USER/Src/%.o USER/Src/%.su USER/Src/%.cyclo: ../USER/Src/%.c USER/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/y6484/f429_workspace/pcTOstm32_ground/Core/Inc" -I"C:/Users/y6484/f429_workspace/pcTOstm32_ground/USER" -I"C:/Users/y6484/f429_workspace/pcTOstm32_ground/USER/Inc" -I"C:/Users/y6484/f429_workspace/pcTOstm32_ground/USER/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-USER-2f-Src

clean-USER-2f-Src:
	-$(RM) ./USER/Src/packet_parser.cyclo ./USER/Src/packet_parser.d ./USER/Src/packet_parser.o ./USER/Src/packet_parser.su

.PHONY: clean-USER-2f-Src

