/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   RCC.c provides the implementation for initializing RCC.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   stm32f405 reference manual, page 150 (RCC)
--|   stm32f405 reference manual, page 73 (FLASH)
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

void RCC_Init(void)
{
    // set 2 FLASH controller wait states for 60 < HCLK <= 90
    FLASH->ACR |= FLASH_ACR_LATENCY_2WS;

    // set the clock dividers
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  // AHB:  84MHz

    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // APB1: 42MHz

    RCC->CFGR |= RCC_CFGR_PPRE2_DIV2; // APB2: 42MHz

    // enable the external 16MHz high speed clock
    RCC->CR |= RCC_CR_HSEON;

    while (!(RCC->CR & RCC_CR_HSERDY))
    {
        // wait for the external clock to be ready
    }

    // set the PLL clock source to HSE
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;

    // set the PLL divider Q to divide by 4
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLQ_3;

    // set the PLL divider M to divide by 8
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_3;

    // set the PLL multiplier N to multiply by 168
    RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_3 | RCC_PLLCFGR_PLLN_5 | RCC_PLLCFGR_PLLN_7);

    // set the PLL divider P to divide by 4
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLP_0;

    // the external 16MHz xtal is now multiplied to 84MHz [(16 / 8) * 168] / 4 = 84

    // TODO: Something is wrong though, the clock is actually more like 77.3MHz, pls investigate

    // turn on the PLL
    RCC->CR |= RCC_CR_PLLON;

    while (!(RCC->CR & RCC_CR_PLLRDY))
    {
        // wait for the PLL to lock
    }

    // select the PLL as the system clock
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL))
    {
        // wait for the PLL to be ready
    }
}
