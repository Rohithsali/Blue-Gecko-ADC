/*
 * ADC.c
 * Created on: 21/9/2017
 *      Author: Rohith Sali
 */
#include "adc.h"
#include "letimer.h"


int comp1,Prev_dir;
float ontime = 0.2;
extern int Prev_dir;


/***************************************************
 * Interrupt IRQ handler for LETIMER0
 * Handles joy-stick movement.
 * Turns the led1 on when pushed NORTH
 * Turns the led1 off when pushed SOUTH
 * Increments the on time of led0 when pushed EAST by 500ms
 *Decrements the on time of led0 when pushed WEST by 500ms
 *When the joy-stick is depressed it resets to 200ms on-time
 * *************************************************/
void ADC0_IRQHandler(void)
{
	int intFlags;
	int ADC_data;

	// Disable interrupts
	CORE_ATOMIC_IRQ_DISABLE();

	// Read interrupt flags
	intFlags = ADC_IntGet(ADC0);

	// Read the value sampled by the ADC
	 ADC_data = ADC_DataSingleGet(ADC0);

	// Clear ADC buffer
	ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;

	// clear interrupt flags
	ADC_IntClear(ADC0, intFlags);

	if(intFlags & ADC_IF_SINGLECMP)
	{
		if (Prev_dir != NORTH)
		{
			//Joy stick pushed towards north
			if ((ADC_data > UP_MIN) && (ADC_data < UP_MAX))
			{
				GPIO_PinOutSet(LED1_port, LED1_pin);
			}
		}
		//Joy stick pushed towards south
		if (Prev_dir != SOUTH)
		{
			if (ADC_data > DOWN_MIN && ADC_data < DOWN_MAX)
			{

				GPIO_PinOutClear(LED1_port, LED1_pin);
			}
		}

		if (Prev_dir != WEST)
					{
			//Joy stick pushed towards west
		 if (ADC_data > LEFT_MIN && ADC_data < LEFT_MAX)
		{
			 	 //decrease on-time by 500ms
				ontime = ontime - ON_TIME_CHANGE;

				// on-time not less than 200ms
				if (ontime <= ON_TIME_MIN)
				{
					ontime = ON_TIME_MIN;
				}

				// change registers in LETIMER0
				CurrentFrequency = CMU_ClockFreqGet(cmuClock_LFA);
				comp1 = CurrentFrequency * (ontime);
				LETIMER_CompareSet(LETIMER0, 1, comp1);
				Prev_dir = WEST;
			}
		}

		if (Prev_dir != EAST)
		{
		// Joy stick pushed towards east
			if(ADC_data > RIGHT_MIN && ADC_data < RIGHT_MAX)
			{
				 //increase on-time by 500ms

				ontime = ontime + ON_TIME_CHANGE;

				// on-time not greater than 3s
				if (ontime >= ON_TIME_LIMIT)
				{
					ontime = ON_TIME_LIMIT;
				}

				// change appropriate registers in LETIMER0 to accommodate the change in on time
				CurrentFrequency = CMU_ClockFreqGet(cmuClock_LFA);
				comp1 = CurrentFrequency * (ontime);
				LETIMER_CompareSet(LETIMER0, 1, comp1);
				Prev_dir = EAST;
			}
		}

		// Joystick depressed
			if (ADC_data < RESET_MAX)
			{
				ontime = ON_TIME_MIN;

			// change appropriate registers in LETIMER0 to accommodate the change in on time
				CurrentFrequency = CMU_ClockFreqGet(cmuClock_LFA);
				comp1 = CurrentFrequency * (ontime);
				LETIMER_CompareSet(LETIMER0, 1, comp1);
				Prev_dir = RESET;
			}
		}


	CORE_ATOMIC_IRQ_ENABLE();
}

/******************************************************************
 * change ADC from synchronous to asynchronous mode
 *******************************************************************/
