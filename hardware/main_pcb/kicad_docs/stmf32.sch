EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 10
Title "Quad ADSR"
Date "2020-07-31"
Rev "0"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
Text HLabel 6550 2500 2    50   Input ~ 0
gate_1_in
Text HLabel 6550 2600 2    50   Input ~ 0
trigger_1_in
Text HLabel 6550 2700 2    50   Input ~ 0
gate_2_in
Text HLabel 6550 2800 2    50   Input ~ 0
trigger_2_in
Text HLabel 6550 2900 2    50   Input ~ 0
gate_3_in
Text HLabel 6550 3900 2    50   Input ~ 0
trigger_3_in
Text HLabel 6550 4000 2    50   Input ~ 0
gate_4_in
Text HLabel 6550 5100 2    50   Input ~ 0
trigger_4_in
Text HLabel 6550 2200 2    50   Input ~ 0
encoder_1_a_in
Text HLabel 6550 2300 2    50   Input ~ 0
encoder_1_b_in
Text HLabel 6550 2400 2    50   Input ~ 0
encoder_1_sw_in
Text HLabel 5150 4500 0    50   Input ~ 0
encoder_2_a_in
Text HLabel 5150 4600 0    50   Input ~ 0
encoder_2_b_in
Text HLabel 6550 5400 2    50   Input ~ 0
encoder_2_sw_in
Text HLabel 6550 3000 2    50   Input ~ 0
encoder_3_a_in
Text HLabel 6550 3100 2    50   Input ~ 0
encoder_3_b_in
Text HLabel 5150 4800 0    50   Input ~ 0
encoder_3_sw_in
Text HLabel 6550 4500 2    50   Input ~ 0
encoder_4_a_in
Text HLabel 6550 4600 2    50   Input ~ 0
encoder_4_b_in
Text HLabel 6550 3700 2    50   Input ~ 0
encoder_4_sw_in
Text HLabel 5150 4700 0    50   Output ~ 0
digit_1_out
Text HLabel 6550 3200 2    50   Output ~ 0
digit_2_out
Text HLabel 6550 3300 2    50   Output ~ 0
digit_3_out
Text HLabel 6550 3400 2    50   Output ~ 0
digit_4_out
Text HLabel 5150 4900 0    50   Output ~ 0
spi_clk_out
Text HLabel 5150 5100 0    50   Output ~ 0
spi_data_out
Text HLabel 6550 4400 2    50   Output ~ 0
spi_dac1_cs
Text HLabel 6550 4300 2    50   Output ~ 0
spi_dac2_cs
Text HLabel 6550 5200 2    50   Output ~ 0
spi_seven_segment_cs
Text HLabel 6550 4800 2    50   Output ~ 0
spi_rg_leds_cs
$Comp
L Device:R R81
U 1 1 5E58A1D9
P 1900 3550
F 0 "R81" H 1950 3550 50  0000 L CNN
F 1 "2k2" V 1900 3500 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 1830 3550 50  0001 C CNN
F 3 "~" H 1900 3550 50  0001 C CNN
	1    1900 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5E58B5BA
P 1900 3950
F 0 "D5" V 1939 3833 50  0000 R CNN
F 1 "LED" V 1848 3833 50  0000 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 1900 3950 50  0001 C CNN
F 3 "~" H 1900 3950 50  0001 C CNN
	1    1900 3950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E58BEC1
P 1900 4200
F 0 "#PWR0101" H 1900 3950 50  0001 C CNN
F 1 "GND" H 1905 4027 50  0000 C CNN
F 2 "" H 1900 4200 50  0001 C CNN
F 3 "" H 1900 4200 50  0001 C CNN
	1    1900 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 4200 1900 4100
Wire Wire Line
	1900 3800 1900 3700
