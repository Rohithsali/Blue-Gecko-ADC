

//***********************************************************************************
// Include files
//***********************************************************************************
#include "gpio.h"
#include "main.h"

//***********************************************************************************
// functions
//***********************************************************************************

void gpio_init(void)
{
	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, LED0_default);

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, LED1_default);

	GPIO_PinModeSet(ADC0_port, ADC0_pin, gpioModeDisabled, ADC0_default);
	/*Over voltage disable for analog pin PortA pin 0*/
	GPIO->P[gpioPortA].OVTDIS = 0x0001;
}


