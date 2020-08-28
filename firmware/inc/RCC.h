/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   RCC.h provides the interface for initializing the Reset and Clock
--|   Control registers.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   stm32f405 reference manual, page 150
--|
--|----------------------------------------------------------------------------|
*/

#ifndef RCC_H_INCLUDED
#define RCC_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    RCC_Init

Function Description:
    Perform initialization of the Reset and Clock Control registers. Sets the 
    system clock to use the external 8MHz crystal oscillator, multiplied by
    the PLL to reach a final clock frequency of 84MHz.

    AHB: 84MHz
    APB1: 42MHz
    APB2: 84MHz

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before branching to the main application.
------------------------------------------------------------------------------*/
void RCC_Init(void);

#endif