/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   global_data.h provides access to the global data used by the system.
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None
--|
--|----------------------------------------------------------------------------|
*/

#ifndef GLOBAL_DATA_H_INCLUDED
#define GLOBAL_DATA_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "ADSR.h"
#include "Discrete_Input.h"
#include <stdbool.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: ADSR_Mode_t
--| DESCRIPTION: Enumeration for the available ADSR control modes. In independent
--| mode, each of the four ADSRs has unique values for the A, D, S, and R
--| parameters. In lock-to-master mode, the four ADSRs all lock to a common set
--| of A, D, S, and R parameters given by the active ADSR.
*/
typedef enum ADSR_Mode_Type
{
    ADSR_MODE_INDEPENDENT = 0,
    ADSR_MODE_LOCK_TO_MASTER = 1
} ADSR_Mode_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: NUM_ADSRs
--| DESCRIPTION: the number of ADSR generators in the system
--| TYPE: uint
*/
#define NUM_ADSRs (4u)

/*
--| NAME: ADSR_SAMPLE_RATE_Hz
--| DESCRIPTION: the sample rate for the ADSRs, in Hertz
--| TYPE: uint
*/
#define ADSR_SAMPLE_RATE_Hz (5E3)

/*
--| NAME: CONTROL_SAMPLE_RATE_Hz
--| DESCRIPTION: the sample rate for the control signals, in Hertz
--| TYPE: uint
*/
#define CONTROL_SAMPLE_RATE_Hz (1E3)

/*
--| NAME: GATE_AND_TRIGGER_DEBOUNCE_COUNT
--| DESCRIPTION: the debounce count used for discrete gate and trigger inputs
--| TYPE: uint
*/
#define GATE_AND_TRIGGER_DEBOUNCE_COUNT (10u)

/*
--| NAME: PUSHBUTTON_DEBOUNCE_COUNT
--| DESCRIPTION: the debounce count used for the encoder pushbuttons
--| TYPE: uint
*/
#define PUSHBUTTON_DEBOUNCE_COUNT (10u)

/*
--| NAME: PUSHBUTTON_LONG_PRESS_COUNT
--| DESCRIPTION: the debounce long-press count used for the encoder pushbuttons
--| TYPE: uint
*/
#define PUSHBUTTON_LONG_PRESS_COUNT (1000u)

/*
--| NAME: NUM_MCP4822_DACs
--| DESCRIPTION: the number of MCP4822 12-bit SPI DACs in the system
--| NOTE: each MCP4822 has 2 channels, so 2 DACs handle the 4 ADSRs
--| TYPE: uint
*/
#define NUM_MCP4822_DACs (2u)

/*
--| NAME: EEPROM_DEVICE_ADDRESS
--| DESCRIPTION: the device address for the 24LCxx EEPROM used by the system
--| TYPE: uint
*/
#define EEPROM_DEVICE_ADDRESS (0xA0u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: adsr
--| DESCRIPTION: the array of Attack Decay Sustain Release generators
--| TYPE: ADSR_t
*/
ADSR_t adsr[NUM_ADSRs];

/*
--| NAME: active_adsr
--| DESCRIPTION: the index of the adsr that is currently selected, range: [0, NUM_ADSRs - 1]
--| TYPE: uint8_t
*/
uint8_t active_adsr;

/*
--| NAME: adsr_mode
--| DESCRIPTION: the current mode, independent or lock-to-master
--| TYPE: ADSR_Mode_t
*/
ADSR_Mode_t adsr_mode;

/*
--| NAME: p_encoder
--| DESCRIPTION: array of pointers to the four TIMx timers configured as encoders
--| TYPE: TIM_TypeDef
*/
TIM_TypeDef * p_encoder[NUM_ADSR_INPUT_TYPES];

/*
--| NAME: gate_input
--| DESCRIPTION: array of gate inputs
--| TYPE: Discrete_Input_t
*/
Discrete_Input_t gate_input[NUM_ADSRs];

/*
--| NAME: trigger_input
--| DESCRIPTION: array of trigger inputs
--| TYPE: Discrete_Input_t
*/
Discrete_Input_t trigger_input[NUM_ADSRs];

/*
--| NAME: pushbutton
--| DESCRIPTION: array of the four encoder pushbuttons
--| TYPE: Discrete_Input_t
*/
Discrete_Input_t pushbutton[NUM_ADSR_INPUT_TYPES];

/*
--| NAME: cached_encoder_reading
--| DESCRIPTION: cached encoder readings used to detect changes in encoder position
--| TYPE: uint16_t
*/
uint16_t cached_encoder_reading[NUM_ADSR_INPUT_TYPES];

/*
--| NAME: active_encoder
--| DESCRIPTION: represents the encoder which was last adjusted by the user
--| TYPE: ADSR_input_t
*/
ADSR_input_t active_encoder;

/*
--| NAME: eeprom_save_allowed
--| DESCRIPTION: boolean guard, allows or forbids writing to the EEPROM
--| TYPE: bool
*/
bool eeprom_save_allowed;

#endif
