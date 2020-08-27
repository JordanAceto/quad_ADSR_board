/*
--|----------------------------------------------------------------------------|
--| FILE DESCRIPTION:
--|   Seven_Segment.c provides the implementation for the four digit seven-segment
--|   display with four decimal points used by the system.
--|
--|   The seven-segment display is used to show the value of the most recently
--|   adjusted parameter to the user. 
--|
--|   Time based parameters Attack, Decay, and Release are shown with the units 
--|   being seconds. A moving decimal point is used depending on how long the 
--|   time to be shown is.
--|
--|   The Sustain paramter is shown as a percent between 0.0% and 100.0%. For
--|   Sustain parameters the decimal point is always in the same place.
--|
--|----------------------------------------------------------------------------|
--| REFERENCES:
--|   hdsp-7503_seven_segment datasheet
--|
--|----------------------------------------------------------------------------|
*/

/*
--|----------------------------------------------------------------------------|
--| INCLUDE FILES
--|----------------------------------------------------------------------------|
*/

#include "GPIO.h"
#include "Seven_Segment.h"
#include "SPI3.h"

/*
--|----------------------------------------------------------------------------|
--| PRIVATE DEFINES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: DECIMAL_POINT_BIT_PATTERN
--| DESCRIPTION: the bit pattern for adding the decimal point to a digit
--| TYPE: uint
*/
#define DECIMAL_POINT_BIT_PATTERN (1u << 2u)

/*
--|----------------------------------------------------------------------------|
--| PRIVATE CONSTANTS
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: SEVEN_SEGMENT_NUMBERS
--| DESCRIPTION: array of bit patterns for writing numbers 0 - 9 to a HDSP-7503
--|              seven segment display via the SN74HC595
--|
--|              Array position 0 contains the pattern to write the digit 0,
--|              position 1 contains the pattern to write the digit 1, etc.
--|
--|              The bit-to-segment mapping is as follows:
--|              0 -> D, 1 -> E, 2 -> DP, 3 -> G, 4 -> C, 5 -> F, 6 -> B, 7 -> A
--|
--|              This mapping was chosen to work with the pcb layout, to make
--|              routing easy.
--|
--| TYPE: uint8_t
*/
static const uint8_t SEVEN_SEGMENT_NUMBERS[10]=
{
    0b11110011,
    0b01010000,
    0b11001011,
    0b11011001,
    0b01111000,
    0b10111001,
    0b10111011,
    0b11010000,
    0b11111011,
    0b11111001
};

/*
--| NAME: seven_segment_digit_en_port
--| DESCRIPTION: array of the seven segment digit enable ports
--| TYPE: GPIO_TypeDef *
*/
static GPIO_TypeDef * const seven_segment_digit_en_port[NUM_SEVEN_SEGMENT_DIGITS] =
{
    SEVEN_SEG_DIGIT_1_GPIO_Port,
    SEVEN_SEG_DIGIT_2_GPIO_Port,
    SEVEN_SEG_DIGIT_3_GPIO_Port,
    SEVEN_SEG_DIGIT_4_GPIO_Port
};

/*
--| NAME: seven_segment_digit_en_pin
--| DESCRIPTION: array of the seven segment digit enable pins
--| TYPE: uint16_t
*/
static const uint16_t seven_segment_digit_en_pin[NUM_SEVEN_SEGMENT_DIGITS] =
{
    SEVEN_SEG_DIGIT_1_Pin,
    SEVEN_SEG_DIGIT_2_Pin,
    SEVEN_SEG_DIGIT_3_Pin,
    SEVEN_SEG_DIGIT_4_Pin
};

/*
--|----------------------------------------------------------------------------|
--| PRIVATE VARIABLES
--|----------------------------------------------------------------------------|
*/

/*
--| NAME: illuminated_digit
--| DESCRIPTION: the seven segment digit that is currently illuminated
--| TYPE: uint8_t
*/
static uint8_t illuminated_digit = 0;

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION PROTOTYPES
--|----------------------------------------------------------------------------|
*/

/*------------------------------------------------------------------------------
Function Name:
    extract_digit

Function Description:
    Extranct a single 10's place digit from a given integer.

Parameters:
    val: the integer value that you want to extract a digit from
    digit: the 10's place of the digit you want to extract

Returns:
    uint32_t: the digit at the desired position

Assumptions/Limitations:
    None
------------------------------------------------------------------------------*/
static uint32_t extract_digit(uint32_t val, uint32_t digit);

