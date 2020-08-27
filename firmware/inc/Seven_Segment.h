/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   Seven_Segment.h provides an interface for using the four digit seven-segment
--|   display with four decimal points used by the system.
--|
--|   The seven-segment display is used to show the value of the most recently
--|   adjusted parameter to the user. 
--|
--|   Time based parameters Attack, Decay, and Release are shown with the units 
--|   being seconds. A moving decimal point is used depending on how long the 
--|   time to be shown is.
--|
--|   The Sustain paramter is shown as a percent between 0.0% and 100.0%. For
--|   Sustain parameters the decimal point is always in the same place.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   hdsp-7503_seven_segment datasheet
--|
--|----------------------------------------------------------------------------|
*/

#ifndef SEVEN_SEGMENT_H_INCLUDED
#define SEVEN_SEGMENT_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: NUM_SEVEN_SEGMENT_DIGITS
--| DESCRIPTION: the number of digits in the seven-segment display
--| TYPE: uint
*/
#define NUM_SEVEN_SEGMENT_DIGITS (4u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    seven_segment_update_ADR_param

Function Description:
    Update the seven-segment display with the given Attack, Decay, or Release
    parameter.

Parameters:
    ADR_param: the Attack, Decay, or Release parameter to display.

Returns:
    None.

Assumptions/Limitations:
    Assumes that the given parameter fits in four digits.

    Assumes that all system initialization is complete.

    Assumes that this function (or the similar seven_segment_update_S_param
    function) will be called periodically at at least 10Hz to avoid flickering.
------------------------------------------------------------------------------*/
void seven_segment_update_ADR_param(uint32_t ADR_param);

/*------------------------------------------------------------------------------
Function Name:
    seven_segment_update_S_param

Function Description:
    Update the seven-segment display with the given Sustain parameter.

Parameters:
    ADR_param: the Sustain parameter to display.

Returns:
    None.

Assumptions/Limitations:
    Assumes that the given parameter fits in four digits.

    Assumes that all system initialization is complete.

    Assumes that this function (or the similar seven_segment_update_ADR_param
    function) will be called periodically at at least 10Hz to avoid flickering.
------------------------------------------------------------------------------*/
void seven_segment_update_S_param(uint32_t S_param);

#endif
