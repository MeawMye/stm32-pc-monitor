################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Utilities/font12.c \
../Drivers/Utilities/font16.c \
../Drivers/Utilities/font20.c \
../Drivers/Utilities/font24.c \
../Drivers/Utilities/font8.c 

OBJS += \
./Drivers/Utilities/font12.o \
./Drivers/Utilities/font16.o \
./Drivers/Utilities/font20.o \
./Drivers/Utilities/font24.o \
./Drivers/Utilities/font8.o 

C_DEPS += \
./Drivers/Utilities/font12.d \
./Drivers/Utilities/font16.d \
./Drivers/Utilities/font20.d \
./Drivers/Utilities/font24.d \
./Drivers/Utilities/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Utilities/%.o Drivers/Utilities/%.su Drivers/Utilities/%.cyclo: ../Drivers/Utilities/%.c Drivers/Utilities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp/Component" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Utilities" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers/Bsp" -I"C:/Users/y6484/f429_workspace/f769_lcd_test/Drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Utilities

clean-Drivers-2f-Utilities:
	-$(RM) ./Drivers/Utilities/font12.cyclo ./Drivers/Utilities/font12.d ./Drivers/Utilities/font12.o ./Drivers/Utilities/font12.su ./Drivers/Utilities/font16.cyclo ./Drivers/Utilities/font16.d ./Drivers/Utilities/font16.o ./Drivers/Utilities/font16.su ./Drivers/Utilities/font20.cyclo ./Drivers/Utilities/font20.d ./Drivers/Utilities/font20.o ./Drivers/Utilities/font20.su ./Drivers/Utilities/font24.cyclo ./Drivers/Utilities/font24.d ./Drivers/Utilities/font24.o ./Drivers/Utilities/font24.su ./Drivers/Utilities/font8.cyclo ./Drivers/Utilities/font8.d ./Drivers/Utilities/font8.o ./Drivers/Utilities/font8.su

.PHONY: clean-Drivers-2f-Utilities

