################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../kit_flashpwr/BRD4302A/mx25flash_spi.c 

OBJS += \
./kit_flashpwr/BRD4302A/mx25flash_spi.o 

C_DEPS += \
./kit_flashpwr/BRD4302A/mx25flash_spi.d 


# Each subdirectory must supply rules for building sources it contributes
kit_flashpwr/BRD4302A/mx25flash_spi.o: ../kit_flashpwr/BRD4302A/mx25flash_spi.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DSILABS_AF_USE_HWCONF=1' '-D__NO_SYSTEM_INIT=1' '-DEFR32BG1B232F256GM56=1' -I"D:\CU Boulder\3rd Sem\IoT\assignment2.1\LED_Blinking_Rohith_ADC0\inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//protocol/bluetooth_2.4/ble_stack/inc/common" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//protocol/bluetooth_2.4/ble_stack/inc/soc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/bootloader/api" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/dmadrv/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emlib/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/CMSIS/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/Device/SiliconLabs/EFR32BG1B/Include" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/common/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/dmadrv/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/gpiointerrupt/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/nvm/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/nvm/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/rtcdrv/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/rtcdrv/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/sleep/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/spidrv/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/spidrv/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/tempdrv/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/tempdrv/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/uartdrv/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/uartdrv/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/ustimer/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/emdrv/ustimer/inc" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/EFR32BG1_BRD4302A/config" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/bsp" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//hardware/kit/common/drivers" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/radio/rail_lib/chip/efr32/rf/common/cortex" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/radio/rail_lib/common" -I"D:/SiliconLabs/SimplicityStudio/v4/developer/sdks/gecko_sdk_suite/v1.1//platform/radio/rail_lib/chip/efr32" -I"D:\CU Boulder\3rd Sem\IoT\assignment2.1\LED_Blinking_Rohith_ADC0\src" -I"D:\CU Boulder\3rd Sem\IoT\assignment2.1\LED_Blinking_Rohith_ADC0" -O0 -fno-short-enums -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=hard -MMD -MP -MF"kit_flashpwr/BRD4302A/mx25flash_spi.d" -MT"kit_flashpwr/BRD4302A/mx25flash_spi.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


