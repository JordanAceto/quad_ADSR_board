/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   SPI3.h provides the interface for initializing and using SPI3.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef SPI3_H_INCLUDED
#define SPI3_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    SPI3_Init

Function Description:
    Perform initialization of SPI3.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using SPI3.
------------------------------------------------------------------------------*/
void SPI3_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    SPI3_Transmit

Function Description:
    Transmit data via SPI3

Parameters:
    CS_port: pointer to the port for the chip select pin
    CS_pin: the pin number for the chip select pin
    value: the value to transmit

Returns:
    None

Assumptions/Limitations:
    Assumed that SPI3 has been initialized.
------------------------------------------------------------------------------*/
void SPI3_Transmit(GPIO_TypeDef * CS_port, uint16_t CS_pin, uint32_t value);

#endif
