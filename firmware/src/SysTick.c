/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   SysTick.h provides the implementation for SysTick related functions,
--|   and implements the SysTick_handler interrupt routine.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   PM0214 programmers manual page 246
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f4xx.h"
#include "SysTick.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE TYPES
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE CONSTANTS
--|----------------------------------------------------------------------------|
*/

/* None */

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: mSec_since_reset 
--| DESCRIPTION: the number of milliseconds since the last power on/reset.
--| TYPE: uint32_t
*/
static volatile uint32_t mSec_since_reset = 0u;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Handler

Function Description:
    Interrupt routine for periodic Systick interrupts. Simply increments the
    mSec_since_reset variable.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Called automatically, do not call this function.
------------------------------------------------------------------------------*/
void SysTick_Handler(void);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SysTick_Init(void)
{
    // set the load register such that the SysTick fires at 1kHz
    SysTick->LOAD = (SystemCoreClock / 1000u) - 1u;

    // reset the SysTick current value
    SysTick->VAL = 0u;

    // set the clocksource to the undivided processor clock (AHB)
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

    // enable exception requests
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

    // enable the SysTick timer
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Delay_mSec(uint32_t mSec)
{
    const uint32_t start_time = SysTick_Get_mSec();

    while ((SysTick_Get_mSec() - start_time) <= mSec)
    {
        // wait
    }
}

uint32_t SysTick_Get_mSec(void)
{
    return mSec_since_reset;
}

void SysTick_Start_Timeout_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    p_timer->timeout_start_mSec = SysTick_Get_mSec();
}

bool SysTick_Poll_One_Shot_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    return (SysTick_Get_mSec() - p_timer->timeout_start_mSec) >= p_timer->timeout_period_mSec;
}

bool SysTick_Poll_Periodic_Timer(SysTick_Timeout_Timer_t * p_timer)
{
    bool timeout_occured = SysTick_Poll_One_Shot_Timer(p_timer);

    if (timeout_occured) 
    {
        // reset the timer
        p_timer->timeout_start_mSec = SysTick_Get_mSec();
    }

    return timeout_occured;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SysTick_Handler(void)
{
    mSec_since_reset++;
}