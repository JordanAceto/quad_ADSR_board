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

#include "encoders.h"
#include "global_data.h"
#include "input_processing.h"

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
            set_encoders_to_active_adsr_values();
        }

        // doing a long press selects the active adsr and enters lock-to-master mode
        if (pushbutton[i].state == DISCRETE_INPUT_STATE_LONG_HIGH)
        {
            active_adsr = i;
            adsr_mode = ADSR_MODE_LOCK_TO_MASTER;
            set_encoders_to_active_adsr_values();
        }
    }
}

void set_encoders_to_active_adsr_values(void)
{
    // collect the A, D, S, and R values of the active ADSR
    const uint32_t A = adsr[active_adsr].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec];
    const uint32_t D = adsr[active_adsr].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec];
    const uint32_t S = adsr[active_adsr].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10];
    const uint32_t R = adsr[active_adsr].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec];

    // set the timer CNT registers to the active adsr settings
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_ATTACK_TIME_mSec],         A);
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_DECAY_TIME_mSec],          D);
    S_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10], S);
    ADR_param_to_encoder_count(p_encoder[ADSR_INPUT_TYPE_RELEASE_TIME_mSec],        R);

    // load the saved encoder settings from the encoder values
    for (int i = 0; i < NUM_ADSR_INPUT_TYPES; ++i)
    {
        cached_encoder_reading[i] = p_encoder[i]->CNT;
    }
}

void update_ADSR_inputs(void)
{
    // collect the current A, D, S, and R settings
    const uint32_t A = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]);
    const uint32_t D = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_DECAY_TIME_mSec]);
    const uint32_t S = encoder_count_to_S_param(p_encoder[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10]);
    const uint32_t R = encoder_count_to_ADR_param(p_encoder[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]);

    if (adsr_mode == ADSR_MODE_INDEPENDENT) // only update the active ADSR
    {
        adsr[active_adsr].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]           = A;
        adsr[active_adsr].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec]            = D;
        adsr[active_adsr].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] = S;
        adsr[active_adsr].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]          = R;
    }
    else // it is lock-to-master mode, so update the inputs to all the ADSRs
    {
        for (int i = 0; i < NUM_ADSRs; ++i)
        {
            adsr[i].input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]           = A;
            adsr[i].input[ADSR_INPUT_TYPE_DECAY_TIME_mSec]            = D;
            adsr[i].input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] = S;
            adsr[i].input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]          = R;
        }
    }
}

void poll_gate_and_trigger_inputs(void)
{
    // poll each trigger and gate input
    for (int i = 0; i < NUM_ADSRs; ++i)
    {
        Poll_Discrete_Input(&gate_input[i]);
        Poll_Discrete_Input(&trigger_input[i]);

        // start an attack phase on rising gate or trigger edges
        if ((gate_input[i].state == DISCRETE_INPUT_STATE_RISING_EDGE) || (trigger_input[i].state == DISCRETE_INPUT_STATE_RISING_EDGE))
        {
            ADSR_Gate_On_Event(&adsr[i]);
        }

        // start a release phase on falling gate edges
        if (gate_input[i].state == DISCRETE_INPUT_STATE_FALLING_EDGE)
        {
            ADSR_Gate_Off_Event(&adsr[i]);
        }
    }
}
