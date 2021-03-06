
/*Include guard */
#ifndef GPIO_H_
#define GPIO_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include "../inc/main.h"
#include "em_gpio.h"


// LED0 pin
#define	LED0_port gpioPortF
#define LED0_pin (4)
#define LED0_default	false 	// off

// LED0 pin
#define	LED1_port gpioPortF
#define LED1_pin (5)
#define LED1_default	false 	// off

// ADC pin
#define	ADC0_port gpioPortA
#define ADC0_pin (0)
#define ADC0_default	false 	// off

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Description : Initializes GPIO pins
************************************************************************************/
void gpio_init(void);


#endif
