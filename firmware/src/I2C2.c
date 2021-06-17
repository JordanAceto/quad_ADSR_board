/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   I2C2.c provides the implementation for initializing and using I2C2.
--|  
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|     stm32f405 reference manual, page 839
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "global_data.h"
#include "SysTick.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: I2C2_SCL_SPEED
--| DESCRIPTION: I2C2 clock speed in Hz
--| TYPE: uint32_t
*/
#define I2C2_SCL_SPEED ((uint32_t)100E3)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    initiate_I2C2_mem_transfer

Function Description:
    Start a read or write operation, helper function to keep the main read/write
    functions uncluttered

Parameters:
    device_addr: the address of the device to initiate communication with
    mem_addr: the memory address on the device

Returns:
    None

Assumptions/Limitations:
    Assumed that I2C2 has been initialized.
------------------------------------------------------------------------------*/

static void initiate_I2C2_mem_transfer(uint16_t device_addr, uint16_t mem_addr);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void I2C2_Init(void)
{
    // enable clock control for I2C2
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;

    // reset and exit reset
    I2C2->CR1 |= I2C_CR1_SWRST;
    I2C2->CR1 &= ~I2C_CR1_SWRST;

    // set the clock frequency
    I2C2->CR2 |= (APB1_PERIPHERAL_CLOCK / 1000000u) << I2C_CR2_FREQ_Pos;

    // T_high = T_low = CCR[11:0] * Tpclk1
    // Example with 100kHz desired I2C speed and 25MHz APB1 clock: 
    //    slow speed is 100kHz, so T_high = T_low = 1/(2*100kHz) = 5*10^-6
    //    Tpclk1 = 1/APB1_clk = 1/25MHz = 40*10^-9
    //    so then CCR[11:0] = (5*10^-6)/(40*10^-9) = 125
    //    more straightforward calc is: CCR[11:0] = APB1_clk/(2*desired I2C speed)
    I2C2->CCR |= ((APB1_PERIPHERAL_CLOCK / (2u*I2C2_SCL_SPEED)) << I2C_CCR_CCR_Pos);

    // rise time
    //    TRISE[5:0] = 1000ns / Tpclk1, or 1000ns * APB1_clk
    I2C2->TRISE |= (uint32_t)(1000E-9f * APB1_PERIPHERAL_CLOCK);

    // enable I2C2
    I2C2->CR1 |= I2C_CR1_PE;
}

static void initiate_I2C2_mem_transfer(uint16_t device_addr, uint16_t mem_addr)
{
    while (I2C2->SR2 & I2C_SR2_BUSY)
    {
        // wait for I2C2 to be ready
    }

    // initiate a start condition
    I2C2->CR1 |= I2C_CR1_START;

    while (!(I2C2->SR1 & I2C_SR1_SB))
    {
        // wait for the start condition to be generated
    }

    // load the device address
    I2C2->DR = device_addr;

    while (!(I2C2->SR1 & I2C_SR1_ADDR))
    {
        // wait for the address to be received
    }

    // clear the address flag by reading SR1 and SR2
    volatile uint32_t dummy = I2C2->SR1 | I2C2->SR2;

    while (!(I2C2->SR1 & I2C_SR1_TXE))
    {
        // wait for the data register to be empty
    }

    // send the memory address high byte
    I2C2->DR = mem_addr >> 8u;

    while (!(I2C2->SR1 & I2C_SR1_TXE))
    {
        // wait for the data register to be empty
    }

    // send the memory address low byte
    I2C2->DR = mem_addr & 0xFFu;

    while (!(I2C2->SR1 & I2C_SR1_TXE))
    {
        // wait for the data register to be empty
    }
}

void I2C2_memory_write(uint16_t device_addr, uint16_t mem_addr, uint8_t* in_buff, uint16_t num_bytes)
{
    initiate_I2C2_mem_transfer(device_addr, mem_addr);

    // enable acknowledge
    I2C2->CR1 |= I2C_CR1_ACK;

    for (int i = 0; i < num_bytes; i++)
    {
        while (!(I2C2->SR1 & I2C_SR1_TXE))
        {
            // wait for the tx buffer to be empty
        }

        // write the next byte
        I2C2->DR = *in_buff;

        in_buff++;
    }

    while (!(I2C2->SR1 & I2C_SR1_BTF))
    {
        // wait for the transfer to complete
    }

    // initiate a stop condition
    I2C2->CR1 |= I2C_CR1_STOP;

    // hack to get around infinite hang when reading directly after writing
    // the system goes into an infinite loop without this delay if an EEPROM 
    // operation happens right after a call to this function.
    // TODO: investigate and fix the problem, this delay is not ideal because if
    // it happens while someone is playing there may be an annoying discontinuity.
    SysTick_Delay_mSec(5);
}

void I2C2_memory_read(uint16_t device_addr, uint16_t mem_addr, uint8_t* out_buff, uint16_t num_bytes)
{
    initiate_I2C2_mem_transfer(device_addr, mem_addr);

    // initiate a restart condition
    I2C2->CR1 |= I2C_CR1_START;

    while (!(I2C2->SR1 & I2C_SR1_SB))
    {
        // wait for the start condition to be generated
    }

    // load the device address and set the read flag
    I2C2->DR = (device_addr) | 1u;

    while (!(I2C2->SR1 & I2C_SR1_ADDR))
    {
        // wait for the address to be recieved
    }

    // clear the address flag by reading SR1 and SR2
    volatile uint32_t dummy = I2C2->SR1;
    dummy = I2C2->SR2;

    // enable acknowledge
    I2C2->CR1 |= I2C_CR1_ACK;

    while (num_bytes > 0)
    {
        if (num_bytes == 1)
        {
            // disable acknowledge
            I2C2->CR1 &= ~I2C_CR1_ACK;

            // initiate a stop condition
            I2C2->CR1 |= I2C_CR1_STOP;
        }

        while (!(I2C2->SR1 & I2C_SR1_RXNE))
        {
            // wait for the data to be ready
        }

        // read the data register
        *out_buff = I2C2->DR;
        out_buff++;

        num_bytes--;
    }
}