Text Label 5150 4200 2    50   ~ 0
status_led
Text Label 1900 3400 0    50   ~ 0
status_led
$Comp
L MCU_ST_STM32F4:STM32F405RGTx U12
U 1 1 5ED43435
P 5850 3800
F 0 "U12" H 5200 5700 50  0000 C CNN
F 1 "STM32F405RGTx" H 5200 5600 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 5250 2100 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00037051.pdf" H 5850 3800 50  0001 C CNN
	1    5850 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2000 5650 1900
Wire Wire Line
	5650 1900 5750 1900
Wire Wire Line
	6150 1900 6150 2000
Wire Wire Line
	6050 2000 6050 1900
Connection ~ 6050 1900
Wire Wire Line
	6050 1900 6150 1900
Wire Wire Line
	5950 2000 5950 1900
Connection ~ 5950 1900
Wire Wire Line
	5950 1900 6050 1900
Wire Wire Line
	5850 2000 5850 1900
Connection ~ 5850 1900
Wire Wire Line
	5850 1900 5900 1900
Wire Wire Line
	5750 2000 5750 1900
Connection ~ 5750 1900
Wire Wire Line
	5750 1900 5850 1900
$Comp
L power:+3.3V #PWR0103
U 1 1 5ED4CB97
P 5900 1900
F 0 "#PWR0103" H 5900 1750 50  0001 C CNN
F 1 "+3.3V" H 5915 2073 50  0000 C CNN
F 2 "" H 5900 1900 50  0001 C CNN
F 3 "" H 5900 1900 50  0001 C CNN
	1    5900 1900
	1    0    0    -1  
$EndComp
Connection ~ 5900 1900
Wire Wire Line
	5900 1900 5950 1900
Wire Wire Line
	5750 5600 5750 5700
Wire Wire Line
	5750 5700 5850 5700
Wire Wire Line
	5950 5700 5950 5600
Wire Wire Line
	5850 5600 5850 5700
Connection ~ 5850 5700
Wire Wire Line
	5850 5700 5950 5700
$Comp
L power:GND #PWR0102
U 1 1 5ED4E59E
P 5850 5700
F 0 "#PWR0102" H 5850 5450 50  0001 C CNN
F 1 "GND" H 5855 5527 50  0000 C CNN
F 2 "" H 5850 5700 50  0001 C CNN
F 3 "" H 5850 5700 50  0001 C CNN
	1    5850 5700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C46
U 1 1 5ED4FA2C
P 4500 2900
F 0 "C46" H 4615 2946 50  0000 L CNN
F 1 "2.2uF" H 4615 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4538 2750 50  0001 C CNN
F 3 "~" H 4500 2900 50  0001 C CNN
	1    4500 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C45
U 1 1 5ED504BF
P 4050 2900
F 0 "C45" H 4165 2946 50  0000 L CNN
F 1 "2.2uF" H 4165 2855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4088 2750 50  0001 C CNN
F 3 "~" H 4050 2900 50  0001 C CNN
	1    4050 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR099
U 1 1 5ED5235B
P 4500 3050
F 0 "#PWR099" H 4500 2800 50  0001 C CNN
F 1 "GND" H 4505 2877 50  0000 C CNN
F 2 "" H 4500 3050 50  0001 C CNN
F 3 "" H 4500 3050 50  0001 C CNN
	1    4500 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR098
U 1 1 5ED53679
P 4050 3050
F 0 "#PWR098" H 4050 2800 50  0001 C CNN
F 1 "GND" H 4055 2877 50  0000 C CNN
F 2 "" H 4050 3050 50  0001 C CNN
F 3 "" H 4050 3050 50  0001 C CNN
	1    4050 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2750 4500 2700
Wire Wire Line
	4500 2700 5150 2700
Wire Wire Line
	4050 2750 4050 2600
Wire Wire Line
	4050 2600 5150 2600
