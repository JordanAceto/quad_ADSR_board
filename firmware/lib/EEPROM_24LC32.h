/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   EEPROM_24LC32.h provides the interface for using the EEPROM.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef EEPROM_24LC32_H_INCLUDED
#define EEPROM_24LC32_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdint.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    EEPROM_24LC32_write

Function Description:
    Write a number of bytes to the EEPROM

Parameters:
    mem_addr: the memory address to write to
    in_buff: the buffer containing the data to write to the EEPROM
    num_bytes: the number of bytes of in_buff to write

Returns:
    None

Assumptions/Limitations:
    Assumed that I2C2 has been initialized, mem_addr is a valid memory address
    for the given device, and in_buff has at least num_bytes elements.
------------------------------------------------------------------------------*/
void EEPROM_24LC32_write(uint16_t mem_addr, uint8_t* in_buff, uint16_t num_bytes);

/*------------------------------------------------------------------------------
Function Name:
    EEPROM_24LC32_read

Function Description:
    Read a number of bytes from the EEPROM

Parameters:
    mem_addr: the memory address on the device to read from
    out_buff: the buffer to fill with data read from the EEPROM
    num_bytes: the number of bytes to read into out_buff

Returns:
    mutates output parameter out_buff

Assumptions/Limitations:
    Assumed that I2C2 has been initialized, mem_addr is a valid memory address
    for the given device, and out_buff has at least num_bytes elements.
------------------------------------------------------------------------------*/
void EEPROM_24LC32_read(uint16_t mem_addr, uint8_t* out_buff, uint16_t num_bytes);

/*------------------------------------------------------------------------------
Function Name:
    test_EEPROM

Function Description:
    Perform a test of the EEPROM by writing some data, then reading the same 
    data back and checking to see if they match.

    If the data does match, blink the onboard LED rapidly for a few seconds.

    If the data does not match, blink the onboard LED slowly for a few seconds.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that I2C2 has been initialized.
------------------------------------------------------------------------------*/
void test_EEPROM(void);

#endif
