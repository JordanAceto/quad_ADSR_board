/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM6.h provides the implementation for initializing TIM6.
--|
--|   TIM6 is configured as a periodic timer that sets the sample time for the
--|   high prioritry, relatively fast-updating tasks.
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
#include "TIM6.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void TIM6_Init(void)
{
    // enable clock control for timer 6
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

    // set the frequency to the desired value
    TIM6->PSC = 100u - 1u;
    TIM6->ARR = ((SYSTEM_CORE_CLOCK / 100u) / TIM6_FREQUENCY_Hz)  - 1u;

    // enable update interrupts
    TIM6->DIER |= TIM_DIER_UIE;

    // enable the timer
    TIM6->CR1 |= TIM_CR1_CEN;
}