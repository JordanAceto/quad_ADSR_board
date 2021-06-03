/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   input_processing.h provides an interface for using various input
--|   processing helper functions.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

#ifndef INPUT_PROCESSING_H_INCLUDED
#define INPUT_PROCESSING_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    poll_encoders

Function Description:
    Poll the four encoders and select the active encoder to the last
    encoder to be turned.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void poll_encoders(void);

/*------------------------------------------------------------------------------
Function Name:
    poll_pushbuttons

Function Description:
    Poll the four push-buttons and set the active ADSR to the last button
    clicked, and set the ADSR mode to lock-to-master if there is a long
    button press.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void poll_pushbuttons(void);

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
    poll_gate_and_trigger_inputs

Function Description:
    Poll the gate and trigger inputs and deliver gate on/off messages to the
    ADSRs.

Parameters:
    None.

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void poll_gate_and_trigger_inputs(void);

/*------------------------------------------------------------------------------
Function Name:
    set_encoders_to_active_adsr_values

Function Description:
    Set the encoders to the values held by active ADSR and update the cached
    encoder settings.

Parameters:
    None

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void set_encoders_to_active_adsr_values(void);

#endif
