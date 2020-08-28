/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   system_init.c provides the implementation for system initialization.
--|
--|   The SystemInit function is called from the assembly startup routine prior
--|   to branching to the main application function.
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
#include "interrupts.h"
#include "RCC.h"
#include "SPI3.h"
#include "stm32f4xx.h"
#include "TIM7.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: HSE_VALUE
--| DESCRIPTION: Default value of the External oscillator in Hz
--| TYPE: uint32_t
*/
#define HSE_VALUE ((uint32_t)16E6)

/*
--| NAME: HSE_VALUE
--| DESCRIPTION: Default value of the Internal RC oscillator in Hz
--| TYPE: uint32_t
*/
#define HSI_VALUE ((uint32_t)16E6)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: SystemCoreClock
--| DESCRIPTION: System Core Clock frequency in Hz
--| TYPE: uint32_t
*/
uint32_t SystemCoreClock = 84E6;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SystemInit(void)
{
    __disable_irq();

    RCC_Init();
    GPIO_Init();
    SPI3_Init();
    TIM7_Init();
    interrupts_Init();
    
    __enable_irq();
}
