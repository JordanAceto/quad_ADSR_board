/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   bicolor_LED.h provides an interface for the bicolor LED array used to
--|   display the active ADSR.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   WP115WEGW_bicolor_LED datasheet
--|
--|----------------------------------------------------------------------------|
*/

#ifndef BICOLOR_LED_H_INCLUDED
#define BICOLOR_LED_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdint.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: NUM_BICOLOR_LEDS
--| DESCRIPTION: the number of bi-color LEDs
--| TYPE: uint
*/
#define NUM_BICOLOR_LEDS (4u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    bicolor_LED_show_active_ADSR

Function Description:
    Update the bi-color LEDs to show the active adsr

Parameters:
    active_adsr: the active adsr.
    is_master: boolean signal indicating if the active adsr is acting as master

Returns:
    None.

Assumptions/Limitations:
    Assumes that the active adsr is in the range [0, 3]

    Assumes that all system initialization is complete.
------------------------------------------------------------------------------*/
void bicolor_LED_show_active_ADSR(uint32_t active_adsr, uint32_t is_master);

#endif
