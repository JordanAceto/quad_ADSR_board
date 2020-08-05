EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 10
Title "Quad ADSR"
Date "2020-07-31"
Rev "0"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
$Comp
L Display_Character:HDSP-7503 U?
U 1 1 5E60FEB8
P 2200 4000
AR Path="/5E60FEB8" Ref="U?"  Part="1" 
AR Path="/5E60A7A1/5E60FEB8" Ref="U1"  Part="1" 
F 0 "U1" H 2200 4667 50  0000 C CNN
F 1 "HDSP-7503" H 2200 4576 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 2200 3450 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 1800 4550 50  0001 C CNN
	1    2200 4000
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7503 U?
U 1 1 5E60FEBE
P 4700 4000
AR Path="/5E60FEBE" Ref="U?"  Part="1" 
AR Path="/5E60A7A1/5E60FEBE" Ref="U3"  Part="1" 
F 0 "U3" H 4700 4667 50  0000 C CNN
F 1 "HDSP-7503" H 4700 4576 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 4700 3450 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 4300 4550 50  0001 C CNN
	1    4700 4000
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7503 U?
U 1 1 5E60FEC4
P 7200 4000
AR Path="/5E60FEC4" Ref="U?"  Part="1" 
AR Path="/5E60A7A1/5E60FEC4" Ref="U4"  Part="1" 
F 0 "U4" H 7200 4667 50  0000 C CNN
F 1 "HDSP-7503" H 7200 4576 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 7200 3450 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 6800 4550 50  0001 C CNN
	1    7200 4000
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:HDSP-7503 U?
U 1 1 5E60FECA
P 9700 4000
AR Path="/5E60FECA" Ref="U?"  Part="1" 
AR Path="/5E60A7A1/5E60FECA" Ref="U5"  Part="1" 
F 0 "U5" H 9700 4667 50  0000 C CNN
F 1 "HDSP-7503" H 9700 4576 50  0000 C CNN
F 2 "Display_7Segment:HDSP-A151" H 9700 3450 50  0001 C CNN
F 3 "https://docs.broadcom.com/docs/AV02-2553EN" H 9300 4550 50  0001 C CNN
	1    9700 4000
	1    0    0    -1  
$EndComp
Text HLabel 1950 5000 0    50   Input ~ 0
digit_1_in
Text HLabel 4450 4950 0    50   Input ~ 0
digit_2_in
Text HLabel 7000 5000 0    50   Input ~ 0
digit_3_in
Text HLabel 9500 4950 0    50   Input ~ 0
digit_4_in
$Comp
L Transistor_BJT:MMBT3904 Q1
U 1 1 5E56B1A1
P 2600 5000
F 0 "Q1" H 2791 5046 50  0000 L CNN
F 1 "MMBT3904" H 2791 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2800 4925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 2600 5000 50  0001 L CNN
	1    2600 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R25
U 1 1 5E56B97D
P 2100 5000
F 0 "R25" V 2000 5000 50  0000 C CNN
F 1 "10k" V 2100 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2030 5000 50  0001 C CNN
F 3 "~" H 2100 5000 50  0001 C CNN
	1    2100 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 5000 2400 5000
$Comp
L power:GND #PWR025
U 1 1 5E56EE9F
P 2700 5300
F 0 "#PWR025" H 2700 5050 50  0001 C CNN
F 1 "GND" H 2705 5127 50  0000 C CNN
F 2 "" H 2700 5300 50  0001 C CNN
F 3 "" H 2700 5300 50  0001 C CNN
	1    2700 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 5300 2700 5200
$Comp
L Transistor_BJT:MMBT3904 Q2
U 1 1 5E571013
P 5100 4950
F 0 "Q2" H 5291 4996 50  0000 L CNN
F 1 "MMBT3904" H 5291 4905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5300 4875 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 5100 4950 50  0001 L CNN
	1    5100 4950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R34
U 1 1 5E571019
P 4600 4950
F 0 "R34" V 4500 4950 50  0000 C CNN
F 1 "10k" V 4600 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 4950 50  0001 C CNN
F 3 "~" H 4600 4950 50  0001 C CNN
	1    4600 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 4950 4900 4950
$Comp
L power:GND #PWR026
U 1 1 5E571020
P 5200 5250
F 0 "#PWR026" H 5200 5000 50  0001 C CNN
F 1 "GND" H 5205 5077 50  0000 C CNN
F 2 "" H 5200 5250 50  0001 C CNN
F 3 "" H 5200 5250 50  0001 C CNN
	1    5200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 5250 5200 5150
$Comp
L Transistor_BJT:MMBT3904 Q3
U 1 1 5E572472
P 7650 5000
F 0 "Q3" H 7841 5046 50  0000 L CNN
F 1 "MMBT3904" H 7841 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7850 4925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 7650 5000 50  0001 L CNN
	1    7650 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 5000 7450 5000
$Comp
L power:GND #PWR027
U 1 1 5E57247F
P 7750 5300
F 0 "#PWR027" H 7750 5050 50  0001 C CNN
F 1 "GND" H 7755 5127 50  0000 C CNN
F 2 "" H 7750 5300 50  0001 C CNN
F 3 "" H 7750 5300 50  0001 C CNN
	1    7750 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 5300 7750 5200
