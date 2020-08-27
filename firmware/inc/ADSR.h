 /*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|      ADSR stands for Attack Decay Sustain Release generator.
--|      ADSRs are a standard component of most analog synthesizers.
--|      ADSRs are used to dynamically modulate various parameters
--|      of synthesizers, most commonly loudness, timbre, or pitch.
--| 
--|      This ADSR simulates the RC curves typically found in analog 
--|      ADSRs, where the attack curve is a truncated up-going convex 
--|      RC curve, and the decay and release curves are down-going
--|      concave RC curves.
--| 
--|      This ADSR has four variable input parameters: 
--|          Attack time
--|          Decay time
--|          Sustain level
--|          Release time
--| 
--|      This ADSR responds to these types of time based events:
--|          Gate On events:  initiate an attack phase
--|          Gate Off events: initiate a release phase
--| 
--|      This ADSR has a single output:
--|          The current sample of the ADSR waveform
--|      
--|      This software ADSR is implemented with fixed-point 32 bit 
--|      unsigned integer types for all of the input and output
--|      parameters.
--| 
--|      A Phase-Accumulator and Look-Up-Table (LUT) approach is used.
--|      This is known as "Direct Digital Synthesis", or DDS.
--| 
--|      Look Up Tables (LUTs) are used to store the Attack and Decay 
--|      curves for the ADSRs. These curves simulate the typical
--|      resistor/capacitor time constant curves used in analog ADSRs.
--| 
--|      Acronyms used:
--|          ADSR: Attack Decay Sustain Release generator
--|          LUT:  Look Up Table
--|          DDS:  Direct Digital Synthesis
--| 
--| NOTES:
--|      Some familiarity with analog synthesizer terminology and analog
--|      ADSRs will be helpful in understanding this software module.
--| 
--|      Some familiarity with phase accumulators, DDS, and linear interpolation
--|      will be helpful as well.
--| 
--| REFERENCES:
--|      https://en.wikipedia.org/wiki/Envelope_(music)
--|      https://en.wikipedia.org/wiki/Numerically-controlled_oscillator
--|      https://en.wikipedia.org/wiki/Linear_interpolation
--|      https://www.digikey.com/en/articles/techzone/2019/mar/the-basics-of-direct-digital-synthesizers-ddss
--|----------------------------------------------------------------------------|
*/

#ifndef ADSR_H_INCLUDED
#define ADSR_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdint.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: ADSR_MAX_ATTACK_TIME_mSec
--| DESCRIPTION: Max attack time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_MAX_ATTACK_TIME_mSec (60000u)

/*
--| NAME: ADSR_MAX_DECAY_TIME_mSec
--| DESCRIPTION: Max decay time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_MAX_DECAY_TIME_mSec (60000u)

/*
--| NAME: ADSR_MAX_SUSTAIN_LEVEL_percent_x_10
--| DESCRIPTION: Max sustain level, in [percent * 10].
--| TYPE: uint32_t
*/
#define ADSR_MAX_SUSTAIN_LEVEL_percent_x_10 (1000u)

/*
--| NAME: ADSR_MAX_RELEASE_TIME_mSec
--| DESCRIPTION: Max release time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_MAX_RELEASE_TIME_mSec (60000u)

/*
--| NAME: ADSR_DEFAULT_ATTACK_TIME_mSec
--| DESCRIPTION: Default attack time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_DEFAULT_ATTACK_TIME_mSec (100u)

/*
--| NAME: ADSR_DEFAULT_DECAY_TIME_mSec
--| DESCRIPTION: Default decay time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_DEFAULT_DECAY_TIME_mSec (500u)

/*
--| NAME: ADSR_DEFAULT_SUSTAIN_LEVEL_percent_x_10
--| DESCRIPTION: Default sustain level, sustain range: [0, 1000].
--| TYPE: uint32_t
*/
#define ADSR_DEFAULT_SUSTAIN_LEVEL_percent_x_10 (500)

/*
--| NAME: ADSR_DEFAULT_RELEASE_TIME_mSec
--| DESCRIPTION: Default release time, in milliseconds.
--| TYPE: uint32_t
*/
#define ADSR_DEFAULT_RELEASE_TIME_mSec (500u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: ADSR_input_t
--| DESCRIPTION: Enumeration for the four variable input parameters to the ADSR.
--|     These enumerations are used to give symbolic names to the input
--|     parameters, and to index into an array holding input variables.
*/
typedef enum ADSR_Input_Type
{
    ADSR_INPUT_TYPE_ATTACK_TIME_mSec = 0u,
    ADSR_INPUT_TYPE_DECAY_TIME_mSec,
    ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10,
    ADSR_INPUT_TYPE_RELEASE_TIME_mSec,
    NUM_ADSR_INPUT_TYPES
} ADSR_input_t;

/*
--| NAME: ADSR_state_t
--| DESCRIPTION: enumeration for the five possible states of the ADSR.
--|     These enumerations are used to give a symbolic name to the
--|     current state of the ADSR. These enumerations are also used to
--|     index into an array holding input variables.
*/
typedef enum ADSR_State_Type
{
    ADSR_STATE_TYPE_ATTACK = 0u,
    ADSR_STATE_TYPE_DECAY,
    ADSR_STATE_TYPE_SUSTAIN,
    ADSR_STATE_TYPE_RELEASE,
    ADSR_STATE_TYPE_AT_REST,
    NUM_ADSR_STATES
} ADSR_state_t;

