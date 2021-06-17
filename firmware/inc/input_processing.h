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
    get_and_cache_adsr_settings_from_EEPROM

Function Description:
    Read the ADSR settings stored in the EEPROM and update the values of
    the ADSRs with those settings.

Parameters:
    None

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void get_and_cache_adsr_settings_from_EEPROM(void);

/*------------------------------------------------------------------------------
Function Name:
    store_cached_adsr_settings_in_EEPROM

Function Description:
    Store the cached ADSR settings in the EEPROM.

Parameters:
    None

Returns:
    None.

Assumptions/Limitations:
    Assumes that all initialization is complete.
------------------------------------------------------------------------------*/
void store_cached_adsr_settings_in_EEPROM(void);

/*------------------------------------------------------------------------------
Function Name:
    eeprom_save_is_pending

Function Description:
    Return true if there is new data to be written to the EEPROM, else false.

Parameters:
    None

Returns:
    None.

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
bool eeprom_save_is_pending(void);

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
