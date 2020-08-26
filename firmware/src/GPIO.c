/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   GPIO.c provides the implementation for initializing the GPIO pins.
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

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    enable_GPIO_clocks

Function Description:
    Enable clock control in RCC for the GPIO ports used by the system. 

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void enable_GPIO_clocks(void);

/*------------------------------------------------------------------------------
Function Name:
    set_gate_and_trigger_inputs_to_input_pullup

Function Description:
    Set the four gate and four trigger inputs to input pullup.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_gate_and_trigger_inputs_to_input_pullup(void);

/*------------------------------------------------------------------------------
Function Name:
    set_encoder_switches_to_input_pullup

Function Description:
    Set the four encoder pushbuttons to input pullup.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_encoder_switches_to_input_pullup(void);

/*------------------------------------------------------------------------------
Function Name:
    set_SPI_CV_pins_to_output

Function Description:
    Set the SPI chip select pins to outputs.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_SPI_CV_pins_to_output(void);

/*------------------------------------------------------------------------------
Function Name:
    write_all_SPI_CS_pins_high

Function Description:
    Write the initial state of the SPI chip select pins high.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void write_all_SPI_CS_pins_high(void);

/*------------------------------------------------------------------------------
Function Name:
    set_seven_seg_digit_select_pins_to_output

Function Description:
    Set the seven segment digit select pins to outputs.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_seven_seg_digit_select_pins_to_output(void);

/*------------------------------------------------------------------------------
Function Name:
    set_status_LED_pin_to_output

Function Description:
    Set the onboard debug status LED pin to output.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_status_LED_pin_to_output(void);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void GPIO_Init(void)
{
    enable_GPIO_clocks();
    set_gate_and_trigger_inputs_to_input_pullup();
    set_encoder_switches_to_input_pullup();
    set_SPI_CV_pins_to_output();
    write_all_SPI_CS_pins_high();
    set_seven_seg_digit_select_pins_to_output();
    set_status_LED_pin_to_output();
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void enable_GPIO_clocks(void)
{
    // enable clock control for GPIO A, B, and C
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
}

void set_gate_and_trigger_inputs_to_input_pullup(void)
{
    // PA3 is gate 1
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_0;

    // PA4 is trigger 1
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD4_0;

    // PA5 is gate 2
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD5_0;

    // PA6 is trigger 2
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD6_0;

    // PA7 is gate 3
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD7_0;

    // PB0 is trigger 3
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD0_0;
    
    // PB1 is gate 5
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD1_0;
    
    // PB12 is trigger 4
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD12_0;
}

void set_encoder_switches_to_input_pullup(void)
{
    // PA2 is encoder 1 switch
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD2_0;

    // PB15 is encoder 2 switch
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD15_0;

    // PC9 is encoder 3 switch
    GPIOC->PUPDR |= GPIO_PUPDR_PUPD9_0;

    // PA15 is encoder 4 switch
    GPIOA->PUPDR |= GPIO_PUPDR_PUPD15_0;
}

void set_SPI_CV_pins_to_output(void)
{
    // PB4 is DAC2 CS
    GPIOB->MODER |= GPIO_MODER_MODER4_0;

    // PB5 is DAC1 CS
    GPIOB->MODER |= GPIO_MODER_MODER5_0;

    // PB9 is RG LED CS
    GPIOB->MODER |= GPIO_MODER_MODER9_0;

    // PB13 is seven segment display CS
    GPIOB->MODER |= GPIO_MODER_MODER13_0;
}

void write_all_SPI_CS_pins_high(void)
{
    // the SPI CS pins happen to all be in port B
    GPIOB->BSRR = (GPIO_BSRR_BS4 | GPIO_BSRR_BS5 | GPIO_BSRR_BS9 | GPIO_BSRR_BS13);
}

void set_seven_seg_digit_select_pins_to_output(void)
{
    // PC8 is digit 1 select
    GPIOC->MODER |= GPIO_MODER_MODER8_0;

    // PA10 is digit 2 select
    GPIOA->MODER |= GPIO_MODER_MODER10_0;

    // PA11 is digit 3 select
    GPIOA->MODER |= GPIO_MODER_MODER11_0;

    // PA12 is digit 4 select
    GPIOA->MODER |= GPIO_MODER_MODER12_0;
}

void set_status_LED_pin_to_output(void)
{
    // PC3 is the debug status LED
    GPIOC->MODER |= GPIO_MODER_MODER3_0;
}