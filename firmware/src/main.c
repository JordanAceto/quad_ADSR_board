
#include "input_processing.h"
#include "interrupts.h"
#include "output_processing.h"

int main(void)
{
    while (1)
    {
        // TIM6 triggers the fast interrupt for timing critical tasks
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM6))
        {
            interrupt_clear_flag(INTERRUPT_FLAG_TIM6);

            poll_gate_and_trigger_inputs();
            tick_ADSRs();
            update_MCP4822_DACs();
        }

        // TIM7 triggers the slower interrupt for updating the UI
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM7))
        {
            interrupt_clear_flag(INTERRUPT_FLAG_TIM7);

            poll_encoders();
            poll_pushbuttons();
            update_ADSR_inputs();
            update_seven_segment_display();
            update_bicolor_LEDs();
        }
    }

    // never reached
    return 0;
}
