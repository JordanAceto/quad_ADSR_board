EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_ST_STM32F1:STM32F103RBTx U5
U 1 1 5E566B4E
P 4600 3200
F 0 "U5" H 4050 5000 50  0000 C CNN
F 1 "STM32F103RBTx" H 5250 5000 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 4000 1500 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00161566.pdf" H 4600 3200 50  0001 C CNN
	1    4600 3200
	1    0    0    -1  
$EndComp
Text HLabel 5300 4600 2    50   Input ~ 0
gate_1_in
Text HLabel 5300 4700 2    50   Input ~ 0
trigger_1_in
Text HLabel 3900 4100 0    50   Input ~ 0
gate_2_in
Text HLabel 5300 2600 2    50   Input ~ 0
trigger_2_in
Text HLabel 5300 4400 2    50   Input ~ 0
gate_3_in
Text HLabel 5300 4300 2    50   Input ~ 0
trigger_3_in
Text HLabel 5300 1800 2    50   Input ~ 0
gate_4_in
Text HLabel 3900 3500 0    50   Input ~ 0
trigger_4_in
Text HLabel 5300 4000 2    50   Input ~ 0
encoder_1_a_in
Text HLabel 5300 3900 2    50   Input ~ 0
encoder_1_b_in
Text HLabel 5300 3800 2    50   Input ~ 0
encoder_1_sw_in
Text HLabel 5300 1700 2    50   Input ~ 0
encoder_2_a_in
Text HLabel 5300 1600 2    50   Input ~ 0
encoder_2_b_in
Text HLabel 3900 3600 0    50   Input ~ 0
encoder_2_sw_in
Text HLabel 5300 2400 2    50   Input ~ 0
encoder_3_a_in
Text HLabel 3900 4200 0    50   Input ~ 0
encoder_3_b_in
Text HLabel 5300 2500 2    50   Input ~ 0
encoder_3_sw_in
Text HLabel 3900 3900 0    50   Input ~ 0
encoder_4_a_in
Text HLabel 5300 4800 2    50   Input ~ 0
encoder_4_b_in
Text HLabel 3900 4000 0    50   Input ~ 0
encoder_4_sw_in
Text HLabel 5300 4200 2    50   Output ~ 0
digit_1_out
Text HLabel 5300 4100 2    50   Output ~ 0
digit_2_out
Text HLabel 3900 4600 0    50   Output ~ 0
digit_3_out
Text HLabel 3900 4700 0    50   Output ~ 0
digit_4_out
Text HLabel 5300 2100 2    50   Output ~ 0
spi_clk_out
Text HLabel 5300 2300 2    50   Output ~ 0
spi_data_out
Text HLabel 3900 3800 0    50   Output ~ 0
spi_cs_1_out
Text HLabel 3900 3700 0    50   Output ~ 0
spi_cs_2_out
Text HLabel 5300 3700 2    50   Output ~ 0
seven_segment_data_out
Text HLabel 3900 3100 0    50   Output ~ 0
seven_segment_clk_out
Text HLabel 5300 3300 2    50   Output ~ 0
rg_leds_data_out
Text HLabel 5300 3400 2    50   Output ~ 0
rg_leds_clk_out
Text HLabel 5300 3600 2    50   Output ~ 0
seven_segment_en_out
Text HLabel 5300 3500 2    50   Output ~ 0
rg_leds_en_out
$Comp
L power:GND #PWR0121
U 1 1 5EBB06FF
P 4400 5000
F 0 "#PWR0121" H 4400 4750 50  0001 C CNN
F 1 "GND" H 4405 4827 50  0000 C CNN
F 2 "" H 4400 5000 50  0001 C CNN
F 3 "" H 4400 5000 50  0001 C CNN
	1    4400 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0122
U 1 1 5EBB0EB7
P 4500 5000
F 0 "#PWR0122" H 4500 4750 50  0001 C CNN
F 1 "GND" H 4505 4827 50  0000 C CNN
F 2 "" H 4500 5000 50  0001 C CNN
F 3 "" H 4500 5000 50  0001 C CNN
	1    4500 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0123
