/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   I2C2.h provides the interface for initializing and using I2C2.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|     stm32f405 reference manual, page 839
--|----------------------------------------------------------------------------|
*/

#ifndef I2C2_H_INCLUDED
#define I2C2_H_INCLUDED

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
    I2C2_Init

Function Description:
    Perform initialization of I2C2.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using I2C2.
------------------------------------------------------------------------------*/
void I2C2_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    I2C2_memory_write

Function Description:
    Write a number of bytes via I2C2

Parameters:
    device_addr: the address of the device to write to
    mem_addr: the memory address on the device to write to
    in_buff: the buffer containing the data to write out via I2C2
    num_bytes: the number of bytes of in_buff to write

Returns:
    None

Assumptions/Limitations:
    Assumed that I2C2 has been initialized, device_addr is the address of an 
    I2C device attached to the system, mem_addr is a valid memory address
    for the given device, and in_buff has at least num_bytes elements.
------------------------------------------------------------------------------*/
void I2C2_memory_write(uint16_t device_addr, uint16_t mem_addr, uint8_t* in_buff, uint16_t num_bytes);

/*------------------------------------------------------------------------------
Function Name:
    I2C2_memory_read

Function Description:
    Read a number of bytes via I2C2

Parameters:
    device_addr: the address of the device to read from
    mem_addr: the memory address on the device to read from
    out_buff: the buffer to fill with data read from I2C2
    num_bytes: the number of bytes to read into out_buff

Returns:
    mutates output parameter out_buff

Assumptions/Limitations:
    Assumed that I2C2 has been initialized, device_addr is the address of an 
    I2C device attached to the system, mem_addr is a valid memory address
    for the given device, and out_buff has at least num_bytes elements.
------------------------------------------------------------------------------*/
void I2C2_memory_read(uint16_t device_addr, uint16_t mem_addr, uint8_t* out_buff, uint16_t num_bytes);

#endif
