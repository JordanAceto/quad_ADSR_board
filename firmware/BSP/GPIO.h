/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   GPIO.h provides the interface for initializing the GPIO pins.
--|   
--| 
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|
--|----------------------------------------------------------------------------|
*/

#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "stm32f4xx.h"

/*
--|----------------------------------------------------------------------------|
--| PUBLIC DEFINES
--|----------------------------------------------------------------------------|
*/

// defines for GPIO pins used by the system follow the pattern below:

/*
--| NAME: xxx_Port
--| DESCRIPTION: the GPIO port for a given GPIO pin
--| TYPE: GPIO_TypeDef *
*/

/*
--| NAME: xxx_Pin
--| DESCRIPTION: the pin number for a given GPIO pin
--| TYPE: uint
*/

/*
--|------------------------------------------|
--| ENCODER PINS
--|------------------------------------------|
*/

/*
--| Encoder 1
*/
#define ENCODER_1_A_GPIO_Port (GPIOA)
#define ENCODER_1_A_Pin (0u)

#define ENCODER_1_B_GPIO_Port (GPIOA)
#define ENCODER_1_B_Pin (1u)

#define ENCODER_1_SWITCH_GPIO_Port (GPIOA)
#define ENCODER_1_SWITCH_Pin (2u)

/*
--| Encoder 2
*/
#define ENCODER_2_A_GPIO_Port (GPIOC)
#define ENCODER_2_A_Pin (6u)

#define ENCODER_2_B_GPIO_Port (GPIOC)
#define ENCODER_2_B_Pin (7u)

#define ENCODER_2_SWITCH_GPIO_Port (GPIOB)
#define ENCODER_2_SWITCH_Pin (15u)

/*
--| Encoder 3
*/
#define ENCODER_3_A_GPIO_Port (GPIOA)
#define ENCODER_3_A_Pin (8u)

#define ENCODER_3_B_GPIO_Port (GPIOA)
#define ENCODER_3_B_Pin (9u)

#define ENCODER_3_SWITCH_GPIO_Port (GPIOC)
#define ENCODER_3_SWITCH_Pin (9u)

/*
--| Encoder 4
*/
#define ENCODER_4_A_GPIO_Port (GPIOB)
#define ENCODER_4_A_Pin (6u)

#define ENCODER_4_B_GPIO_Port (GPIOB)
#define ENCODER_4_B_Pin (7u)

#define ENCODER_4_SWITCH_GPIO_Port (GPIOA)
#define ENCODER_4_SWITCH_Pin (15u)

/*
--|------------------------------------------|
--| GATE PINS
--|------------------------------------------|
*/

/*
--| Gate 1
*/
#define GATE_1_GPIO_Port (GPIOA)
#define GATE_1_Pin (3u)

/*
--| Gate 2
*/
#define GATE_2_GPIO_Port (GPIOA)
#define GATE_2_Pin (5u)

/*
--| Gate 3
*/
#define GATE_3_GPIO_Port (GPIOA)
#define GATE_3_Pin (7u)

/*
--| Gate 4
*/
#define GATE_4_GPIO_Port (GPIOB)
#define GATE_4_Pin (1u)

/*
--|------------------------------------------|
--| TRIGGER PINS
--|------------------------------------------|
*/

/*
--| Trigger 1
*/
#define TRIG_1_GPIO_Port (GPIOA)
#define TRIG_1_Pin (4u)

/*
--| Trigger 2
*/
#define TRIG_2_GPIO_Port (GPIOA)
#define TRIG_2_Pin (6u)

/*
--| Trigger 3
*/
#define TRIG_3_GPIO_Port (GPIOB)
#define TRIG_3_Pin (0u)

/*
--| Trigger 4
*/
#define TRIG_4_GPIO_Port (GPIOB)
#define TRIG_4_Pin (12u)

/*
--|------------------------------------------|
--| SPI3 PINS
--|------------------------------------------|
*/

/*
--| SPI3 SCK
*/
#define SPI3_SCK_GPIO_Port (GPIOC)
#define SPI3_SCK_Pin (10u)

/*
--| SPI3 MISO
*/
#define SPI3_MISO_GPIO_Port (GPIOC)
#define SPI3_MISO_Pin (11u)

/*
--| SPI3 MOSI
*/
#define SPI3_MOSI_GPIO_Port (GPIOC)
#define SPI3_MOSI_Pin (12u)

/*
--| SPI3 DAC 1 CS
*/
#define SPI3_DAC1_CS_GPIO_Port (GPIOB)
#define SPI3_DAC1_CS_Pin (5u)

/*
--| SPI3 DAC 2 CS
*/
#define SPI3_DAC2_CS_GPIO_Port (GPIOB)
#define SPI3_DAC2_CS_Pin (4u)

/*
--| SPI3 SEVEN SEGMENT DISPLAY CS
*/
#define SPI3_SEVEN_SEG_CS_GPIO_Port (GPIOB)
#define SPI3_SEVEN_SEG_CS_Pin (13u)

/*
--| SPI3 RED/GREEN LEDS CS
*/
#define SPI3_RG_LEDS_CS_GPIO_Port (GPIOB)
#define SPI3_RG_LEDS_CS_Pin (9u)

/*
--|------------------------------------------|
--| SEVEN SEGMENT DIGIT SELECT PINS
--|------------------------------------------|
*/

/*
--| SEVEN SEGMENT DIGIT 1 SELECT
*/
#define SEVEN_SEG_DIGIT_1_GPIO_Port (GPIOC)
#define SEVEN_SEG_DIGIT_1_Pin (8u)

/*
--| SEVEN SEGMENT DIGIT 2 SELECT
*/
#define SEVEN_SEG_DIGIT_2_GPIO_Port (GPIOA)
#define SEVEN_SEG_DIGIT_2_Pin (10u)

/*
--| SEVEN SEGMENT DIGIT 3 SELECT
*/
#define SEVEN_SEG_DIGIT_3_GPIO_Port (GPIOA)
#define SEVEN_SEG_DIGIT_3_Pin (11u)

/*
--| SEVEN SEGMENT DIGIT 4 SELECT
*/
#define SEVEN_SEG_DIGIT_4_GPIO_Port (GPIOA)
#define SEVEN_SEG_DIGIT_4_Pin (12u)

/*
--|------------------------------------------|
--| I2C2 PINS
--|------------------------------------------|
*/

/*
--| I2C2 SCL
*/
#define I2C2_SCL_GPIO_Port (GPIOB)
#define I2C2_SCL_Pin (10u)

/*
--| I2C2 SDA
*/
#define I2C2_SDA_GPIO_Port (GPIOB)
#define I2C2_SDA_Pin (11u)

/*
--|------------------------------------------|
--| MISC/DEBUG PINS
--|------------------------------------------|
*/

/*
--| Status LED
*/
#define STATUS_LED_GPIO_Port (GPIOC)
#define STATUS_LED_Pin (3u)

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    GPIO_Init

Function Description:
    Perform initialization of the GPIO pins used by the system.

Parameters:
    None

Returns:
    None

Assumptions/Limitations:
    Assumed that this will be called before using any of the GPIO pins.
------------------------------------------------------------------------------*/
void GPIO_Init(void);

#endif
