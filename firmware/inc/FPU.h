/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   FPU.h provides the interface for enabling the Floating Point Unit.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   PM0214 Programming manual page 253
--|
--|----------------------------------------------------------------------------|
*/

#ifndef FPU_H_INCLUDED
#define FPU_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    FPU_Init

Function Description:
    Enable the FPU.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before doing any floating point operations.
------------------------------------------------------------------------------*/
void FPU_Init(void);

#endif
