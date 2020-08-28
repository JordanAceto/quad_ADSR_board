/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the interface for the interrupts used by the system.
--|   
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef INTERRUPTS_H_INCLUDED
#define INTERRUPTS_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    interrupts_Init

Function Description:
    Perform initialization of the interrupts used by the system.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called as part of system initialization.
------------------------------------------------------------------------------*/
void interrupts_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    TIM6_DAC_IRQHandler

Function Description:
    IRQ handler for the TIM6 interrupt.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Called automatically, do not call this function.
------------------------------------------------------------------------------*/
void TIM6_DAC_IRQHandler(void);

/*------------------------------------------------------------------------------
Function Name:
    TIM7_IRQHandler

Function Description:
    IRQ handler for the TIM7 interrupt.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Called automatically, do not call this function.
------------------------------------------------------------------------------*/
void TIM7_IRQHandler(void);

#endif
