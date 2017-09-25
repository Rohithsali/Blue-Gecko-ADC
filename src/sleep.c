/******************************************************************************
 * @section License
 * <b>(C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ******************************************************************************
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *****************************************************************************/


#include "main.h"
#include "em_emu.h"
#include "sleep.h"


extern int sleep_block_counter[5];

/* *************************************************************************
 * Function is Sleep routine to enter different energy modes
 * *************************************************************************
 */
void sleep(void) {
if (sleep_block_counter[0] > 0)
{
	return; // Blocked below EM0, so just return
}
else if (sleep_block_counter[1] > 0)
{
	EMU_EnterEM1(); // enter EM1
}
else if (sleep_block_counter[2] > 0)
{
	EMU_EnterEM2(true); // enter EM2
}
else if (sleep_block_counter[3] > 0)
{
	EMU_EnterEM3(true); //  enter EM3
}
else
{
	EMU_EnterEM3(true); // enter EM4
}
return;
}


/**************************************************************************//**
* @brief Block Sleep Mode Routine– to increment the sleep_block_counter for appropriate energy mode
* code used from the lecture notes of Prof.Keith Graham
*****************************************************************************/
void blockSleepMode(sleepstate_enum minimumMode)
{
/*Disable interrupts*/
CORE_ATOMIC_IRQ_DISABLE();
sleep_block_counter[minimumMode]++;
/*enable interrupts*/
CORE_ATOMIC_IRQ_ENABLE();
}

/**************************************************************************//**
* @brief UnBlock Sleep Mode Routine – to decrement the sleep_block_counter for appropriate energy mode
* code used from the lecture notes of Prof.Keith Graham
*****************************************************************************/
void unblockSleepMode(sleepstate_enum minimumMode)
{
CORE_ATOMIC_IRQ_DISABLE();
if(sleep_block_counter[minimumMode] > 0)
{
	sleep_block_counter[minimumMode]--;
}
CORE_ATOMIC_IRQ_ENABLE();
}
