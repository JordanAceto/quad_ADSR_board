/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   bicolor_LED.h provides the implementation for the bi-color LED array.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   WP115WEGW_bicolor_LED datasheet
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "GPIO.h"
#include "SPI3.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void bicolor_LED_show_active_ADSR(uint32_t active_adsr, uint32_t is_master)
{
    // set the red LED high if we're in master mode, else green
    const uint8_t bit_pattern_to_write = is_master ? 1u << (6u - (active_adsr << 1)) : 2u << (6u - (active_adsr << 1u));

    SPI3_Transmit(SPI3_RG_LEDS_CS_GPIO_Port, SPI3_RG_LEDS_CS_Pin, bit_pattern_to_write);
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

/* None */
