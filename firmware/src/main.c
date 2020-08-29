

#include "GPIO.h"
#include "SPI3.h"
#include "SysTick.h"

int main(void)
{

    while (1)
    {
        // right now just demo a few features so I can verify an upload
        
        SysTick_Delay_mSec(10);

        // STATUS_LED_GPIO_Port->ODR ^= (1u << STATUS_LED_Pin);

        SPI3_Transmit(SPI3_DAC2_CS_GPIO_Port, SPI3_DAC2_CS_Pin, 0xDEADu);
    }

    return 0;
}
