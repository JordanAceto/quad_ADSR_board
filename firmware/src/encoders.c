/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   encoders.c provides the implementation for initializing and scaling the
--|   four encoders used by he system.
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

#include "global_data.h"
#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void encoders_Init(void)
{
    // enable clock control for the timers used as encoders
    RCC->APB1ENR |= (RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM4EN);
    RCC->APB2ENR |= (RCC_APB2ENR_TIM1EN | RCC_APB2ENR_TIM8EN);

    // set the four hardware timers to encoder mode
    for (int i = 0; i < NUM_ADSR_INPUT_TYPES; ++i)
    {
        // set the auto-reload register to a high value that it will never run into
        p_encoder[i]->ARR = UINT16_MAX;

        // set encoder mode to count on T1 and T2 edges
        p_encoder[i]->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;

        // config CC1 channel as input mapped to TI1
        p_encoder[i]->CCMR1 |= TIM_CCMR1_CC1S_0;

        // config CC2 channel as input mapped to TI2
        p_encoder[i]->CCMR1 |= TIM_CCMR1_CC2S_0;

        // invert an edge so that the encoders count correctly with the pcb layout
        p_encoder[i]->CCER |= (TIM_CCER_CC1P);

        // enable the encoder timer
        p_encoder[i]->CR1 |= TIM_CR1_CEN;
    }
}

uint32_t encoder_count_to_ADR_param(TIM_TypeDef * tim_x)
{
    // 16 bit signed raw reading makes it possible to clamp the timer
    int16_t raw_encoder_reading = tim_x->CNT;

    // 32 bit unsigned return value in the range [1, 60000]
    uint32_t retval;

    // clamp the encoder reading and the hardware timer to the low bound
    if (raw_encoder_reading < 1)
    {
        raw_encoder_reading = 1;
        tim_x->CNT = 1;
    }

    // clamp the encoder reading and the hardware timer to the high bound
    if (900 < raw_encoder_reading)
    {
        raw_encoder_reading = 900;
        tim_x->CNT = 900;
    }

    // scale the encoder according to the piecewise linear segments
    if (raw_encoder_reading <= 50) // 0.001 seconds to 0.050 seconds, 1 mSec steps
    {
        retval = raw_encoder_reading;
    }
    else if (raw_encoder_reading <= 240) // 0.055 seconds to 1.000 seconds, 5 mSec steps
    {
        retval = raw_encoder_reading * 5 - 200;
    }
    else if (raw_encoder_reading <= 440) // 1.010 seconds to 3.000 seconds, 10 mSec steps
    {
        retval = raw_encoder_reading * 10 - 1400;
    }
    else if (raw_encoder_reading <= 580) // 3.050 seconds to 10.00 seconds, 50 mSec steps
    {
        retval = raw_encoder_reading * 50 - 19000;
    }
    else if (raw_encoder_reading <= 780) // 10.10 seconds to 30.00 seconds, 100 mSec steps
    {
        retval = raw_encoder_reading * 100 - 48000;
    }
    else if (raw_encoder_reading <= 900) // 30.25 seconds to 60.00 seconds, 250 mSec steps
    {
        retval = raw_encoder_reading * 250 - 165000;
    }

    return retval;
}

uint32_t encoder_count_to_S_param(TIM_TypeDef * tim_x)
{
    // 16 bit signed raw reading makes it possible to clamp the timer
    int16_t raw_encoder_reading = tim_x->CNT;

    // 32 bit unsigned return value, range is [0, 1000]
    uint32_t retval;

    // clamp the encoder reading and the hardware timer to the low bound
    if (raw_encoder_reading <= 0)
    {
        raw_encoder_reading = 0;
        tim_x->CNT = 0;
    }

    // clamp the encoder reading and the hardware timer to the high bound
    if (1000 <= raw_encoder_reading)
    {
        raw_encoder_reading = 1000;
        tim_x->CNT = 1000;
    }

    retval = raw_encoder_reading;

    return retval;
}

void ADR_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t ADR_param)
{
    if (ADR_param <= 50)
    {
        tim_x->CNT = ADR_param;
    }
    else if (ADR_param <= 1000)
    {
        tim_x->CNT = (ADR_param + 200) / 5;
    }
    else if (ADR_param <= 3000)
    {
        tim_x->CNT = (ADR_param + 1400) / 10;
    }
    else if (ADR_param <= 10000)
    {
        tim_x->CNT = (ADR_param + 19000) / 50;
    }
    else if (ADR_param <= 30000)
    {
        tim_x->CNT = (ADR_param + 48000) / 100;
    }
    else if (ADR_param <= 60000)
    {
        tim_x->CNT = (ADR_param + 165000) / 250;
    }
}

void S_param_to_encoder_count(TIM_TypeDef * tim_x, uint32_t S_param)
{
    tim_x->CNT = S_param;
}
