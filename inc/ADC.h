
#ifndef INC_ADC_H_
#define INC_ADC_H_


extern int ON_period, TOTAL_period, Prescaler, CurrentFrequency;


#include "em_adc.h"
#include "em_core.h"
#include "gpio.h"
#include "sleep.h"

#define ON_TIME_CHANGE 0.5
#define ON_TIME_LIMIT 2.8
#define ON_TIME_MIN 0.2
#define UP_MAX 3600
#define UP_MIN 3400
#define DOWN_MAX 2100
#define DOWN_MIN 1900
#define RIGHT_MAX 3200
#define RIGHT_MIN 2950
#define LEFT_MAX 2600
#define LEFT_MIN 2300
#define RESET_MAX 100
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define RESET 4
#define ADGT    20
#define ADLT	3700

void ADC_SYNC_To_ASYNC();

void ADC_ASYNC_To_SYNC();

void ADC_Setup();



#endif /* INC_ADC_H_ */
