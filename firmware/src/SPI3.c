/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   SPI3.c provides the implementation for initializing and using SPI3.
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

#include "SPI3.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void SPI3_Init(void)
{
    // enable SPI3 clock control
    RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;

    // enable GPIOC clock control
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

    // set 16 bit data frame format
    SPI3->CR1 |= SPI_CR1_DFF;

    // use software slave management
    SPI3->CR1 |= SPI_CR1_SSM;

    // ignore the value of the NSS pin
    SPI3->CR1 |= SPI_CR1_SSI;

    // set SPI3 to master mode
    SPI3->CR1 |= SPI_CR1_MSTR;

    // prescaler = divide by 8
    SPI3->CR1 |= SPI_CR1_BR_1;

    // enable SPI3
    SPI3->CR1 |= SPI_CR1_SPE;

    // configure the sck and mosi pins (miso is unused)

    // set SPI3 SCK PC10 as output push-pull, very high speed mode, alt fcn 6
    GPIOC->MODER |= GPIO_MODER_MODER10_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_0 | GPIO_OSPEEDER_OSPEEDR10_1);
    GPIOC->AFR[1] |= (GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_2);

    // set SPI3 MOSI PC12 as output push-pull, very high speed mode, alt fcn 6
    GPIOC->MODER |= GPIO_MODER_MODER12_1;
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR12_0 | GPIO_OSPEEDER_OSPEEDR12_1);
    GPIOC->AFR[1] |= (GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_2);
}

void SPI3_Transmit(GPIO_TypeDef * CS_port, uint16_t CS_pin, uint32_t value)
{
    while (!(SPI3->SR & SPI_SR_TXE))
    {
        // wait for TX buffer to be empty
    }

    // set the chip select pin low
    CS_port->BSRR = (0x10000u << CS_pin);

    // write the value to the data register
    SPI3->DR = value;

    while (SPI3->SR & SPI_SR_BSY)
    {
        // wait for transmission to complete
    }

    // set the chip select pin back high
    CS_port->BSRR = (1u << CS_pin);
}