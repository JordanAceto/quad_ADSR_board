/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM6.h provides the interface for initializing TIM6.
--|   
--|   TIM6 sets the sample time for ...
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F4xx Reference Manual, page 696 (Basic Timers)
--|
--|----------------------------------------------------------------------------|
*/

#ifndef TIM6_H_INCLUDED
#define TIM6_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    TIM6_Init

Function Description:
    Perform initialization of TIM6.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using TIM6.
------------------------------------------------------------------------------*/
void TIM6_Init(void);

#endif
