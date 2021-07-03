
/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   output_processing.h provides an interface for using various output
--|   processing helper functions.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

#ifndef OUTPUT_PROCESSING_H_INCLUDED
#define OUTPUT_PROCESSING_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    tick_ADSRs

Function Description:
    Tick the four ADSRs.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that this function will be called at the defined sample rate.
------------------------------------------------------------------------------*/
void tick_ADSRs(void);

/*------------------------------------------------------------------------------
Function Name:
    update_seven_segment_display

Function Description:
    Update the seven-segment display to show the value of the active ADSR setting
    for the active encoder.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void update_seven_segment_display(void);

/*------------------------------------------------------------------------------
Function Name:
    update_bicolor_LEDs

Function Description:
    Update the bi-color LED display to show the active ADSR and the ADSR mode.

    The active ADSR is illuminated. If the mode is lock-to-master, the LED is
    red, and if the mode is independent the LED is green.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void update_bicolor_LEDs(void);

/*------------------------------------------------------------------------------
Function Name:
    update_MCP4822_DACs

Function Description:
    Update the MCP4822 SPI DACs with the current values of the ADSRs.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void update_MCP4822_DACs(void);

#endif
