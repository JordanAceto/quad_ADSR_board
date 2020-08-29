/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   global_data.c provides access to the global data used by the system.
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "ADSR.h"
#include "Discrete_Input.h"
#include "global_data.h"
#include "GPIO.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: adsr
*/
ADSR_t adsr[NUM_ADSRs];

/*
--| NAME: active_adsr
*/
uint8_t active_adsr = 0;

/*
--| NAME: adsr_mode
*/
ADSR_Mode_t adsr_mode = ADSR_MODE_INDEPENDENT;

/*
--| NAME: p_encoder
*/
TIM_TypeDef * p_encoder[NUM_ADSR_INPUT_TYPES] =
{
    TIM2, // the order is deliberate and important,
    TIM8, // array order is dictated by pcb layout
    TIM1,
    TIM4
};

/*
--| NAME: gate_input
*/
Discrete_Input_t gate_input[NUM_ADSRs] =
{
    {
        GATE_1_GPIO_Port,
        GATE_1_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        GATE_2_GPIO_Port,
        GATE_2_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        GATE_3_GPIO_Port,
        GATE_3_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        GATE_4_GPIO_Port,
        GATE_4_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    }
};

/*
--| NAME: trigger_input
*/
Discrete_Input_t trigger_input[NUM_ADSRs] =
{
    {
        TRIG_1_GPIO_Port,
        TRIG_1_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        TRIG_2_GPIO_Port,
        TRIG_2_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        TRIG_3_GPIO_Port,
        TRIG_3_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        TRIG_4_GPIO_Port,
        TRIG_4_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        GATE_AND_TRIGGER_DEBOUNCE_COUNT,
        DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    }
};

/*
--| NAME: pushbutton
*/
Discrete_Input_t pushbutton[NUM_ADSR_INPUT_TYPES] =
{
    {
        ENCODER_1_SWITCH_GPIO_Port,
        ENCODER_1_SWITCH_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        PUSHBUTTON_DEBOUNCE_COUNT,
        PUSHBUTTON_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        ENCODER_2_SWITCH_GPIO_Port,
        ENCODER_2_SWITCH_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        PUSHBUTTON_DEBOUNCE_COUNT,
        PUSHBUTTON_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        ENCODER_3_SWITCH_GPIO_Port,
        ENCODER_3_SWITCH_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        PUSHBUTTON_DEBOUNCE_COUNT,
        PUSHBUTTON_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },

    {
        ENCODER_4_SWITCH_GPIO_Port,
        ENCODER_4_SWITCH_Pin,
        DISCRETE_INPUT_DEFAULT_INITIAL_STATE,
        DISCRETE_INPUT_POLARITY_ACTIVE_LOW,
        PUSHBUTTON_DEBOUNCE_COUNT,
        PUSHBUTTON_LONG_PRESS_COUNT,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING,
        DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
    },
};

/*
--| NAME: cached_encoder_reading
*/
uint16_t cached_encoder_reading[NUM_ADSR_INPUT_TYPES] =
{
    0, 0, 0, 0
};

/*
--| NAME: active_encoder
*/
ADSR_input_t active_encoder = ADSR_INPUT_TYPE_ATTACK_TIME_mSec;

/*
--| NAME: eeprom_save_allowed
*/
bool eeprom_save_allowed = false;
