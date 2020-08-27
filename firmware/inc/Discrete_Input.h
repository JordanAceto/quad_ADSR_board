/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   Discrete_Input.h provides an interface for using discrete inputs.
--|
--|   Discrete inputs are GPIO digital inputs, as opposed to analog, etc. inputs
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

#ifndef DISCRETE_INPUT_H_INCLUDED
#define DISCRETE_INPUT_H_INCLUDED

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
--| NAME: DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING
--| DESCRIPTION: the default setting for discrete input private fields
--| TYPE: uint
*/
#define DEFAULT_DISCRETE_INPUT_PRIVATE_SETTING (0)

/*
--| NAME: DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT
--| DESCRIPTION: setting for discrete inputs to disable long presses
--| TYPE: uint
*/
#define DISCRETE_INPUT_DISABLE_LONG_PRESS_COUNT (UINT32_MAX)

/*
--| NAME: DISCRETE_INPUT_DEFAULT_INITIAL_STATE
--| DESCRIPTION: the default state for discrete inputs
--| TYPE: Discrete_Input_State_t
*/
#define DISCRETE_INPUT_DEFAULT_INITIAL_STATE (DISCRETE_INPUT_STATE_LOW)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: Discrete_Input_State_t
--| DESCRIPTION: enumeration of possible discrete input states
*/
typedef enum Discrete_Input_Enumeration
{
    DISCRETE_INPUT_STATE_LOW = 0,
    DISCRETE_INPUT_STATE_HIGH,
    DISCRETE_INPUT_STATE_RISING_EDGE,
    DISCRETE_INPUT_STATE_FALLING_EDGE,
    DISCRETE_INPUT_STATE_LONG_LOW,
    DISCRETE_INPUT_STATE_LONG_HIGH,
} Discrete_Input_State_t;

/*
--| NAME: Discrete_Input_Polarity_t
--| DESCRIPTION: enumeration of discrete input polarities
*/
typedef enum Discrete_Input_Polarity_Enumeration
{
    DISCRETE_INPUT_POLARITY_ACTIVE_HIGH,
    DISCRETE_INPUT_POLARITY_ACTIVE_LOW
} Discrete_Input_Polarity_t;

/*
--| NAME: Discrete_Input_t
--| DESCRIPTION: structure for a single discrete input
--|
--| Members:
--|	    GPIO_port: pointer to the GPIO port for the discrete input
--|     GPIO_pin:  the GPIO pin number of the button
--|
--|     state: the current enumerated state of the discrete input
--|
--|     polarity: the polarity of the discrete input
--|
--|     debounce_count: when the discrete input consecutively reads high/low
--|         for this many readings, a rising/falling edge will be registered
--|
--|     long_press_count: when the discrete input consecutively reads high/low
--|         for at least this many readings, a long press/no-press will
--|         be registered
--|
--|     high_count: handled privately, the number of consecutive high readings
--|     low_count: handled privately, the number of consecutive low readings
*/
typedef struct Discrete_Input_Type
{
    GPIO_TypeDef * GPIO_port;
    uint16_t       GPIO_pin;

    Discrete_Input_State_t state;

    Discrete_Input_Polarity_t polarity;

    uint32_t debounce_count;
    uint32_t long_press_count;

    uint32_t high_count; // private
    uint32_t low_count;  // private
} Discrete_Input_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    Poll_Discrete_Input

Function Description:
    Poll the given button and update its state.

Parameters:
    p_discrete: pointer to the discrete input to poll.

Returns:
    Returns the current state of the discrete input pointed to by the given 
    pointer and mutates the discrete input.

Assumptions/Limitations:
    Assumes that the given discrete input is configured.
------------------------------------------------------------------------------*/
Discrete_Input_State_t Poll_Discrete_Input(Discrete_Input_t * p_discrete);

#endif
