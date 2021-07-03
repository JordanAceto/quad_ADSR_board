/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM7.h provides the interface for initializing TIM6.
--|
--|   TIM7 is configured as a periodic timer that sets the sample time for the
--|   low priority and relatively slow tasks like updating the UI.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F4xx Reference Manual, page 696 (Basic Timers)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef TIM7_H_INCLUDED
#define TIM7_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: TIM6_FREQUENCY_Hz
--| DESCRIPTION: the frequency of timer 6, in Hertz
--| TYPE: uint
*/
#define TIM7_FREQUENCY_Hz (500u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    TIM7_Init

Function Description:
    Perform initialization of TIM7.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using TIM7.
------------------------------------------------------------------------------*/
void TIM7_Init(void);

#endif