Text Label 5150 3400 2    50   ~ 0
PHO
Text Label 5150 3500 2    50   ~ 0
PH1
$Comp
L Device:Crystal_GND24_Small HSE1
U 1 1 5ED59B3B
P 1800 1750
F 0 "HSE1" H 1450 2000 50  0000 L CNN
F 1 "16MHz" H 1400 1900 50  0000 L CNN
F 2 "Crystal:Crystal_SMD_3225-4Pin_3.2x2.5mm" H 1800 1750 50  0001 C CNN
F 3 "~" H 1800 1750 50  0001 C CNN
	1    1800 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C47
U 1 1 5ED5A9CB
P 1450 2000
F 0 "C47" H 1565 2046 50  0000 L CNN
F 1 "12pF" H 1565 1955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 1488 1850 50  0001 C CNN
F 3 "~" H 1450 2000 50  0001 C CNN
	1    1450 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C48
U 1 1 5ED5BECC
P 2200 2000
F 0 "C48" H 2315 2046 50  0000 L CNN
F 1 "12pF" H 2315 1955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0402_1005Metric" H 2238 1850 50  0001 C CNN
F 3 "~" H 2200 2000 50  0001 C CNN
	1    2200 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R84
U 1 1 5ED5D60B
P 2450 1750
F 0 "R84" V 2350 1750 50  0000 C CNN
F 1 "100" V 2450 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 2380 1750 50  0001 C CNN
F 3 "~" H 2450 1750 50  0001 C CNN
	1    2450 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	1700 1750 1450 1750
Wire Wire Line
	1450 1750 1450 1850
Wire Wire Line
	1900 1750 2200 1750
Wire Wire Line
	2200 1750 2200 1850
Wire Wire Line
	1800 1850 1800 2250
Wire Wire Line
	1800 2250 1450 2250
Wire Wire Line
	1450 2250 1450 2150
Wire Wire Line
	1800 2250 2000 2250
Wire Wire Line
	2200 2250 2200 2150
Connection ~ 1800 2250
Wire Wire Line
	1800 1650 1800 1550
Wire Wire Line
	1800 1550 2000 1550
Wire Wire Line
	2000 1550 2000 2250
Connection ~ 2000 2250
Wire Wire Line
	2000 2250 2200 2250
Wire Wire Line
	2300 1750 2200 1750
Connection ~ 2200 1750
$Comp
L power:GND #PWR0104
U 1 1 5ED65515
P 1800 2250
F 0 "#PWR0104" H 1800 2000 50  0001 C CNN
F 1 "GND" H 1805 2077 50  0000 C CNN
F 2 "" H 1800 2250 50  0001 C CNN
F 3 "" H 1800 2250 50  0001 C CNN
	1    1800 2250
	1    0    0    -1  
$EndComp
Text Label 1450 1750 2    50   ~ 0
PHO
Text Label 2600 1750 0    50   ~ 0
PH1
$Comp
L Device:R R82
U 1 1 5ED6D4A1
P 5000 2400
F 0 "R82" V 4900 2400 50  0000 C CNN
F 1 "10k" V 5000 2400 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 4930 2400 50  0001 C CNN
F 3 "~" H 5000 2400 50  0001 C CNN
	1    5000 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0100
U 1 1 5ED6E852
P 4850 2400
F 0 "#PWR0100" H 4850 2150 50  0001 C CNN
F 1 "GND" V 4855 2272 50  0000 R CNN
F 2 "" H 4850 2400 50  0001 C CNN
F 3 "" H 4850 2400 50  0001 C CNN
	1    4850 2400
	0    1    1    0   
$EndComp
$Comp
L Device:R R83
U 1 1 5EE47505
P 6700 4100
F 0 "R83" V 6700 3550 50  0000 C CNN
F 1 "10k" V 6700 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0402_1005Metric" V 6630 4100 50  0001 C CNN
F 3 "~" H 6700 4100 50  0001 C CNN
	1    6700 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5EE4750B
