/********************************************************************************
* File ​Name 	  : cmu.c
* Author		  : Rohith Sali
* Date			  : 21/9/2017

********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include <cmu.h>

int ON_period, TOTAL_period, Prescaler, CurrentFrequency;

void cmu_init(void)
{
	/*Set the band for HFRCO*/
	CMU_HFRCOBandSet(cmuHFRCOFreq_19M0Hz);
	/*Disable autostart for HFXO*/
	CMU_HFXOAutostartEnable(0, false, false);
	/*Enable HFRCO*/
	CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);

	CMU_AUXHFRCOBandSet(cmuAUXHFRCOFreq_1M0Hz);
	CMU_OscillatorEnable(cmuOsc_AUXHFRCO, true, true); //Enable AUXHFRCO
	CMU_ClockEnable(cmuClock_ADC0, true); //Enable ADC0 clock
	CMU->ADCCTRL = CMU_ADCCTRL_ADC0CLKSEL_AUXHFRCO;


	CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFRCO); //select HFRCO Clock
	/*disable HFXO, as HFRCO on*/
	CMU_OscillatorEnable(cmuOsc_HFXO, false, false);

#ifdef EMTHREE

	/*enable ULFRCO for EM3*/
	CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);

#else

	/*enable LFXO in EM0, EM1, EM2*/
	CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_LFXO);

#endif

	/*clock peripherals*/
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_LETIMER0, true);
	CMU_ClockEnable(cmuClock_HFLE,true);

	/*current frequency*/
	CurrentFrequency = CMU_ClockFreqGet(cmuClock_LFA);
	ON_period = CurrentFrequency * ON_TIME;
	TOTAL_period = CurrentFrequency * TOTAL_TIME;
	/*Determine the correct prescaler value*/
	while(TOTAL_period > LETIMER0_MAX_VAL)
	{
		Prescaler++;
		TOTAL_period /= 2;
		ON_period /= 2;
	}
	Prescaler++;
	/*Prescale the clock based on the frequency*/
	CMU_ClockDivSet(cmuClock_LETIMER0,Prescaler);
}

