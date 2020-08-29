/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   encoders.h provides an interface for initializing and scaling the four
--|   encoders used by he system.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

#ifndef ENCODERS_H_INCLUDED
#define ENCODERS_H_INCLUDED

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
    encoders_Init

Function Description:
    Initialize the four hardware timers used in encoder mode.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using any of the encoders.
------------------------------------------------------------------------------*/
void encoders_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    encoder_count_to_ADR_param

Function Description:
    Read a hardware timer channel configured for encoder mode and scale the
    reading to map to an ADSR time based input parameter. The time based input
    parameters are Attack, Decay, and Release. After reading, the hardware
    encoder timer is also clamped to low and high bounds.

    The encoder is mapped according to the below table. This mapping makes the
    encoder "feel good" while adjusting time based ADSR parameters. The mapping
    is a piecewise linear exponential function, broken up into intuitive whole
    number ranges that allow for a wide range of time adjustment with a reasonable
    amount of knob turning, and look good on the 7-segment display.

    linear segment 1: 0.001 seconds to 0.050 seconds in   1 mSec steps
    linear segment 2: 0.055 seconds to 1.000 seconds in   5 mSec steps
    linear segment 3: 1.010 seconds to 3.000 seconds in  10 mSec steps
    linear segment 4: 3.050 seconds to 10.00 seconds in  50 mSec steps
    linear segment 5: 10.10 seconds to 30.00 seconds in 100 mSec steps
    linear segment 6: 30.25 seconds to 60.00 seconds in 250 mSec steps

    Note that the units of the return value are milliseconds, so the above table
    represents the range of 1 millisecond to 60000 milliseconds.

Parameters:
    tim_x: pointer to the hardware timer handle to read and clamp.

Returns:
    uint32_t: the scaled value, mapped according to the description.
    units are milliseconds in the range [1, 60000]

Assumptions/Limitations:
    Assumes that the timer handle is configured for encoder mode with internal
    pullup resistors enabled, and configured to count up to 2^16 - 1.
    Configuring the timer as a 16 bit up-counter allows the clamping routine
    to work.
------------------------------------------------------------------------------*/
uint32_t encoder_count_to_ADR_param(TIM_TypeDef * tim_x);

/*------------------------------------------------------------------------------
Function Name:
    encoder_count_to_S_param

Function Description:
    Read a hardware timer channel configured for encoder mode and scale the
    reading to map to an ADSR Sustain level input parameter. After reading, the
    hardware encoder timer is also clamped to low and high bounds.

    The Sustain level is mapped to a 32 bit unsigned integer which represents
    the full scale sustain level from 0% to 100.0%.

    This full scale range is broken into 1000 steps, and represents [percent * 10]

Parameters:
    tim_x: pointer to the hardware timer handle to read and clamp.

Returns:
    uint32_t: the scaled value, mapped according to the description. The value
    is unitless, and represents the sustain percent * 10.

Assumptions/Limitations:
    Assumes that the timer handle is configured for encoder mode with internal
    pullup resistors enabled, and configured to count up to 2^16 - 1.
    Configuring the timer as a 16 bit up-counter allows the clamping routine
    to work.
------------------------------------------------------------------------------*/
uint32_t encoder_count_to_S_param(TIM_TypeDef * tim_x);

/*------------------------------------------------------------------------------
Function Name:
    ADR_param_to_encoder_count

Function Description:
    Inverse function to encoder_count_to_ADR_param. Takes a given Attack, Decay,
    or Release parameter in milliseconds, and converts it to the timer count
    that maps to that value.

Parameters:
    tim_x: pointer to the hardware timer handle to update.
    ADR_param: the Attack, Decay, or Release parameter to use to update the
    given hardware timer.

Returns:
    Mutates the given hardware timer CNT register.

Assumptions/Limitations:
    Assumes that the timer handle is configured for encoder mode with internal
    pullup resistors enabled, and configured to count up to 2^16 - 1.

    Assumes that the given ADR_param is within the bounds of that param type.
------------------------------------------------------------------------------*/
void ADR_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t ADR_param);

/*------------------------------------------------------------------------------
Function Name:
    S_param_to_encoder_count

Function Description:
    Inverse function to encoder_count_to_S_param. Takes a given Sustain parameter,
    and converts it to the timer count that maps to that value.

Parameters:
    tim_x: pointer to the hardware timer handle to update.
    S_param: the Sustain parameter to use to update the given hardware timer.

Returns:
    Mutates the given hardware timer CNT register.

Assumptions/Limitations:
    Assumes that the timer handle is configured for encoder mode with internal
    pullup resistors enabled, and configured to count up to 2^16 - 1.

    Assumes that the given S_param is within the bounds of that param type.
------------------------------------------------------------------------------*/
void S_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t S_param);

#endif
