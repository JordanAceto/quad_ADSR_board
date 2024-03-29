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

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void FPU_Init(void)
{
    // enable the FPU, see PM0214 page 253
    SCB->CPACR |= (0b11u << 20u) | (0b11u << 22u);
}
