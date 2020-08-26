/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   MCP4822.h provides types and functions for interfacing with MCP4822
--|   12-bit SPI DACs.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   mcp4822_datasheet.pdf
--|
--|----------------------------------------------------------------------------|
*/

#ifndef MCP4822_H_INCLUDED
#define MCP4822_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "SPI3.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: MCP4822_Channel_enum
--| DESCRIPTION: enumeration for MCP4822 channel
*/
typedef enum MCP4822_Channel_Enumeration
{
    MCP4822_CHANNEL_A = 0u,
    MCP4822_CHANNEL_B = 1u
} MCP4822_Channel_enum;

/*
--| NAME: MCP4822_Gain_enum
--| DESCRIPTION: enumeration for MCP4822 gain
*/
typedef enum MCP4822_Gain_Enumeration
{
    MCP4822_GAIN_2x = 0u,
    MCP4822_GAIN_1x = 1u
} MCP4822_Gain_enum;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    MCP4822_Write

Function Description:
    Write the given 12 bit signal to a MCP4822 DAC via SPI.

Parameters:
    CS_port: pointer to the port for the chip select pin
    CS_pin: the pin number for the chip select pin
    channel: the MCP4822 channel to write to, A or B
    gain: the gain to use, 1x or 2x (2x will cause clipping in a 3.3v system)
    value_12_bits: the 12 bit value to write (bits higher than 12 are discarded)

Returns:
    None

Assumptions/Limitations:
    Assumes that all system initialization is complete.
------------------------------------------------------------------------------*/
void MCP4822_Write(GPIO_TypeDef *        CS_port,
                   uint16_t              CS_pin,
                   MCP4822_Channel_enum  channel,
                   MCP4822_Gain_enum     gain,
                   uint32_t              value_12_bits);

#endif
