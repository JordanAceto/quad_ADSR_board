/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM7.h provides the implementation for initializing TIM7.
--|
--|   TIM7 is configured as a periodic timer that sets the sample time for the
--|   low priority and relatively slow tasks like updating the UI.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   STM32F4xx Reference Manual, page 696 (Basic Timers)
--|
--|----------------------------------------------------------------------------|
*/


/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "RCC.h"
#include "stm32f4xx.h"
#include "TIM7.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void TIM7_Init(void)
{
    // enable clock control for timer 7
    RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;

    // set the frequency to the desired value
    TIM7->PSC = 100u - 1u;
    TIM7->ARR = ((SYSTEM_CORE_CLOCK / 100u) / TIM7_FREQUENCY_Hz)  - 1u;

    // enable update interrupts
    TIM7->DIER |= TIM_DIER_UIE;

    // enable the timer
    TIM7->CR1 |= TIM_CR1_CEN;
}