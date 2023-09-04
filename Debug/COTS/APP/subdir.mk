################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/APP/calc.c \
../COTS/APP/main.c 

OBJS += \
./COTS/APP/calc.o \
./COTS/APP/main.o 

C_DEPS += \
./COTS/APP/calc.d \
./COTS/APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/APP/%.o: ../COTS/APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\HAL" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


