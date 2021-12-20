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
#include "SysTick.h"
#include "TIM6.h"
#include "TIM7.h"

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
--| NAME: SYSTEM_CLOCK_SPEED
--| DESCRIPTION: System Core Clock frequency in Hz
--| TYPE: uint32_t
*/
#define SYSTEM_CLOCK_SPEED ((uint32_t)50E6)

/*
--| NAME: APB1_TIMER_CLOCK
--| DESCRIPTION: APB1 timer Clock frequency in Hz
--| TYPE: uint32_t
*/
#define APB1_TIMER_CLOCK (SYSTEM_CLOCK_SPEED)

/*
--| NAME: APB1_PERIPHERAL_CLOCK
--| DESCRIPTION: APB1 peripheral Clock frequency in Hz
--| TYPE: uint32_t
*/
#define APB1_PERIPHERAL_CLOCK (SYSTEM_CLOCK_SPEED/2u)

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
#define ADSR_SAMPLE_RATE_Hz (TIM6_FREQUENCY_Hz)

/*
--| NAME: CONTROL_SAMPLE_RATE_Hz
--| DESCRIPTION: the sample rate for the control signals, in Hertz
--| TYPE: uint
*/
#define CONTROL_SAMPLE_RATE_Hz (TIM7_FREQUENCY_Hz)

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
--| NAME: EEPROM_MEMORY_ADDRESS
--| DESCRIPTION: the start of the memory region used by the EEPROM
--| TYPE: uint
*/
#define EEPROM_MEMORY_ADDRESS (0x0u)

/*
--| NAME: ADSR_EEPROM_MEM_SIZE_IN_BYTES
--| DESCRIPTION: the number of bytes that the ADSR settings consume in the EEPROM
--|              4 ADSRs with 4 inputs each, each 32 bit input takes up 4 bytes
--| TYPE: uint
*/
#define ADSR_EEPROM_MEM_SIZE_IN_BYTES (NUM_ADSRs * NUM_ADSR_INPUT_TYPES * 4u)

/*
--| NAME: EEPROM_WAIT_TIME_MINUTES
--| DESCRIPTION: the time period to wait between EEPROM writes in minutes
--| TYPE: uint
*/
#define EEPROM_WAIT_TIME_MINUTES (10u)

/*
--| NAME: EEPROM_WAIT_TIME_mSec
--| DESCRIPTION: the time period to wait between EEPROM writes in milliseconds
--|              (1000 mSec/sec) * (60 sec/min) * (desired num minutes)
--| TYPE: uint
*/
#define EEPROM_WAIT_TIME_mSec (1000u * 60u * EEPROM_WAIT_TIME_MINUTES)

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
--| NAME: cached_ADSR_setting
--| DESCRIPTION: cached ADSR settings, used when going back and forth from independent/lock-to-master modes
--| TYPE: uint32_t
*/
uint32_t cached_ADSR_setting[NUM_ADSRs][NUM_ADSR_INPUT_TYPES];

/*
--| NAME: active_encoder
--| DESCRIPTION: represents the encoder which was last adjusted by the user
--| TYPE: ADSR_input_t
*/
ADSR_input_t active_encoder;

/*
--| NAME: EEPROM_periodic_timer
--| DESCRIPTION: Periodic timer object for scheduling EEPROM writes
--| TYPE: SysTick_Timeout_Timer_t
*/
SysTick_Timeout_Timer_t EEPROM_periodic_timer;

#endif