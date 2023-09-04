################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../COTS/MCAL/ADC.c \
../COTS/MCAL/DIO_program.c \
../COTS/MCAL/EXTI0_program.c \
../COTS/MCAL/GIE_program.c \
../COTS/MCAL/I2C_program.c \
../COTS/MCAL/Tim1_program.c \
../COTS/MCAL/Timer_prog.c \
../COTS/MCAL/spi_prog.c \
../COTS/MCAL/uart_prog.c 

OBJS += \
./COTS/MCAL/ADC.o \
./COTS/MCAL/DIO_program.o \
./COTS/MCAL/EXTI0_program.o \
./COTS/MCAL/GIE_program.o \
./COTS/MCAL/I2C_program.o \
./COTS/MCAL/Tim1_program.o \
./COTS/MCAL/Timer_prog.o \
./COTS/MCAL/spi_prog.o \
./COTS/MCAL/uart_prog.o 

C_DEPS += \
./COTS/MCAL/ADC.d \
./COTS/MCAL/DIO_program.d \
./COTS/MCAL/EXTI0_program.d \
./COTS/MCAL/GIE_program.d \
./COTS/MCAL/I2C_program.d \
./COTS/MCAL/Tim1_program.d \
./COTS/MCAL/Timer_prog.d \
./COTS/MCAL/spi_prog.d \
./COTS/MCAL/uart_prog.d 


# Each subdirectory must supply rules for building sources it contributes
COTS/MCAL/%.o: ../COTS/MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\Libary" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\MCAL" -I"C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\NTIII\COTS\HAL" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


