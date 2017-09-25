
/*Include guard */
#ifndef SLEEP_H_
#define SLEEP_H_

typedef enum
{
	energy_mode_0,
	energy_mode_1,
	energy_mode_2,
	energy_mode_3,
	energy_mode_4
} sleepstate_enum;

/************************************************************************************
decides which energy mode to sleep in
************************************************************************************/
void sleep(void);

/************************************************************************************
Blocks the sleep mode to a lowest energy mode
************************************************************************************/
void blockSleepMode(sleepstate_enum minimumMode);

/************************************************************************************
Unblocks the sleep mode
************************************************************************************/
void unblockSleepMode(sleepstate_enum minimumMode);

#endif /* INC_SLEEP_H_ */
