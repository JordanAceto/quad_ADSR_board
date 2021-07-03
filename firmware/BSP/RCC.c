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
    /*
    // test code to view the pll output freq on PC9

    // set MCO2 to use PLL
    RCC->CFGR |= RCC_CFGR_MCO2_0 | RCC_CFGR_MCO2_1;
    // divide MCO2 by 5
    RCC->CFGR |= RCC_CFGR_MCO2PRE_0 | RCC_CFGR_MCO2PRE_1 | RCC_CFGR_MCO2PRE_2;
    // make sure port c is enabled
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    // set PC9 to af, MCO2 output
    GPIOC->MODER |= GPIO_MODER_MODER9_1;
    */

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

    // set the PLL divider M to divide by 16
    RCC->PLLCFGR |= (16u << 0u);

    // set the PLL multiplier N to multiply by 200
    RCC->PLLCFGR |= (200u << 6u);

    // set the PLL divider P to divide by 4
    RCC->PLLCFGR |= (1u << 16u);

    // the external 16MHz xtal is now multiplied to 50MHz: [(16 / 16) * 200] / 4 = 50

    // TODO: Something is wrong, I can't get certain pll frequencies to work right
    // the above setting works, but other N, M, and P settings do not produce the
    // expected frequencies. Ex: M = 8, N = 168, P = 4 should result in 84MHz, but it doesn't?

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