$Comp
L Transistor_BJT:MMBT3904 Q4
U 1 1 5E5731E0
P 10150 4950
F 0 "Q4" H 10341 4996 50  0000 L CNN
F 1 "MMBT3904" H 10341 4905 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10350 4875 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 10150 4950 50  0001 L CNN
	1    10150 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 4950 9950 4950
$Comp
L power:GND #PWR028
U 1 1 5E5731ED
P 10250 5250
F 0 "#PWR028" H 10250 5000 50  0001 C CNN
F 1 "GND" H 10255 5077 50  0000 C CNN
F 2 "" H 10250 5250 50  0001 C CNN
F 3 "" H 10250 5250 50  0001 C CNN
	1    10250 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 5250 10250 5150
$Comp
L 74xx:74HC595 U2
U 1 1 5E797846
P 2300 2000
F 0 "U2" H 2550 2700 50  0000 C CNN
F 1 "74HC595" H 2550 2600 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 2300 2000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2300 2000 50  0001 C CNN
	1    2300 2000
	1    0    0    -1  
$EndComp
Text HLabel 1900 1600 0    50   Input ~ 0
spi_data_in
Text HLabel 1900 1800 0    50   Input ~ 0
spi_clk_in
$Comp
L power:+3.3V #PWR023
U 1 1 5E7CF77E
P 2300 1400
F 0 "#PWR023" H 2300 1250 50  0001 C CNN
F 1 "+3.3V" H 2315 1573 50  0000 C CNN
F 2 "" H 2300 1400 50  0001 C CNN
F 3 "" H 2300 1400 50  0001 C CNN
	1    2300 1400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5E7D0042
P 2300 2700
F 0 "#PWR024" H 2300 2450 50  0001 C CNN
F 1 "GND" H 2305 2527 50  0000 C CNN
F 2 "" H 2300 2700 50  0001 C CNN
F 3 "" H 2300 2700 50  0001 C CNN
	1    2300 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R26
U 1 1 5E7D1F34
P 3050 1600
F 0 "R26" V 3000 1400 50  0000 C CNN
F 1 "390" V 3050 1600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1600 50  0001 C CNN
F 3 "~" H 3050 1600 50  0001 C CNN
	1    3050 1600
	0    1    1    0   
$EndComp
$Comp
L Device:R R27
U 1 1 5E7D2E3D
P 3050 1700
F 0 "R27" V 3000 1500 50  0000 C CNN
F 1 "390" V 3050 1700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1700 50  0001 C CNN
F 3 "~" H 3050 1700 50  0001 C CNN
	1    3050 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R R28
U 1 1 5E7D455F
P 3050 1800
F 0 "R28" V 3000 1600 50  0000 C CNN
F 1 "390" V 3050 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1800 50  0001 C CNN
F 3 "~" H 3050 1800 50  0001 C CNN
	1    3050 1800
	0    1    1    0   
$EndComp
$Comp
L Device:R R29
U 1 1 5E7D4838
P 3050 1900
F 0 "R29" V 3000 1700 50  0000 C CNN
F 1 "390" V 3050 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 1900 50  0001 C CNN
F 3 "~" H 3050 1900 50  0001 C CNN
	1    3050 1900
	0    1    1    0   
$EndComp
$Comp
L Device:R R30
U 1 1 5E7D4A9A
P 3050 2000
F 0 "R30" V 3000 1800 50  0000 C CNN
F 1 "390" V 3050 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 2000 50  0001 C CNN
F 3 "~" H 3050 2000 50  0001 C CNN
	1    3050 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R31
U 1 1 5E7D4F00
P 3050 2100
F 0 "R31" V 3000 1900 50  0000 C CNN
F 1 "390" V 3050 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 2100 50  0001 C CNN
F 3 "~" H 3050 2100 50  0001 C CNN
	1    3050 2100
	0    1    1    0   
$EndComp
$Comp
L Device:R R32
U 1 1 5E7D516B
P 3050 2200
F 0 "R32" V 3000 2000 50  0000 C CNN
F 1 "390" V 3050 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 2200 50  0001 C CNN
F 3 "~" H 3050 2200 50  0001 C CNN
	1    3050 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R R33
U 1 1 5E7D5395
P 3050 2300
F 0 "R33" V 3000 2100 50  0000 C CNN
F 1 "390" V 3050 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2980 2300 50  0001 C CNN
F 3 "~" H 3050 2300 50  0001 C CNN
	1    3050 2300
	0    1    1    0   
$EndComp
Text HLabel 1900 2100 0    50   Input ~ 0
spi_seven_segment_cs
$Comp
L power:GND #PWR022
U 1 1 5E80631C
P 1900 2200
F 0 "#PWR022" H 1900 1950 50  0001 C CNN
F 1 "GND" V 1905 2072 50  0000 R CNN
F 2 "" H 1900 2200 50  0001 C CNN
F 3 "" H 1900 2200 50  0001 C CNN
	1    1900 2200
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR021
U 1 1 5E806891
P 1900 1900
F 0 "#PWR021" H 1900 1750 50  0001 C CNN
F 1 "+3.3V" V 1915 2028 50  0000 L CNN
F 2 "" H 1900 1900 50  0001 C CNN
F 3 "" H 1900 1900 50  0001 C CNN
	1    1900 1900
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2900 1600 2700 1600
Wire Wire Line
	2700 1700 2900 1700
