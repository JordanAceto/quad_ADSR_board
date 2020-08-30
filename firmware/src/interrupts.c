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
#include "input_processing.h"
#include "output_processing.h"
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

void TIM6_DAC_IRQHandler(void)
{
    // LED ON to time execution
    // STATUS_LED_GPIO_Port->BSRR = (1u << STATUS_LED_Pin);

    poll_gate_and_trigger_inputs();
    tick_ADSRs();
    update_MCP4822_DACs();
    
    // clear the Update Interrupt flag
    TIM6->SR &= ~TIM_SR_UIF;

    // LED OFF to mark end of ISR
    // STATUS_LED_GPIO_Port->BSRR = (0x10000u << STATUS_LED_Pin);
}

void TIM7_IRQHandler(void)
{
    // LED ON to time execution
    // STATUS_LED_GPIO_Port->BSRR = (1u << STATUS_LED_Pin);

    poll_encoders();
    poll_pushbuttons();
    update_ADSR_inputs();
    update_seven_segment_display();
    update_bicolor_LEDs();
    
    // clear the Update Interrupt flag
    TIM7->SR &= ~TIM_SR_UIF;

    // LED OFF to mark end of ISR
    // STATUS_LED_GPIO_Port->BSRR = (0x10000u << STATUS_LED_Pin);
}
