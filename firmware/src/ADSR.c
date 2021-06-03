 /*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   ADSR.c provides the implementation for the functions declared in ADSR.h,
--|   as well as helper functions and private data to support the system.
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

#include "ADSR.h"
#include "lookup_tables.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: ACCUMULATOR_BIT_WIDTH
--| DESCRIPTION: bit width of the phase accumulator.
--| TYPE: uint32_t
*/
#define ACCUMULATOR_BIT_WIDTH (32u)

/*
--| NAME: NUM_INDEX_BITS_IN_ACCUMULATOR
--| DESCRIPTION: the number of index bits the phase accumulator.
--| TYPE: uint32_t
*/
#define NUM_INDEX_BITS_IN_ACCUMULATOR (10u)

/*
--| NAME: NUM_FRACTIONAL_BITS_IN_ACCUMULATOR
--| DESCRIPTION: the number of fractional bits the phase accumulator.
--| TYPE: uint32_t
*/
#define NUM_FRACTIONAL_BITS_IN_ACCUMULATOR (ACCUMULATOR_BIT_WIDTH - NUM_INDEX_BITS_IN_ACCUMULATOR)

/*
--| NAME: MAX_ACCUMULATOR_VALUE
--| DESCRIPTION: the maximum value of the phase accumulator.
--| TYPE: uint64_t (to avoid truncation)
*/
#define MAX_ACCUMULATOR_VALUE (((uint64_t)1u << ACCUMULATOR_BIT_WIDTH) - 1u)

/*
--| NAME: ACCUMULATOR_FRACTION_MASK
--| DESCRIPTION: a mask to isolate the fractional part of the accumulator.
--| TYPE: uint32_t
*/
#define ACCUMULATOR_FRACTION_MASK ~((1u << NUM_FRACTIONAL_BITS_IN_ACCUMULATOR) - 1u)

/*
--| NAME: ADSR_LOOK_UP_TABLE_TABLE_SIZE
--| DESCRIPTION: the size of the attack and decay look up tables.
--| TYPE: uint32_t
*/
#define ADSR_LOOK_UP_TABLE_TABLE_SIZE (1u << NUM_INDEX_BITS_IN_ACCUMULATOR)

/*
--| NAME: MAX_ADSR_VALUE
--| DESCRIPTION: the maximum value of the ADSR.
--| TYPE: uint32_t
*/
#define MAX_ADSR_VALUE (0xFFFFFFFFu)

/*
--| NAME: SUSTAIN_SCALER
--| DESCRIPTION: scaler to map sustain from [0, 1000] to [0, 2^32 - 1]
--| TYPE: uint32_t
*/
#define SUSTAIN_SCALER (MAX_ADSR_VALUE / ADSR_MAX_SUSTAIN_LEVEL_percent_x_10)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    Current_ADSR_State_Is_Tickable

Function Description:
    Determine if the current state of the given ADSR is tickable or not.
        Attack, Decay, and Release states are tickable.
        Sustain and At-Rest states are not tickable.
    
Parameters:
    * p_ADSR: pointer to the given ADSR.