Wire Wire Line
	2900 1800 2700 1800
Wire Wire Line
	2700 1900 2900 1900
Wire Wire Line
	2900 2000 2700 2000
Wire Wire Line
	2700 2100 2900 2100
Wire Wire Line
	2900 2200 2700 2200
Wire Wire Line
	2700 2300 2900 2300
Wire Wire Line
	2700 4800 2700 4400
Wire Wire Line
	2700 4300 2500 4300
Wire Wire Line
	2500 4400 2700 4400
Connection ~ 2700 4400
Wire Wire Line
	2700 4400 2700 4300
Wire Wire Line
	5200 4750 5200 4400
Wire Wire Line
	5200 4300 5000 4300
Wire Wire Line
	5000 4400 5200 4400
Connection ~ 5200 4400
Wire Wire Line
	5200 4400 5200 4300
Wire Wire Line
	7750 4800 7750 4400
Wire Wire Line
	7750 4300 7500 4300
Wire Wire Line
	7500 4400 7750 4400
Connection ~ 7750 4400
Wire Wire Line
	7750 4400 7750 4300
Wire Wire Line
	10250 4750 10250 4400
Wire Wire Line
	10250 4300 10000 4300
Wire Wire Line
	10000 4400 10250 4400
Connection ~ 10250 4400
Wire Wire Line
	10250 4400 10250 4300
Text Label 3200 2300 0    50   ~ 0
segment_D
Text Label 3200 2200 0    50   ~ 0
segment_E
Text Label 3200 2100 0    50   ~ 0
segment_DP
Text Label 3200 2000 0    50   ~ 0
segment_G
Text Label 3200 1900 0    50   ~ 0
segment_C
Text Label 3200 1800 0    50   ~ 0
segment_F
Text Label 3200 1700 0    50   ~ 0
segment_B
Text Label 3200 1600 0    50   ~ 0
segment_A
Text Label 1900 4000 2    50   ~ 0
segment_D
Text Label 1900 4100 2    50   ~ 0
segment_E
Text Label 1900 4400 2    50   ~ 0
segment_DP
Text Label 1900 4300 2    50   ~ 0
segment_G
Text Label 1900 3900 2    50   ~ 0
segment_C
Text Label 1900 4200 2    50   ~ 0
segment_F
Text Label 1900 3800 2    50   ~ 0
segment_B
Text Label 1900 3700 2    50   ~ 0
segment_A
Text Label 4400 4000 2    50   ~ 0
segment_D
Text Label 4400 4100 2    50   ~ 0
segment_E
Text Label 4400 4400 2    50   ~ 0
segment_DP
Text Label 4400 4300 2    50   ~ 0
segment_G
Text Label 4400 3900 2    50   ~ 0
segment_C
Text Label 4400 4200 2    50   ~ 0
segment_F
Text Label 4400 3800 2    50   ~ 0
segment_B
Text Label 4400 3700 2    50   ~ 0
segment_A
Text Label 6900 4000 2    50   ~ 0
segment_D
Text Label 6900 4100 2    50   ~ 0
segment_E
Text Label 6900 4400 2    50   ~ 0
segment_DP
Text Label 6900 4300 2    50   ~ 0
segment_G
Text Label 6900 3900 2    50   ~ 0
segment_C
Text Label 6900 4200 2    50   ~ 0
segment_F
Text Label 6900 3800 2    50   ~ 0
segment_B
Text Label 6900 3700 2    50   ~ 0
segment_A
Text Label 9400 4000 2    50   ~ 0
segment_D
Text Label 9400 4100 2    50   ~ 0
segment_E
Text Label 9400 4400 2    50   ~ 0
segment_DP
Text Label 9400 4300 2    50   ~ 0
segment_G
Text Label 9400 3900 2    50   ~ 0
segment_C
Text Label 9400 4200 2    50   ~ 0
segment_F
Text Label 9400 3800 2    50   ~ 0
segment_B
Text Label 9400 3700 2    50   ~ 0
segment_A
NoConn ~ 2700 2500
$Comp
L Device:R R36
U 1 1 5E5731E6
P 9650 4950
F 0 "R36" V 9550 4950 50  0000 C CNN
F 1 "10k" V 9650 4950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9580 4950 50  0001 C CNN
F 3 "~" H 9650 4950 50  0001 C CNN
	1    9650 4950
	0    1    1    0   
$EndComp
$Comp
L Device:R R35
U 1 1 5E572478
P 7150 5000
F 0 "R35" V 7050 5000 50  0000 C CNN
F 1 "10k" V 7150 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7080 5000 50  0001 C CNN
F 3 "~" H 7150 5000 50  0001 C CNN
	1    7150 5000
	0    1    1    0   
$EndComp
$EndSCHEMATC
