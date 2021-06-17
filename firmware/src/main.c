
#include "EEPROM_24LC32.h"
#include "global_data.h"
#include "GPIO.h"
#include "input_processing.h"
#include "interrupts.h"
#include "output_processing.h"
#include "SysTick.h"

int main(void)
{
    test_EEPROM();

    while (1)
    {
        // TIM6 triggers the fast interrupt for timing critical tasks
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM6))
        {
            poll_gate_and_trigger_inputs();
            tick_ADSRs();
            update_MCP4822_DACs();
        }

        // TIM7 triggers the slower interrupt for updating the UI
        if (interrupt_get_flag(INTERRUPT_FLAG_TIM7))
        {
            poll_encoders();
            poll_pushbuttons();
            update_ADSR_inputs();
            update_seven_segment_display();
            update_bicolor_LEDs();
        }

        // write settings to the EEPROM periodically if the settings have changed
        if (SysTick_Poll_Periodic_Timer(&EEPROM_periodic_timer) && eeprom_save_is_pending())
        {
            store_cached_adsr_settings_in_EEPROM();
        }
    }

    // never reached
    return 0;
}