Returns:
    uint32_t: boolean signal. 1 if the current state is tickable, else 0.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static uint32_t Current_ADSR_State_Is_Tickable(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    Calculate_Tuning_Word_And_Increment_Accumulator

Function Description:
    Calculate the phase accumulator tuning word for the current state of the 
    given ADSR and increment the accumulator.

    This function must only be called when the current ADSR state is tickable,
    ie: the ADSR state is either Attack, Decay, or Release.
    
Parameters:
    * p_ADSR: pointer to the given ADSR.

Returns:
    None. Modifies the data held by p_ADSR.

Assumptions/Limitations:
    Assumes the the current state of the given ADSR is tickable.
------------------------------------------------------------------------------*/
static void Calculate_Tuning_Word_And_Increment_Accumulator(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    Handle_State_Transitions

Function Description:
    Handle the state transitions for the given ADSR.

    If the current state is complete, reset the accumulator and increment the 
    ADSR state.
    
Parameters:
    * p_ADSR: pointer to the given ADSR.

Returns:
    None. Modifies the data held by p_ADSR.

Assumptions/Limitations:
    None.
------------------------------------------------------------------------------*/
static void Handle_State_Transitions(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    Calculate_Current_ADSR_Value

Function Description:
    Calculate the value of the current unsigned 32 bit sample of the ADSR.
    
Parameters:
    * p_ADSR: pointer to the given ADSR.

Returns:
    None. Modifies the data held by p_ADSR.

Assumptions/Limitations:
    None.
------------------------------------------------------------------------------*/
static void Calculate_Current_ADSR_Value(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    Linear_Interpolation

Function Description:
    Linearly interpolate two points where y1 is the current point in the LUT, 
    y2 is the next point in the LUT, and the fraction is composed of the lower  
    NUM_FRACTIONAL_BITS_IN_ACCUMULATOR bits in the accumulator and represents 
    how far you are in the x direction between y1 and y2.
    
Parameters:
    y1: the current point in the LUT
    y2: the next point in the LUT
    fraction: the lower NUM_FRACTIONAL_BITS_IN_ACCUMULATOR bits in the 
        accumulator. represents how far you are in the x direction between 
        y1 and y2.

Returns:
    uint32_t: the linearly interpolated value between y1 and y2.

Assumptions/Limitations:
    None.
------------------------------------------------------------------------------*/
static uint32_t Linear_Interpolation(uint32_t y1, uint32_t y2, uint32_t fraction);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void Initialize_ADSR(ADSR_t * p_ADSR, uint32_t sample_rate)
{
    p_ADSR->state = ADSR_STATE_TYPE_AT_REST;

    p_ADSR->input[ADSR_INPUT_TYPE_ATTACK_TIME_mSec]           = ADSR_DEFAULT_ATTACK_TIME_mSec;
    p_ADSR->input[ADSR_INPUT_TYPE_DECAY_TIME_mSec]            = ADSR_DEFAULT_DECAY_TIME_mSec;
    p_ADSR->input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] = ADSR_DEFAULT_SUSTAIN_LEVEL_percent_x_10;
    p_ADSR->input[ADSR_INPUT_TYPE_RELEASE_TIME_mSec]          = ADSR_DEFAULT_RELEASE_TIME_mSec;

    p_ADSR->current_value = 0u;

    p_ADSR->phase_accumulator = 0u;
    p_ADSR->last_accumulator_value = 0u;

    p_ADSR->value_when_gate_on_recieved = 0;
    p_ADSR->value_when_gate_off_recieved = 0u;

    p_ADSR->sample_rate = sample_rate;
}

void ADSR_Tick(ADSR_t * p_ADSR)
{
    if (Current_ADSR_State_Is_Tickable(p_ADSR))
    {
        // save the last accumulator value before updating
        p_ADSR->last_accumulator_value = p_ADSR->phase_accumulator;

        Calculate_Tuning_Word_And_Increment_Accumulator(p_ADSR);

        Handle_State_Transitions(p_ADSR);
    }

    Calculate_Current_ADSR_Value(p_ADSR);
}

void ADSR_Gate_On_Event(ADSR_t * p_ADSR)
{
    if (p_ADSR->state != ADSR_STATE_TYPE_ATTACK)
    {
        p_ADSR->value_when_gate_on_recieved = p_ADSR->current_value;
        p_ADSR->phase_accumulator = 0u;
        p_ADSR->last_accumulator_value = 0u;
        p_ADSR->state = ADSR_STATE_TYPE_ATTACK;
    }
    else
    {
        /* The ADSR is already in an attack phase, ignore the gate-on message. */
    }
}

void ADSR_Gate_Off_Event(ADSR_t * p_ADSR)
{
    if (p_ADSR->state == ADSR_STATE_TYPE_ATTACK ||
        p_ADSR->state == ADSR_STATE_TYPE_DECAY  ||
        p_ADSR->state == ADSR_STATE_TYPE_SUSTAIN)
    {
        p_ADSR->value_when_gate_off_recieved = p_ADSR->current_value;
        p_ADSR->phase_accumulator = 0u;
        p_ADSR->last_accumulator_value = 0u;
        p_ADSR->state = ADSR_STATE_TYPE_RELEASE;
    }
    else
    {
        /* 
        The ADSR is already in a release phase, or it is already at-rest, 
        ignore the gate-off message. 
        */
    }
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

uint32_t Current_ADSR_State_Is_Tickable(ADSR_t * p_ADSR)
{
    const ADSR_state_t current_state = p_ADSR->state;

    return current_state == ADSR_STATE_TYPE_ATTACK ||
           current_state == ADSR_STATE_TYPE_DECAY  ||
           current_state == ADSR_STATE_TYPE_RELEASE;
}

void Calculate_Tuning_Word_And_Increment_Accumulator(ADSR_t * p_ADSR)
{
    const uint32_t period_of_current_state_in_mSec = p_ADSR->input[p_ADSR->state];

    const uint32_t mSec_per_second = 1000u;
    const uint64_t numerator = MAX_ACCUMULATOR_VALUE * mSec_per_second;

    const uint32_t tuning_word = (numerator) / (p_ADSR->sample_rate * period_of_current_state_in_mSec);

    p_ADSR->phase_accumulator += tuning_word;
}

void Handle_State_Transitions(ADSR_t * p_ADSR)
{
    // If the last accumulator value is bigger than the current one, it means that the accumulator
    // has wrapped around past zero, this means that the current phase is complete.
    const uint32_t accumulator_has_rolled_over = p_ADSR->phase_accumulator < p_ADSR->last_accumulator_value;

    if (accumulator_has_rolled_over)
    {
        // reset the accumulator and move to the next phase
        p_ADSR->phase_accumulator = 0u;
        p_ADSR->last_accumulator_value = 0u;

        // advance to the next ADSR state
        switch (p_ADSR->state)
        {
        case ADSR_STATE_TYPE_AT_REST:
            // at-rest state only changes after a gate-on message
            break;

        case ADSR_STATE_TYPE_ATTACK:
            p_ADSR->state = ADSR_STATE_TYPE_DECAY;
            break;

        case ADSR_STATE_TYPE_DECAY:
            p_ADSR->state = ADSR_STATE_TYPE_SUSTAIN;
            break;

        case ADSR_STATE_TYPE_SUSTAIN:
            // sustain state only changes after a gate-off message
            break;

        case ADSR_STATE_TYPE_RELEASE:
            p_ADSR->state = ADSR_STATE_TYPE_AT_REST;
            break;
        
        default:
            p_ADSR->state = ADSR_STATE_TYPE_AT_REST;
            break;
        }
    }
}

void Calculate_Current_ADSR_Value(ADSR_t * p_ADSR)
{
    /*
    The coefficient for the sample is between 0 and full scale. This is used to
    accomplish a multiplication of the ADSR value by a coefficient between 0.0 
    and 1.0, using only integer multiplication. This is used to "squish" the 
    attack, decay, and release curves as needed. 
    
    Example: the decay curve starts at full scale, and ramps down to the sustain 
    level. The range of the decay curve from top to bottom is full-scale at the 
    top to sustain level at the bottom. The decay curve must be compressed to 
    fit in this reduced range. The coefficient variable helps accomplish this. 
    */
    uint64_t coefficient;

    /* 
    The value of the current sample. This will come from the attack LUT if the 
    current state is attack, from the decay LUT if the current state is decay 
    or release, and from the sustain level input if the current state is 
    sustain. If the current state is at-rest, the value of the sample will be 
    zero.
    */
    uint64_t sample;

    /*
    The offset for the current sample. This is only non-zero when an attack 
    phase begins while the ADSR is not at rest, or a decay phase begins while 
    the sustain level is non-zero. Basically this is how much to "push up" the 
    ADSR curve, so that it fits between the starting value for the curve segment 
    and the target value for the curve segment.
    */
    uint64_t offset;

    /*
    y1 and y2 are used for linear interpolation. These are only used for the 
    attack, decay, and release phases. y1 is the value in the appropriate LUT 
    at the current accumulator index. y2 is the value in the appropriate LUT at 
    the next index. The fractional part of the accumulator is used to calculate 
    a point on the line between y1 and y2 that approximates the ADSR value 
    between the two points in the LUT.
    */
    uint32_t y1;
    uint32_t y2;

    // the current LUT index
    const uint32_t LUT_index = p_ADSR->phase_accumulator >> NUM_FRACTIONAL_BITS_IN_ACCUMULATOR;

    // the next LUT index for interpolation, clamps at the max index to avoid bad behavior
    const uint32_t next_idx = (LUT_index + 1u) < ADSR_LOOK_UP_TABLE_TABLE_SIZE ? LUT_index + 1u : ADSR_LOOK_UP_TABLE_TABLE_SIZE - 1u;

    // the fractional part of the phase accumulator
    const uint32_t accumulator_fraction = p_ADSR->phase_accumulator & ACCUMULATOR_FRACTION_MASK;

    switch (p_ADSR->state)
    {
    case ADSR_STATE_TYPE_ATTACK:
        y1 = ADSR_ATTACK_TABLE[LUT_index];
        y2 = ADSR_ATTACK_TABLE[next_idx];
        
        coefficient = MAX_ADSR_VALUE - p_ADSR->value_when_gate_on_recieved;
        sample      = Linear_Interpolation(y1, y2, accumulator_fraction);
        offset      = p_ADSR->value_when_gate_on_recieved;
        break;

    case ADSR_STATE_TYPE_DECAY:
        y1 = ADSR_DECAY_TABLE[LUT_index];
        y2 = ADSR_DECAY_TABLE[next_idx];

        coefficient = MAX_ADSR_VALUE - (p_ADSR->input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] * SUSTAIN_SCALER);
        sample      = Linear_Interpolation(y1, y2, accumulator_fraction);
        offset      = p_ADSR->input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] * SUSTAIN_SCALER;
        break;

    case ADSR_STATE_TYPE_SUSTAIN:
        coefficient = MAX_ADSR_VALUE;
        sample      = p_ADSR->input[ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10] * SUSTAIN_SCALER;
        offset      = 0u;
        break;

    case ADSR_STATE_TYPE_RELEASE:
        y1 = ADSR_DECAY_TABLE[LUT_index];
        y2 = ADSR_DECAY_TABLE[next_idx];

        coefficient = p_ADSR->value_when_gate_off_recieved;
        sample      = Linear_Interpolation(y1, y2, accumulator_fraction);
        offset      = 0u;
        break;
    
    case ADSR_STATE_TYPE_AT_REST:
        coefficient = 0u;
        sample      = 0u;
        offset      = 0u;
        break;

    default:
        coefficient = 0u;
        sample      = 0u;
        offset      = 0u;
        break;
    }

    const uint64_t scaled_sample = (coefficient * sample) / MAX_ADSR_VALUE;
    p_ADSR->current_value = scaled_sample + offset;
}

uint32_t Linear_Interpolation(uint32_t y1, uint32_t y2, uint32_t fraction)
{
    const uint32_t delta_y = y2 - y1;

    const uint32_t fractional_part = (fraction * delta_y) >> NUM_FRACTIONAL_BITS_IN_ACCUMULATOR;

    return y1 + fractional_part;
}