void ADC_SYNC_To_ASYNC()
{
		NVIC_DisableIRQ(ADC0_IRQn);
		ADC_IntDisable(ADC0, ADC_IFC_PROGERR | ADC_IFC_VREFOV | ADC_IFC_SCANCMP | ADC_IFC_SINGLECMP | ADC_IFC_SCANUF | ADC_IFC_SINGLEUF | ADC_IFC_SCANOF | ADC_IFC_SINGLEOF);
		/*Clear the FIFOs*/
		ADC0->SCANFIFOCLEAR = ADC_SCANFIFOCLEAR_SCANFIFOCLEAR;
		ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;
		ADC0->CTRL |= ADC_CTRL_ADCCLKMODE_ASYNC;

}
/******************************************************************
 * change ADC from Asynchronous to synchronous mode
 *******************************************************************/
//void ADC_ASYNC_To_SYNC()
//{
//		NVIC_DisableIRQ(ADC0_IRQn);
//		ADC_IntDisable(ADC0, ADC_IFC_PROGERR | ADC_IFC_VREFOV | ADC_IFC_SCANCMP | ADC_IFC_SINGLECMP | ADC_IFC_SCANUF | ADC_IFC_SINGLEUF | ADC_IFC_SCANOF | ADC_IFC_SINGLEOF);
//		/*Clear the FIFOs*/
//		ADC0->CTRL &= ~ADC_CTRL_ADCCLKMODE_ASYNC;
//		ADC0->SCANFIFOCLEAR = ADC_SCANFIFOCLEAR_SCANFIFOCLEAR;
//		ADC0->SINGLEFIFOCLEAR = ADC_SINGLEFIFOCLEAR_SINGLEFIFOCLEAR;
//
//}

void ADC_Setup()
{
	ADC_Init_TypeDef Init =
	{
			.ovsRateSel = adcOvsRateSel2,
			.prescale = _ADC_CTRL_PRESC_DEFAULT,
			.warmUpMode = adcWarmupNormal,
			.timebase = ADC_TimebaseCalc(0),
			.tailgate = false,
			.em2ClockConfig = adcEm2ClockAlwaysOn
	};

	ADC_InitSingle_TypeDef singleInit =
	{
			.acqTime = adcAcqTime32,
			.reference = adcRefVDD,
			.resolution = adcRes12Bit,
			.posSel = adcPosSelAPORT3XCH8,
			.negSel=adcNegSelVSS,
			.diff = false,
			.prsEnable = false,
			.leftAdjust = false ,
			.rep = true,
			.singleDmaEm2Wu = false,
			.fifoOverwrite = true
	};

	ADC_Init(ADC0, &Init);
	ADC_InitSingle(ADC0, &singleInit);
	ADC0->SCANCTRL |= _ADC_SCANCTRL_REF_VDD;
	ADC0->SCANCTRLX |= _ADC_SCANCTRLX_VREFSEL_VDDXWATT;
	ADC0->CMPTHR = _ADC_CMPTHR_RESETVALUE;
	ADC0->CMPTHR = (ADGT << _ADC_CMPTHR_ADGT_SHIFT) + (ADLT << _ADC_CMPTHR_ADLT_SHIFT);

	ADC0->SINGLECTRL |=  ADC_SINGLECTRL_CMPEN;
	ADC_SYNC_To_ASYNC();
	ADC_IntClear(ADC0, ADC_IFC_PROGERR | ADC_IFC_VREFOV | ADC_IFC_SCANCMP | ADC_IFC_SINGLECMP | ADC_IFC_SCANUF | ADC_IFC_SINGLEUF | ADC_IFC_SCANOF | ADC_IFC_SINGLEOF);
	ADC_IntEnable(ADC0, ADC_IEN_SINGLECMP );
	blockSleepMode(EM3);
	CORE_ATOMIC_IRQ_ENABLE();
	NVIC_EnableIRQ(ADC0_IRQn);

	ADC_Start(ADC0, adcStartSingle);
}
