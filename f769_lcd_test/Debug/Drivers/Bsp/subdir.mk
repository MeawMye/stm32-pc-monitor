################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Bsp/nt35510.c \
../Drivers/Bsp/otm8009a.c \
../Drivers/Bsp/stm32f769i_discovery.c \
../Drivers/Bsp/stm32f769i_discovery_lcd.c \
../Drivers/Bsp/stm32f769i_discovery_sdram.c 

OBJS += \
./Drivers/Bsp/nt35510.o \
./Drivers/Bsp/otm8009a.o \
./Drivers/Bsp/stm32f769i_discovery.o \
./Drivers/Bsp/stm32f769i_discovery_lcd.o \
./Drivers/Bsp/stm32f769i_discovery_sdram.o 

C_DEPS += \
./Drivers/Bsp/nt35510.d \
./Drivers/Bsp/otm8009a.d \
./Drivers/Bsp/stm32f769i_discovery.d \
./Drivers/Bsp/stm32f769i_discovery_lcd.d \
./Drivers/Bsp/stm32f769i_discovery_sdram.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Bsp/%.o Drivers/Bsp/%.su Drivers/Bsp/%.cyclo: ../Drivers/Bsp/%.c Drivers/Bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp/Component" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Utilities" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/STM32F7xx_HAL_Driver" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/STM32F7xx_HAL_Driver/Src" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Bsp

clean-Drivers-2f-Bsp:
	-$(RM) ./Drivers/Bsp/nt35510.cyclo ./Drivers/Bsp/nt35510.d ./Drivers/Bsp/nt35510.o ./Drivers/Bsp/nt35510.su ./Drivers/Bsp/otm8009a.cyclo ./Drivers/Bsp/otm8009a.d ./Drivers/Bsp/otm8009a.o ./Drivers/Bsp/otm8009a.su ./Drivers/Bsp/stm32f769i_discovery.cyclo ./Drivers/Bsp/stm32f769i_discovery.d ./Drivers/Bsp/stm32f769i_discovery.o ./Drivers/Bsp/stm32f769i_discovery.su ./Drivers/Bsp/stm32f769i_discovery_lcd.cyclo ./Drivers/Bsp/stm32f769i_discovery_lcd.d ./Drivers/Bsp/stm32f769i_discovery_lcd.o ./Drivers/Bsp/stm32f769i_discovery_lcd.su ./Drivers/Bsp/stm32f769i_discovery_sdram.cyclo ./Drivers/Bsp/stm32f769i_discovery_sdram.d ./Drivers/Bsp/stm32f769i_discovery_sdram.o ./Drivers/Bsp/stm32f769i_discovery_sdram.su

.PHONY: clean-Drivers-2f-Bsp

