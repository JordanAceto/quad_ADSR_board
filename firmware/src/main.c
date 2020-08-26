

#include "Discrete_Input.h"
#include "MCP4822.h"
#include "SPI3.h"
#include "stm32f4xx.h"

void delay(uint32_t ticks);

int main(void)
{

    while (1)
    {

        delay(5000);
        GPIOC->ODR ^= GPIO_ODR_OD3;

        MCP4822_Write(GPIOB, 5u, MCP4822_CHANNEL_A, MCP4822_GAIN_1x, 0x0ABCu);
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