/*
--|----------------------------------------------------------------------------|
--| PUBLIC FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

void seven_segment_update_ADR_param(uint32_t ADR_param)
{
    // turn off all the digits
    for (int i = 0; i < NUM_SEVEN_SEGMENT_DIGITS; ++i)
    {
        seven_segment_digit_en_port[i]->BSRR = (0x10000u << seven_segment_digit_en_pin[i]);
    }

    uint32_t val_of_digit_to_write = 0;

    uint8_t bit_pattern_to_write;

    if (ADR_param >= 10000) // at least 10 seconds, format as: [tens][ones].[tenths][hundredths]
    {
        ADR_param /= 10;

        val_of_digit_to_write = extract_digit(ADR_param, illuminated_digit);

        bit_pattern_to_write = SEVEN_SEGMENT_NUMBERS[val_of_digit_to_write];

        // add in the decimal point
        if (illuminated_digit == 2)
        {
            bit_pattern_to_write |= DECIMAL_POINT_BIT_PATTERN;
        }
    }
    else // less than 10 seconds, format as: [ones].[tenths][hundredths][thousansdths]
    {
        val_of_digit_to_write = extract_digit(ADR_param, illuminated_digit);

        bit_pattern_to_write = SEVEN_SEGMENT_NUMBERS[val_of_digit_to_write];

        // add in the decimal point
        if (illuminated_digit == 3)
        {
            bit_pattern_to_write |= DECIMAL_POINT_BIT_PATTERN;
        }
    }

    // write the pattern
    SPI3_Transmit(SPI3_SEVEN_SEG_CS_GPIO_Port, SPI3_SEVEN_SEG_CS_Pin, bit_pattern_to_write);

    // illuminate the active digit
    seven_segment_digit_en_port[illuminated_digit]->BSRR = (1u << seven_segment_digit_en_pin[illuminated_digit]);

    // move the illuminated digit up one space
    illuminated_digit++;
    illuminated_digit %= NUM_SEVEN_SEGMENT_DIGITS;
}

void seven_segment_update_S_param(uint32_t S_param)
{
    // turn off all the digits
    for (int i = 0; i < NUM_SEVEN_SEGMENT_DIGITS; ++i)
    {
        seven_segment_digit_en_port[i]->BSRR = (0x10000u << seven_segment_digit_en_pin[i]);
    }

    // we'll use this to only illuminate the digits with information in them
    uint32_t log_10_of_param = 0;

    uint32_t param_copy = S_param;

    while (param_copy)
    {
        param_copy /= 10;
        log_10_of_param++;
    }

    uint32_t val_of_digit_to_write = extract_digit(S_param, illuminated_digit);

    uint8_t bit_pattern_to_write = SEVEN_SEGMENT_NUMBERS[val_of_digit_to_write];

    // add in the decimal point, always at the same segment
    if (illuminated_digit == 1)
    {
        bit_pattern_to_write |= DECIMAL_POINT_BIT_PATTERN;
    }

    // write the pattern
    SPI3_Transmit(SPI3_SEVEN_SEG_CS_GPIO_Port, SPI3_SEVEN_SEG_CS_Pin, bit_pattern_to_write);

    // illuminate the active digit, but do not illuminate more than one leading zero
    if (illuminated_digit < 2 || illuminated_digit < log_10_of_param)
    {
        seven_segment_digit_en_port[illuminated_digit]->BSRR = (1u << seven_segment_digit_en_pin[illuminated_digit]);
    }

    // move the illuminated digit up one space
    illuminated_digit++;
    illuminated_digit %= NUM_SEVEN_SEGMENT_DIGITS;
}

/*
--|----------------------------------------------------------------------------|
--| PRIVATE HELPER FUNCTION DEFINITIONS
--|----------------------------------------------------------------------------|
*/

static uint32_t extract_digit(uint32_t val, uint32_t digit)
{
    // the divisor is used for stripping out the digit of interest
    uint32_t divisor = 1;

    // calculate the divisor needed to put the desired digit in the ones place
    for (int i = 0; i < digit; ++i)
    {
        divisor *= 10;
    }

    return (val / divisor) % 10;
}
