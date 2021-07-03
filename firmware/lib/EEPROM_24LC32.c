/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   EEPROIM_24LC32.c provides the implementation for using the EEPROM
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
#include "GPIO.h"
#include "I2C2.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void EEPROM_24LC32_write(uint16_t mem_addr, uint8_t* in_buff, uint16_t num_bytes)
{
    I2C2_memory_write(EEPROM_DEVICE_ADDRESS, mem_addr, in_buff, num_bytes);
}

void EEPROM_24LC32_read(uint16_t mem_addr, uint8_t* out_buff, uint16_t num_bytes)
{
    I2C2_memory_read(EEPROM_DEVICE_ADDRESS, mem_addr, out_buff, num_bytes);
}

void test_EEPROM(void)
{
    #define N_ROWS (4)
    #define N_COLS (4)

    uint32_t wmsg[N_ROWS][N_COLS] = 
    { 
        {
            0, 1, 2, 3
        },

        {
            4, 5, 6, 7
        },

        {
            8, 9, 10, 11
        },

        {
            12, 13, 14, 15
        }
    };

    uint32_t rmsg[N_ROWS][N_COLS];

    const uint16_t msg_len = N_ROWS * N_COLS;

    const uint16_t msg_len_bytes = msg_len * 4;

    const uint16_t mem_addr = 64;

    for (int i = 0; i < N_ROWS; i++)
    {
        EEPROM_24LC32_write(mem_addr + (16*i), (uint8_t*)wmsg[i], msg_len_bytes/N_ROWS);
    }

    for (int i = 0; i < N_ROWS; i++)
    {
        EEPROM_24LC32_read(mem_addr + (16*i), (uint8_t*)rmsg[i], msg_len_bytes/N_ROWS);
    }

    bool its_a_match = true;

    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            if (wmsg[i][j] != rmsg[i][j])
            {
                its_a_match = false;
            }
        }
    }

    const uint32_t led_blink_period_mSec = its_a_match ? 100 : 2000;
    const uint32_t start_time = SysTick_Get_mSec();
    const uint32_t length_of_demo_mSec = 5000;

    while (SysTick_Get_mSec() < (start_time + length_of_demo_mSec))
    {
        STATUS_LED_GPIO_Port->ODR ^= 1u << STATUS_LED_Pin;
        SysTick_Delay_mSec(led_blink_period_mSec);
    }
}