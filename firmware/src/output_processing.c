/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   output_processing.c provides the implementation for using various output
--|   processing helper functions.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   None.
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "bicolor_LED.h"
#include "global_data.h"
#include "GPIO.h"
#include "MCP4822.h"
#include "Seven_Segment.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void tick_ADSRs(void)
{
    for (int i = 0; i < NUM_ADSRs; ++i)
    {
        ADSR_Tick(&adsr[i]);
    }
}

void update_seven_segment_display(void)
{
    if (active_encoder == ADSR_INPUT_TYPE_SUSTAIN_LEVEL_percent_x_10)
    {
        seven_segment_update_S_param(adsr[active_adsr].input[active_encoder]);
    }
    else // it is Attack, Decay, or Release
    {
        seven_segment_update_ADR_param(adsr[active_adsr].input[active_encoder]);
    }
}

void update_bicolor_LEDs(void)
{
    bicolor_LED_show_active_ADSR(active_adsr, adsr_mode);
}

void update_MCP4822_DACs(void)
{
    // update the 12-bit MCP4822 SPI DACs with the upper 12 bits of the ADSRs
    MCP4822_Write(SPI3_DAC1_CS_GPIO_Port, SPI3_DAC1_CS_Pin, MCP4822_CHANNEL_B, MCP4822_GAIN_1x, adsr[0].current_value >> 20);
    MCP4822_Write(SPI3_DAC1_CS_GPIO_Port, SPI3_DAC1_CS_Pin, MCP4822_CHANNEL_A, MCP4822_GAIN_1x, adsr[1].current_value >> 20);
    MCP4822_Write(SPI3_DAC2_CS_GPIO_Port, SPI3_DAC2_CS_Pin, MCP4822_CHANNEL_B, MCP4822_GAIN_1x, adsr[2].current_value >> 20);
    MCP4822_Write(SPI3_DAC2_CS_GPIO_Port, SPI3_DAC2_CS_Pin, MCP4822_CHANNEL_A, MCP4822_GAIN_1x, adsr[3].current_value >> 20);
}
