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

#include "GPIO.h"

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
    set_SPI_pins_to_special_function

Function Description:
    Set the SPI SCK, MISO, and MOSI pins to special function.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_SPI_pins_to_special_function(void);

/*------------------------------------------------------------------------------
Function Name:
    set_SPI_CS_pins_to_output

Function Description:
    Set the SPI chip select pins to outputs.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_SPI_CS_pins_to_output(void);

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
    set_I2C_pins_to_special_function

Function Description:
    Set the I2C SDA and SCL pins to special function.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static void set_I2C_pins_to_special_function(void);

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
    set_SPI_pins_to_special_function();
    set_SPI_CS_pins_to_output();
    write_all_SPI_CS_pins_high();
    set_seven_seg_digit_select_pins_to_output();
    set_I2C_pins_to_special_function();
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
    // each pin in the PUPD register takes up 2 bits
    GATE_1_GPIO_Port->PUPDR |= (1u << (GATE_1_Pin << 1u));
    GATE_2_GPIO_Port->PUPDR |= (1u << (GATE_2_Pin << 1u));
    GATE_3_GPIO_Port->PUPDR |= (1u << (GATE_3_Pin << 1u));
    GATE_4_GPIO_Port->PUPDR |= (1u << (GATE_4_Pin << 1u));
    TRIG_1_GPIO_Port->PUPDR |= (1u << (TRIG_1_Pin << 1u));
    TRIG_2_GPIO_Port->PUPDR |= (1u << (TRIG_2_Pin << 1u));
    TRIG_3_GPIO_Port->PUPDR |= (1u << (TRIG_3_Pin << 1u));
    TRIG_4_GPIO_Port->PUPDR |= (1u << (TRIG_4_Pin << 1u));
}

void set_encoder_switches_to_input_pullup(void)
{
    // each pin in the PUPD register takes up 2 bits
    ENCODER_1_SWITCH_GPIO_Port->PUPDR |= (1u << (ENCODER_1_SWITCH_Pin << 1u));
    ENCODER_2_SWITCH_GPIO_Port->PUPDR |= (1u << (ENCODER_2_SWITCH_Pin << 1u));
    ENCODER_3_SWITCH_GPIO_Port->PUPDR |= (1u << (ENCODER_3_SWITCH_Pin << 1u));
    ENCODER_4_SWITCH_GPIO_Port->PUPDR |= (1u << (ENCODER_4_SWITCH_Pin << 1u));
}

void set_SPI_pins_to_special_function(void)
{
    // set SPI3 SCK PC10 as output push-pull, very high speed mode, alt fcn 6
    GPIOC->MODER   |= (GPIO_MODER_MODER10_1);
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_0 | GPIO_OSPEEDER_OSPEEDR10_1);
    GPIOC->AFR[1]  |= (GPIO_AFRH_AFSEL10_1 | GPIO_AFRH_AFSEL10_2);

    // SPI3 MISO is not used by the system

    // set SPI3 MOSI PC12 as output push-pull, very high speed mode, alt fcn 6
    GPIOC->MODER   |= (GPIO_MODER_MODER12_1);
    GPIOC->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR12_0 | GPIO_OSPEEDER_OSPEEDR12_1);
    GPIOC->AFR[1]  |= (GPIO_AFRH_AFSEL12_1 | GPIO_AFRH_AFSEL12_2);
}

void set_SPI_CS_pins_to_output(void)
{
    // each pin in the MODER register takes up 2 bits
    SPI3_DAC1_CS_GPIO_Port->MODER      |= (1u << (SPI3_DAC1_CS_Pin << 1u));

    /* 
        For the DAC2 CS pin, I accidentally put it on PB4, which is used as the
        NJTRST JTAG pin. In order to use PB4 we must first clear out the MODER
        bits for alt fcn 0 which are set automatically. After clearing out the
        GPIOB->MODER bits for PB4 we can set PB4 to be an output normally.

        If a board revision ever happens, put the DAC2 CS pin somewhere else and
        delete the code below which clears out MODER 4 in GPIOB.
    */
    GPIOB->MODER &= ~(GPIO_MODER_MODER4_Msk);
    SPI3_DAC2_CS_GPIO_Port->MODER      |= (1u << (SPI3_DAC2_CS_Pin << 1u));

    SPI3_SEVEN_SEG_CS_GPIO_Port->MODER |= (1u << (SPI3_SEVEN_SEG_CS_Pin << 1u));
    SPI3_RG_LEDS_CS_GPIO_Port->MODER   |= (1u << (SPI3_RG_LEDS_CS_Pin << 1u));
}

void write_all_SPI_CS_pins_high(void)
{
    SPI3_DAC1_CS_GPIO_Port->BSRR      = (1u << SPI3_DAC1_CS_Pin);
    SPI3_DAC2_CS_GPIO_Port->BSRR      = (1u << SPI3_DAC2_CS_Pin);
    SPI3_SEVEN_SEG_CS_GPIO_Port->BSRR = (1u << SPI3_SEVEN_SEG_CS_Pin);
    SPI3_RG_LEDS_CS_GPIO_Port->BSRR   = (1u << SPI3_RG_LEDS_CS_Pin);
}

void set_seven_seg_digit_select_pins_to_output(void)
{
    // each pin in the MODER register takes up 2 bits
    SEVEN_SEG_DIGIT_1_GPIO_Port->MODER |= (1u << (SEVEN_SEG_DIGIT_1_Pin << 1u));
    SEVEN_SEG_DIGIT_2_GPIO_Port->MODER |= (1u << (SEVEN_SEG_DIGIT_2_Pin << 1u));
    SEVEN_SEG_DIGIT_3_GPIO_Port->MODER |= (1u << (SEVEN_SEG_DIGIT_3_Pin << 1u));
    SEVEN_SEG_DIGIT_4_GPIO_Port->MODER |= (1u << (SEVEN_SEG_DIGIT_4_Pin << 1u));
}

void set_I2C_pins_to_special_function(void)
{
    // set I2C2 SCL PB10 pin as open drain, pullup, very high speed, alt fcn 4
    GPIOB->MODER   |= (GPIO_MODER_MODER10_1);
    GPIOB->OTYPER  |= (GPIO_OTYPER_OT10);
    GPIOB->PUPDR   |= (GPIO_PUPDR_PUPD10_0);
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10_0 | GPIO_OSPEEDER_OSPEEDR10_1);
    GPIOB->AFR[1]  |= (GPIO_AFRH_AFSEL10_2);

    // set I2C2 SDA PB11 as open drain, pullup, very high speed, alt fcn 4
    GPIOB->MODER   |= (GPIO_MODER_MODER11_1);
    GPIOB->OTYPER  |= (GPIO_OTYPER_OT11);
    GPIOB->PUPDR   |= (GPIO_PUPDR_PUPD11_0);
    GPIOB->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR11_0 | GPIO_OSPEEDER_OSPEEDR11_1);
    GPIOB->AFR[1]  |= (GPIO_AFRH_AFSEL11_2);
}

void set_status_LED_pin_to_output(void)
{
    // each pin in the MODER register takes up 2 bits
    STATUS_LED_GPIO_Port->MODER |= (1u << (STATUS_LED_Pin << 1u));
}