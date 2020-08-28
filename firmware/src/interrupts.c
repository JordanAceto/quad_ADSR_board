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

#include "GPIO.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

// note that for interrupts, higher numbers mean lower priority

/*
--| NAME: TIM3_IRQ_PRIORITY
--| DESCRIPTION: the priority of the TIM7 interrupt
--| TYPE: uint
*/
#define TIM7_IRQ_PRIORITY (0)


/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void interrupts_Init(void)
{
    // enable the TIM7 IRQ
    NVIC_SetPriority(TIM7_IRQn, TIM7_IRQ_PRIORITY);
    NVIC_EnableIRQ(TIM7_IRQn);


}

void TIM7_IRQHandler(void)
{
    // toggle the LED as a test
    STATUS_LED_GPIO_Port->ODR ^= (1u << STATUS_LED_Pin);
    
    // clear the Update Interrupt flag
    TIM7->SR &= ~TIM_SR_UIF;
}