/*
--| NAME: ADSR_t
--| DESCRIPTION: struct holding the variables which represent an ADSR object.
--|
--| Members:
--|     ADSR_state_t state: the current enumerated state of the ADSR.
--|     
--|     uint32_t input[NUM_ADSR_INPUT_TYPES]: array of uint32_t input variables.
--|         ADSR_INPUT_TYPE_ATTACK_TIME_mSec
--|         ADSR_INPUT_TYPE_DECAY_TIME_mSec
--|         ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10
--|         ADSR_INPUT_TYPE_RELEASE_TIME_mSec
--|     
--|     uint32_t current_value: the current 32 bit value of the ADSR.
--|     
--|     uint32_t accumulator: handled privately.   
--|     uint32_t last_accumulator_value: handled privately.
--|     uint32_t value_when_gate_on_recieved: handled privately. 
--|     uint32_t value_when_gate_off_recieved: handled privately.
--|     
--|     uint32_t sample_rate: the sample rate of the ADSR, in Hertz.   
*/
typedef struct ADSR_Type
{
    ADSR_state_t state;

    uint32_t input[NUM_ADSR_INPUT_TYPES];

    uint32_t current_value;

    uint32_t phase_accumulator;
    uint32_t last_accumulator_value;
    uint32_t value_when_gate_on_recieved;
    uint32_t value_when_gate_off_recieved;

    uint32_t sample_rate;

} ADSR_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    ADSR_Initialize_Look_Up_Tables

Function Description:
    The ADSR uses Look Up Tables (LUTs) to hold the Attack and Decay curves used
    to set the ADSR output. These LUTs must be filled before using any ADSRs.

    This function calculates the values for the LUTs and fills them with those
    values.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    This function must be called once before using any ADSRs.
------------------------------------------------------------------------------*/
void ADSR_Initialize_Look_Up_Tables(void);

/*------------------------------------------------------------------------------
Function Name:
    Initialize_ADSR

Function Description:
    Initialize a given ADSR struct by setting all input parameters to their 
    default values, setting the output to zero, setting the sample rate to the 
    given value, and setting the state to ADSR_STATE_TYPE_AT_REST.

Parameters:
    * p_ADSR: pointer to the ADSR struct to initialize.
    sample_rate: the sample rate for the ADSR, in Hz.

Returns:
    None.

Assumptions/Limitations:
    It is assumed that this function will be called prior to using the given
    ADSR.

    Also assumed that the given ADSR will be ticked at the given sample rate.
------------------------------------------------------------------------------*/
void Initialize_ADSR(ADSR_t * p_ADSR, uint32_t sample_rate);

/*------------------------------------------------------------------------------
Function Name:
    ADSR_Tick

Function Description:
    Process one tick of a given ADSR struct. During a "tick", the phase 
    accumulator is incremented, the current state is determined, and the 
    current output level is set.

    This function MUST be called periodically at the sample rate held by the 
    ADSR that is passed in to this function.

Parameters:
    * p_ADSR: pointer to the ADSR struct to tick.

Returns:
    Mutates the fields of p_ADSR

Assumptions/Limitations:
    If this function is not called periodically at the sample rate held by the 
    ADSR that is passed in, then the Attack, Decay, and Release times will be
    incorrect.
------------------------------------------------------------------------------*/
void ADSR_Tick(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    ADSR_Gate_On_Event

Function Description:
    Initiates a gate-on event for a given ADSR. A gate-on event causes the ADSR 
    to enter the attack phase, unless the ADSR is already in the middle of an 
    attack phase.

    If a gate-on message is received while the ADSR is already in an attack
    phase, then the ADSR will ignore the gate-on message and finish the 
    existing attack phase.

    If a gate-on message is received during a decay, sustain, or release phase, 
    the ADSR will be "retriggered", and a new attack phase will begin starting 
    from the current ADSR level.

Parameters:
    * p_ADSR: pointer to the ADSR struct to send a gate-on message to.

Returns:
    Mutates the fields of p_ADSR

Assumptions/Limitations:
    Assumes that p_ADSR has been properly initialized.
------------------------------------------------------------------------------*/
void ADSR_Gate_On_Event(ADSR_t * p_ADSR);

/*------------------------------------------------------------------------------
Function Name:
    ADSR_Gate_Off_Event

Function Description:
    Initiates a gate-off event for a given ADSR. A gate-off event causes the 
    ADSR to enter the release phase, unless the ADSR is already in a release 
    phase or the ADSR is in an at-rest phase.

    If a gate-off message is received while the ADSR is already in a release
    phase, then the ADSR will ignore the gate-off message and finish the 
    existing release phase.

    If a gate-off message is received while the ADSR is in the at-rest phase,
    then the gate-off message will be ignored and the ADSR will remain at-rest. 

Parameters:
    * p_ADSR: pointer to the ADSR struct to send a gate-off message to.

Returns:
    Mutates the fields of p_ADSR

Assumptions/Limitations:
    Assumes that p_ADSR has been properly initialized.
------------------------------------------------------------------------------*/
void ADSR_Gate_Off_Event(ADSR_t * p_ADSR);

#endif
