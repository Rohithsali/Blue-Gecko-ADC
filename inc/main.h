
/*Include guard */
#ifndef MAIN_H_
#define MAIN_H_

//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "em_core.h"
extern int ON_period, TOTAL_period, Prescaler, CurrentFrequency;

/*Define the desired energy mode here*/
#define EMTHREE
/*Define the ON time here*/
#define ON_TIME (0.2)
/*Define the TOTAL time here*/
#define TOTAL_TIME (3)
/*Define the maximum count for the 16 bit LETIMER0*/
#define LETIMER0_MAX_VAL (65536)

typedef enum {
    EM0 = 0,
    EM1 = 1,
    EM2 = 2,
    EM3 = 3,
    EM4 = 4
} sleepstate_enum_1;

typedef enum
{
	OFF = 0,
	ON = 1
} led_status;



#endif
