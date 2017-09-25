/********************************************************************************
* File ​Name 	  : letimer.c
* File Description: This file has the initialization & interrupt handler of LETIMER0
* Author		  : Rohith Sali
* Date			  : 21/9/2017
********************************************************************************/

#include "letimer.h"
#include "sleep.h"
#include "gpio.h"

extern int Prev_dir;

const LETIMER_Init_TypeDef letimerInit =
{
		.enable         = false,                //Start counting
		.debugRun       = false,                //Counter will not run during debug halt
		.comp0Top       = true,                 //Load COMP0 register into CNT when counter underflows. COMP0 is used as TOP
		.bufTop         = false,                //Don't load COMP1 into COMP0 when REP0 reaches 0
		.out0Pol        = 0,                    //Idle value for output 0.
		.out1Pol        = 0,                    //Idle value for output 1.
		.ufoa0          = letimerUFOANone,      //PWM output on output 0
		.ufoa1          = letimerUFOANone,      //Pulse output on output 1
		.repMode        = letimerRepeatFree     //Count until stopped
};

void LETIMER0_IRQHandler(void)
{
	int intFlags;

	// Disable interrupts a
	CORE_ATOMIC_IRQ_DISABLE();

	// Read the interrupt flags
	intFlags = LETIMER_IntGet(LETIMER0);


	LETIMER_IntClear(LETIMER0, intFlags);   //Clear the interrupt flags
	Prev_dir = RESET;
	if(intFlags & LETIMER_IF_COMP1)
	{
		GPIO_PinOutSet(LED0_port, LED0_pin);
	}
	else if(intFlags & LETIMER_IF_UF)
	{
		GPIO_PinOutClear(LED0_port, LED0_pin);
	}
	CORE_ATOMIC_IRQ_ENABLE();                         //Re-enable interrupts
}


void le_timer_init(uint32_t ON_timeperiod, uint32_t TOTAL_timeperiod)
{
	LETIMER_Init(LETIMER0, &letimerInit);


	LETIMER_CompareSet(LETIMER0, 0, TOTAL_timeperiod);
	LETIMER_CompareSet(LETIMER0, 1, ON_timeperiod);

	while(LETIMER0->SYNCBUSY);

	LETIMER_IntClear(LETIMER0, LETIMER_IFC_UF | LETIMER_IFC_COMP0 | LETIMER_IFC_COMP1); //clear interruputs for UF, COMP0, COMP1
	LETIMER_IntEnable(LETIMER0 , LETIMER_IEN_COMP1 | LETIMER_IEN_UF);
	NVIC_EnableIRQ(LETIMER0_IRQn);

	/* Start LETIMER0*/
	LETIMER0->CMD = LETIMER_CMD_START;

#ifdef EMZERO
		blockSleepMode(energy_mode_0);
#endif
#ifdef EMONE
		blockSleepMode(energy_mode_1);
#endif
#ifdef EMTWO
		blockSleepMode(energy_mode_2);
#endif
#ifdef EMTHREE
		blockSleepMode(energy_mode_3);
#endif

}
