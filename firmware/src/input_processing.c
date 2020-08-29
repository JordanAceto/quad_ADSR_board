/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   input_processing.c provides the implementation for using various input
--|   processing helper functions.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "global_data.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    lock_encoders_to_active_adsr

Function Description:
    Lock the encoders to the active ADSR. This means that rotating the encoders
    will update the active ADSR, the bi-color LEDs will show the position of
    the active ADSR, and the seven-segment LEDs will display parameters from
    the active ADSR.

Parameters:
    None

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void lock_encoders_to_active_adsr(void);

/*------------------------------------------------------------------------------
Function Name:
    update_ADSR_inputs

Function Description:
    Update the Attack, Decay, Sustain, and Release inputs for each of the
    four ADSRs based on the encoder readings and current mode.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void update_ADSR_inputs(void);

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

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void poll_encoders(void)
{
    for (int i = 0; i < NUM_ADSR_INPUT_TYPES; ++i)
    {
        // if you adjusted an encoder, make that one the active encoder
        if (cached_encoder_reading[i] != p_encoder[i]->CNT)
        {
            active_encoder = i;
            cached_encoder_reading[i] = p_encoder[i]->CNT;
        }
    }
}

void poll_pushbuttons(void)
{
    // read the buttons and select the active adsr and mode
    for (int i = 0; i < NUM_ADSR_INPUT_TYPES; ++i)
    {
        Poll_Discrete_Input(&pushbutton[i]);

        // clicking a button selects the active adsr and enters independent mode
        if (pushbutton[i].state == DISCRETE_INPUT_STATE_RISING_EDGE)
        {
            active_adsr = i;
            adsr_mode = ADSR_MODE_INDEPENDENT;
            lock_encoders_to_active_adsr();
        }

        // doing a long press selects the active adsr and enters lock-to-master mode
        if (pushbutton[i].state == DISCRETE_INPUT_STATE_LONG_HIGH)
        {
            active_adsr = i;
            adsr_mode = ADSR_MODE_LOCK_TO_MASTER;
            lock_encoders_to_active_adsr();
        }
    }
}

void poll_gate_and_trigger_inputs(void)
{
    // poll each trigger and gate input
    for (int i = 0; i < NUM_ADSRs; ++i)
    {
        Poll_Discrete_Input(&trigger_input[i]);

        // start an attack phase on rising triggers
        if (trigger_input[i].state == DISCRETE_INPUT_STATE_RISING_EDGE)
        {
            ADSR_Gate_On_Event(&adsr[i]);
        }

        Poll_Discrete_Input(&gate_input[i]);

        // start a release phase on falling gates
        if (gate_input[i].state == DISCRETE_INPUT_STATE_FALLING_EDGE)
        {
            ADSR_Gate_Off_Event(&adsr[i]);
        }
    }
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void lock_encoders_to_active_adsr(void)
{
    // set the timer CNT registers to the active adsr settings
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_ATTACK_TIME_mSec], adsr[active_adsr].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]);
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_DECAY_TIME_mSec], adsr[active_adsr].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec]);
    S_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10], adsr[active_adsr].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10]);
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_RELEASE_TIME_mSec], adsr[active_adsr].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]);

    // load the saved encoder settings from the encoder values
    for (int i = 0; i < NUM_ADSR_INPUT_TYPES; ++i)
    {
        cached_encoder_reading[i] = p_encoder[i]->CNT;
    }
}

void update_ADSR_inputs(void)
{
    if (adsr_mode == ADSR_MODE_INDEPENDENT) // only update the active ADSR
    {
        adsr[active_adsr].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]);
        adsr[active_adsr].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_DECAY_TIME_mSec]);
        adsr[active_adsr].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] = encoder_count_to_S_param(p_encoder[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10]);
        adsr[active_adsr].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]);
    }
    else // it is lock-to-master mode, so update the inputs to all the ADSRs
    {
        for (int i = 0; i < NUM_ADSRs; ++i)
        {
            adsr[i].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]);
            adsr[i].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_DECAY_TIME_mSec]);
            adsr[i].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] = encoder_count_to_S_param(p_encoder[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10]);
            adsr[i].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec] = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]);
        }
    }
}

uint32_t encoder_count_to_ADR_param(TIM_TypeDef * tim_x)
{
    // 16 bit signed raw reading makes it possible to clamp the timer
    int16_t raw_encoder_reading = tim_x->CNT;

    // 32 bit unsigned return value in the range [1, 60000]
    uint32_t retval;

    // clamp the encoder reading and the hardware timer to the low bound
    if (raw_encoder_reading < 1)
    {
        raw_encoder_reading = 1;
        tim_x->CNT = 1;
    }

    // clamp the encoder reading and the hardware timer to the high bound
    if (900 < raw_encoder_reading)
    {
        raw_encoder_reading = 900;
        tim_x->CNT = 900;
    }

    // scale the encoder according to the piecewise linear segments
    if (raw_encoder_reading <= 50) // 0.001 seconds to 0.050 seconds, 1 mSec steps
    {
        retval = raw_encoder_reading;
    }
    else if (raw_encoder_reading <= 240) // 0.055 seconds to 1.000 seconds, 5 mSec steps
    {
        retval = raw_encoder_reading * 5 - 200;
    }
    else if (raw_encoder_reading <= 440) // 1.010 seconds to 3.000 seconds, 10 mSec steps
    {
        retval = raw_encoder_reading * 10 - 1400;
    }
    else if (raw_encoder_reading <= 580) // 3.050 seconds to 10.00 seconds, 50 mSec steps
    {
        retval = raw_encoder_reading * 50 - 19000;
    }
    else if (raw_encoder_reading <= 780) // 10.10 seconds to 30.00 seconds, 100 mSec steps
    {
        retval = raw_encoder_reading * 100 - 48000;
    }
    else if (raw_encoder_reading <= 900) // 30.25 seconds to 60.00 seconds, 250 mSec steps
    {
        retval = raw_encoder_reading * 250 - 165000;
    }

    return retval;
}

uint32_t encoder_count_to_S_param(TIM_TypeDef * tim_x)
{
    // 16 bit signed raw reading makes it possible to clamp the timer
    int16_t raw_encoder_reading = tim_x->CNT;

    // 32 bit unsigned return value, range is [0, 1000]
    uint32_t retval;

    // clamp the encoder reading and the hardware timer to the low bound
    if (raw_encoder_reading <= 0)
    {
        raw_encoder_reading = 0;
        tim_x->CNT = 0;
    }

    // clamp the encoder reading and the hardware timer to the high bound
    if (1000 <= raw_encoder_reading)
    {
        raw_encoder_reading = 1000;
        tim_x->CNT = 1000;
    }

    retval = raw_encoder_reading;

    return retval;
}

void ADR_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t ADR_param)
{
    if (ADR_param <= 50)
    {
        tim_x->CNT = ADR_param;
    }
    else if (ADR_param <= 1000)
    {
        tim_x->CNT = (ADR_param + 200) / 5;
    }
    else if (ADR_param <= 3000)
    {
        tim_x->CNT = (ADR_param + 1400) / 10;
    }
    else if (ADR_param <= 10000)
    {
        tim_x->CNT = (ADR_param + 19000) / 50;
    }
    else if (ADR_param <= 30000)
    {
        tim_x->CNT = (ADR_param + 48000) / 100;
    }
    else if (ADR_param <= 60000)
    {
        tim_x->CNT = (ADR_param + 165000) / 250;
    }
}

void S_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t S_param)
{
    tim_x->CNT = S_param;
}
