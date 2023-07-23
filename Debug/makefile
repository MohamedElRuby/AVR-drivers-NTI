################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include COTS/MCAL/subdir.mk
-include COTS/APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
NTIII.lss \

FLASH_IMAGE += \
NTIII.hex \

EEPROM_IMAGE += \
NTIII.eep \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: NTIII.elf secondary-outputs

# Tool invocations
NTIII.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,NTIII.map -mmcu=atmega32 -o "NTIII.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

NTIII.lss: NTIII.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S NTIII.elf  >"NTIII.lss"
	@echo 'Finished building: $@'
	@echo ' '

NTIII.hex: NTIII.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex NTIII.elf  "NTIII.hex"
	@echo 'Finished building: $@'
	@echo ' '

NTIII.eep: NTIII.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex NTIII.elf  "NTIII.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: NTIII.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 NTIII.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: NTIII.elf
	@echo 'Invoking: AVRDude'
	C:\Users\hp\Desktop\NTI\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:NTIII.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) NTIII.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
