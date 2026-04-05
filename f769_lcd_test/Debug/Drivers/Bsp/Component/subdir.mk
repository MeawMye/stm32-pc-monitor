################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Bsp/Component/otm8009a.c 

OBJS += \
./Drivers/Bsp/Component/otm8009a.o 

C_DEPS += \
./Drivers/Bsp/Component/otm8009a.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Bsp/Component/%.o Drivers/Bsp/Component/%.su Drivers/Bsp/Component/%.cyclo: ../Drivers/Bsp/Component/%.c Drivers/Bsp/Component/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp/Component" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Utilities" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/STM32F7xx_HAL_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Bsp-2f-Component

clean-Drivers-2f-Bsp-2f-Component:
	-$(RM) ./Drivers/Bsp/Component/otm8009a.cyclo ./Drivers/Bsp/Component/otm8009a.d ./Drivers/Bsp/Component/otm8009a.o ./Drivers/Bsp/Component/otm8009a.su

.PHONY: clean-Drivers-2f-Bsp-2f-Component

