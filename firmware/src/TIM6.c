/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM6.h provides the implementation for initializing TIM6.
--|   
--|   TIM6 sets the sample time for ...
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

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void TIM6_Init(void)
{
    // enable clock control for timer 6
    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

    // set the period for the TIM6 interrupt = 10kHz
    TIM6->PSC = 499u;
    TIM6->ARR = 9u;

    // enable update interrupts
    TIM6->DIER |= TIM_DIER_UIE;

    // enable the timer
    TIM6->CR1 |= TIM_CR1_CEN;
}