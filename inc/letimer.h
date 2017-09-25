
/*Include guard */
#ifndef LETIMER_H_
#define LETIMER_H_

#include "em_letimer.h"
#include "main.h"
#include "em_cmu.h"
#include "ADC.h"

extern int ON_period, TOTAL_period, Prescaler, CurrentFrequency;


void le_timer_init(uint32_t ON_timeperiod, uint32_t TOTAL_timeperiod);


void LED_ON() __attribute__((always_inline));

void LED_OFF() __attribute__((always_inline));


#endif /* INC_LETIMER_H_ */
