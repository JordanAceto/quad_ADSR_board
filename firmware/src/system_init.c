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

#include "ADSR.h"
#include "encoders.h"
#include "FPU.h"
#include "global_data.h"
#include "GPIO.h"
#include "I2C2.h"
#include "input_processing.h"
#include "interrupts.h"
#include "RCC.h"
#include "SPI3.h"
#include "stm32f4xx.h"
#include "SysTick.h"
#include "TIM6.h"
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
uint32_t SystemCoreClock = 50E6;

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SystemInit(void)
{
    __disable_irq();

    FPU_Init();
    RCC_Init();
    SysTick_Init();
    I2C2_Init();
    GPIO_Init();
    SPI3_Init();
    TIM6_Init();
    TIM7_Init();
    encoders_Init();
    interrupts_Init();

    for (int i = 0; i < NUM_ADSRs; ++i)
    {
        Initialize_ADSR(&adsr[i], ADSR_SAMPLE_RATE_Hz);
    }

    set_encoders_to_active_adsr_values();

    __enable_irq();
}
