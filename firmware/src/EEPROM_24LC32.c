/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   EEPROIM_24LC32.c provides the implementation for using the EEPROM
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|     stm32f405 reference manual, page 839
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "global_data.h"
#include "I2C2.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void EEPROM_24LC32_write(uint16_t mem_addr, uint8_t* in_buff, uint16_t num_bytes)
{
    I2C2_memory_write(EEPROM_DEVICE_ADDRESS, mem_addr, in_buff, num_bytes);
}

void EEPROM_24LC32_read(uint16_t mem_addr, uint8_t* out_buff, uint16_t num_bytes)
{
    I2C2_memory_read(EEPROM_DEVICE_ADDRESS, mem_addr, out_buff, num_bytes);
}
