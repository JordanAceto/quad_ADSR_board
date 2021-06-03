/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the interface for the interrupts used by the system.
--|   
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef INTERRUPTS_H_INCLUDED
#define INTERRUPTS_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include <stdbool.h>

/*
--|----------------------------------------------------------------------------|
--| PUBLIC TYPES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: Interrupt_Flag_t
--| DESCRIPTION: Enumeration of the interrupt flags used by the system
*/
typedef enum Interrupt_Flag_Type
{
    INTERRUPT_FLAG_TIM6 = 0u,
    INTERRUPT_FLAG_TIM7,
    
    NUM_INTERRUPT_FLAG_TYPES
} Interrupt_Flag_t;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    interrupts_Init

Function Description:
    Perform initialization of the interrupts used by the system.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called as part of system initialization.
------------------------------------------------------------------------------*/
void interrupts_Init(void);

/*------------------------------------------------------------------------------
Function Name:
    interrupt_get_flag

Function Description:
    Get the status of the specified interrupt flag.

Parameters:
    flag: the flag to check

Returns:
    None

Assumptions/Limitations:
    Assumed that the flag is a member of the Interrupt_Flag_t enumeration.
------------------------------------------------------------------------------*/
bool interrupt_get_flag(Interrupt_Flag_t flag);

/*------------------------------------------------------------------------------
Function Name:
    interrupt_set_flag

Function Description:
    Set the specified interrupt flag.

Parameters:
    flag: the flag to set

Returns:
    None

Assumptions/Limitations:
    Assumed that the flag is a member of the Interrupt_Flag_t enumeration.
------------------------------------------------------------------------------*/
void interrupt_set_flag(Interrupt_Flag_t flag);

/*------------------------------------------------------------------------------
Function Name:
    interrupt_clear_flag

Function Description:
    Clear the specified interrupt flag.

Parameters:
    flag: the flag to clear

Returns:
    None

Assumptions/Limitations:
    Assumed that the flag is a member of the Interrupt_Flag_t enumeration.
------------------------------------------------------------------------------*/
void interrupt_clear_flag(Interrupt_Flag_t flag);

#endif
