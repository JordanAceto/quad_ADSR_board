/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   GPIO.h provides the interface for initializing the GPIO pins.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    GPIO_Init

Function Description:
    Perform initialization of the GPIO pins.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using any of the GPIO pins.
------------------------------------------------------------------------------*/
void GPIO_Init(void);

#endif