P 6850 4100
F 0 "#PWR0105" H 6850 3850 50  0001 C CNN
F 1 "GND" V 6855 3972 50  0000 R CNN
F 2 "" H 6850 4100 50  0001 C CNN
F 3 "" H 6850 4100 50  0001 C CNN
	1    6850 4100
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5EF04ADC
P 1950 5600
F 0 "#PWR0107" H 1950 5350 50  0001 C CNN
F 1 "GND" V 1955 5427 50  0000 C CNN
F 2 "" H 1950 5600 50  0001 C CNN
F 3 "" H 1950 5600 50  0001 C CNN
	1    1950 5600
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0106
U 1 1 5EF085E2
P 1950 5400
F 0 "#PWR0106" H 1950 5250 50  0001 C CNN
F 1 "+3.3V" V 1950 5650 50  0000 C CNN
F 2 "" H 1950 5400 50  0001 C CNN
F 3 "" H 1950 5400 50  0001 C CNN
	1    1950 5400
	0    -1   -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x06 J14
U 1 1 5EF0DEA2
P 2150 5600
F 0 "J14" H 2230 5592 50  0000 L CNN
F 1 "SWD_header" H 2230 5501 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 2150 5600 50  0001 C CNN
F 3 "~" H 2150 5600 50  0001 C CNN
	1    2150 5600
	1    0    0    -1  
$EndComp
NoConn ~ 5150 3700
NoConn ~ 5150 3900
NoConn ~ 5150 4000
NoConn ~ 5150 4100
NoConn ~ 5150 5000
NoConn ~ 5150 5300
NoConn ~ 5150 5400
Text HLabel 7850 4900 2    50   BiDi ~ 0
I2C2_SCL
Text HLabel 7850 5000 2    50   BiDi ~ 0
I2C2_SDA
Wire Wire Line
	7850 4900 7700 4900
Wire Wire Line
	6550 5000 7400 5000
$Comp
L Device:R R86
U 1 1 5EE410FF
P 7700 4650
F 0 "R86" H 7750 4650 50  0000 L CNN
F 1 "4k7" V 7700 4600 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7630 4650 50  0001 C CNN
F 3 "~" H 7700 4650 50  0001 C CNN
	1    7700 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 4800 7400 5000
Connection ~ 7400 5000
Wire Wire Line
	7400 5000 7850 5000
Wire Wire Line
	7700 4800 7700 4900
Connection ~ 7700 4900
Wire Wire Line
	7700 4900 6550 4900
Wire Wire Line
	7400 4500 7400 4400
Wire Wire Line
	7400 4400 7550 4400
Wire Wire Line
	7700 4400 7700 4500
$Comp
L power:+3.3V #PWR0122
U 1 1 5EE470C2
P 7550 4300
F 0 "#PWR0122" H 7550 4150 50  0001 C CNN
F 1 "+3.3V" H 7565 4473 50  0000 C CNN
F 2 "" H 7550 4300 50  0001 C CNN
F 3 "" H 7550 4300 50  0001 C CNN
	1    7550 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 4300 7550 4400
Connection ~ 7550 4400
Wire Wire Line
	7550 4400 7700 4400
$Comp
L Device:R R85
U 1 1 5EE40605
P 7400 4650
F 0 "R85" H 7450 4650 50  0000 L CNN
F 1 "4k7" V 7400 4600 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7330 4650 50  0001 C CNN
F 3 "~" H 7400 4650 50  0001 C CNN
	1    7400 4650
	1    0    0    -1  
$EndComp
NoConn ~ 6550 4700
NoConn ~ 6550 5300
NoConn ~ 5150 5200
NoConn ~ 5150 4300
NoConn ~ 5150 4400
Text Label 1950 5500 2    50   ~ 0
SWCLK
Text Label 6550 3600 0    50   ~ 0
SWCLK
Text Label 6550 3500 0    50   ~ 0
SWDIO
Text Label 1950 5700 2    50   ~ 0
SWDIO
Text Label 1950 5800 2    50   ~ 0
NRST
Text Label 5150 2200 2    50   ~ 0
NRST
Text Label 1950 5900 2    50   ~ 0
SWO
Text Label 6550 4200 0    50   ~ 0
SWO
$EndSCHEMATC
