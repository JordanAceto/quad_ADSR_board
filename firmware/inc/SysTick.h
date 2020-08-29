/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   SysTick.h provides types and interfaces for the Core SysTick Timer,
--|   as well as various scheduling and time based functionality.
--|   
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   PM0214 programmers manual page 246
--|
--|----------------------------------------------------------------------------|
*/

#ifndef SYSTICK_H_INCLUDED
#define SYSTICK_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stdbool.h"
#include "stdint.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: SysTick_Timeout_Timer_t
--| DESCRIPTION: structure for timeout timer storage
*/
typedef struct SysTick_Timeout_Timer_Type
{
    uint32_t timeout_period_mSec; // the period of the timeout in mSec
    uint32_t timeout_start_mSec;  // the time in mSec when the timer was started
} SysTick_Timeout_Timer_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Init

Function Description:
    Initialize the SysTick timer

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void SysTick_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Delay_mSec

Function Description:
    Wait for a given number of milliseconds.

Parameters:
    mSec: the number of milliseconds to wait.

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
void SysTick_Delay_mSec(uint32_t mSec);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Get_mSec

Function Description:
    Get the number of milliseconds since the last power on/reset.

Parameters:
    None

Returns:
    uint32_t: the number of milliseconds since reset.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
uint32_t SysTick_Get_mSec(void);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Start_Timeout_Timer

Function Description:
    Start a timeout timeout timer before using.
    
Parameters:
    p_timer: pointer to the timeout timer.

Returns:
    None

Assumptions/Limitations:
    Assumes that the given timeout timer has a valid timeout period.
------------------------------------------------------------------------------*/
void SysTick_Start_Timeout_Timer(SysTick_Timeout_Timer_t * p_timer);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Poll_One_Shot_Timer

Function Description:
    Poll a given one-shot timeout timer and return true if a timeout has 
    occured, otherwise return false.

Parameters:
    p_timer: pointer to the timeout timer.

Returns:
    true if a timeout occured, else false.

Assumptions/Limitations:
    Assumes that the data in the given timeout timer is sensible.
------------------------------------------------------------------------------*/
bool SysTick_Poll_One_Shot_Timer(SysTick_Timeout_Timer_t * p_timer);

/*------------------------------------------------------------------------------
Function Name:
    SysTick_Poll_Periodic_Timer

Function Description:
    Poll a given periodic timeout timer and return true if a timeout has 
    occured, otherwise return false.

    If a timeout has occured, the last timeout time in the given timeout 
    timer is set to the time now.

Parameters:
    p_timer: pointer to the timeout timer.

Returns:
    true if a timeout occured, else false.

Assumptions/Limitations:
    Assumes that the data in the given timeout timer is sensible.
------------------------------------------------------------------------------*/
bool SysTick_Poll_Periodic_Timer(SysTick_Timeout_Timer_t * p_timer);

#endif