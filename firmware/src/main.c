

#include "Discrete_Input.h"
#include "GPIO.h"
#include "MCP4822.h"
#include "SPI3.h"
#include "stm32f4xx.h"

void delay(uint32_t ticks);

int main(void)
{

    while (1)
    {
        // right now just demo a few features so I can verify an upload
        delay(5000);
        STATUS_LED_GPIO_Port->ODR ^= (1u << STATUS_LED_Pin);

        MCP4822_Write(SPI3_DAC2_CS_GPIO_Port, SPI3_DAC2_CS_Pin, MCP4822_CHANNEL_A, MCP4822_GAIN_1x, 0x0ABCu);
    }

    return 0;
}

void delay(uint32_t ticks)
{
    while(ticks)
    {
        ticks -= 1;
    }
}