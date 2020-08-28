/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   TIM7.h provides the implementation for initializing TIM7.
--|   
--|   TIM7 sets the sample time for ...
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

void TIM7_Init(void)
{
    // enable clock control for timer 7
    RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;

    // set the period for the TIM7 interrupt
    TIM7->PSC = 3863u;
    TIM7->ARR = 9u;

    // enable update interrupts
    TIM7->DIER |= TIM_DIER_UIE;

    // enable the timer
    TIM7->CR1 |= TIM_CR1_CEN;
}