U 1 1 5EBB10D9
P 4600 5000
F 0 "#PWR0123" H 4600 4750 50  0001 C CNN
F 1 "GND" H 4605 4827 50  0000 C CNN
F 2 "" H 4600 5000 50  0001 C CNN
F 3 "" H 4600 5000 50  0001 C CNN
	1    4600 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0124
U 1 1 5EBB1325
P 4700 5000
F 0 "#PWR0124" H 4700 4750 50  0001 C CNN
F 1 "GND" H 4705 4827 50  0000 C CNN
F 2 "" H 4700 5000 50  0001 C CNN
F 3 "" H 4700 5000 50  0001 C CNN
	1    4700 5000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0125
U 1 1 5EBB156D
P 4800 5000
F 0 "#PWR0125" H 4800 4750 50  0001 C CNN
F 1 "GND" H 4805 4827 50  0000 C CNN
F 2 "" H 4800 5000 50  0001 C CNN
F 3 "" H 4800 5000 50  0001 C CNN
	1    4800 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R81
U 1 1 5E58A1D9
P 7350 3550
F 0 "R81" H 7420 3596 50  0000 L CNN
F 1 "R" H 7420 3505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7280 3550 50  0001 C CNN
F 3 "~" H 7350 3550 50  0001 C CNN
	1    7350 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5E58B5BA
P 7350 3950
F 0 "D5" V 7389 3833 50  0000 R CNN
F 1 "LED" V 7298 3833 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7350 3950 50  0001 C CNN
F 3 "~" H 7350 3950 50  0001 C CNN
	1    7350 3950
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR057
U 1 1 5E58BEC1
P 7350 4200
F 0 "#PWR057" H 7350 3950 50  0001 C CNN
F 1 "GND" H 7355 4027 50  0000 C CNN
F 2 "" H 7350 4200 50  0001 C CNN
F 3 "" H 7350 4200 50  0001 C CNN
	1    7350 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4200 7350 4100
Wire Wire Line
	7350 3800 7350 3700
Text Label 5300 3100 0    50   ~ 0
status_led
Text Label 7350 3400 0    50   ~ 0
status_led
$Comp
L Device:Crystal Y1
U 1 1 5E725775
P 2850 2700
F 0 "Y1" V 2804 2831 50  0000 L CNN
F 1 "8MHz" V 2895 2831 50  0000 L CNN
F 2 "Crystal:Crystal_HC49-U_Vertical" H 2850 2700 50  0001 C CNN
F 3 "~" H 2850 2700 50  0001 C CNN
	1    2850 2700
	0    1    1    0   
$EndComp
$Comp
L Device:C C29
U 1 1 5E725E75
P 2500 2400
F 0 "C29" V 2248 2400 50  0000 C CNN
F 1 "22pF" V 2339 2400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2538 2250 50  0001 C CNN
F 3 "~" H 2500 2400 50  0001 C CNN
	1    2500 2400
	0    1    1    0   
$EndComp
$Comp
L Device:C C30
U 1 1 5E726505
P 2550 3000
F 0 "C30" V 2298 3000 50  0000 C CNN
F 1 "22pF" V 2389 3000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2588 2850 50  0001 C CNN
F 3 "~" H 2550 3000 50  0001 C CNN
	1    2550 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 2550 2850 2400
Wire Wire Line
	2850 2400 2650 2400
Wire Wire Line
	2850 2850 2850 3000
Wire Wire Line
	2850 3000 2700 3000
Wire Wire Line
	2400 3000 2200 3000
Wire Wire Line
	2200 3000 2200 2400
Wire Wire Line
	2200 2400 2350 2400
Wire Wire Line
	3900 3000 2850 3000
Connection ~ 2850 3000
Wire Wire Line
	3900 2900 3550 2900
Wire Wire Line
	3550 2900 3550 2400
Wire Wire Line
	3550 2400 2850 2400
Connection ~ 2850 2400
$Comp
L power:GND #PWR058
U 1 1 5E72B044
P 2200 3100
F 0 "#PWR058" H 2200 2850 50  0001 C CNN
F 1 "GND" H 2205 2927 50  0000 C CNN
F 2 "" H 2200 3100 50  0001 C CNN
F 3 "" H 2200 3100 50  0001 C CNN
	1    2200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3100 2200 3000
Connection ~ 2200 3000
$EndSCHEMATC
