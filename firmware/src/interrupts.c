/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   interrupts.h provides the implementation for the interrupts used by the 
--|   system.
--|   
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "interrupts.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

// note that for interrupts, higher numbers mean lower priority

/*
--| NAME: TIM6_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM6 interrupt
--| TYPE: uint
*/
#define TIM6_IRQ_PRIORITY (0)

/*
--| NAME: TIM6_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM7 interrupt
--| TYPE: uint
*/
#define TIM7_IRQ_PRIORITY (1)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: flags
--| DESCRIPTION: the interrupt flags used by the system
--| TYPE: bool
*/
static bool flags[NUM_INTERRUPT_FLAG_TYPES];

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    TIM6_DAC_IRQHandler

Function Description:
    IRQ handler for the TIM6 interrupt.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Called automatically, do not call this function.
------------------------------------------------------------------------------*/
void TIM6_DAC_IRQHandler(void);

/*------------------------------------------------------------------------------
Function Name:
    TIM7_IRQHandler

Function Description:
    IRQ handler for the TIM7 interrupt.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Called automatically, do not call this function.
------------------------------------------------------------------------------*/
void TIM7_IRQHandler(void);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void interrupts_Init(void)
{
    // enable the TIM6 IRQ
    NVIC_SetPriority(TIM6_DAC_IRQn, TIM6_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM6_DAC_IRQn);

    // enable the TIM7 IRQ
    NVIC_SetPriority(TIM7_IRQn, TIM7_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM7_IRQn);
}

bool interrupt_get_flag(Interrupt_Flag_t flag)
{
    return flags[flag];
}

void interrupt_set_flag(Interrupt_Flag_t flag)
{
    flags[flag] = true;
}

void interrupt_clear_flag(Interrupt_Flag_t flag)
{
    flags[flag] = false;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void TIM6_DAC_IRQHandler(void)
{
    interrupt_set_flag(INTERRUPT_FLAG_TIM6);

    // clear the Update Interrupt flag
    TIM6->SR &= ~TIM_SR_UIF;
}

void TIM7_IRQHandler(void)
{
    interrupt_set_flag(INTERRUPT_FLAG_TIM7);
    
    // clear the Update Interrupt flag
    TIM7->SR &= ~TIM_SR_UIF;
}
