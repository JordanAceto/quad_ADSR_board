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
