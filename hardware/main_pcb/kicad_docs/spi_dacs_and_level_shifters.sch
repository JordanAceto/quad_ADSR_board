EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 10
Title "Quad ADSR"
Date "2020-07-31"
Rev "0"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
Text HLabel 6150 1350 2    50   Output ~ 0
10vp_adsr_1_out
Text HLabel 10000 1400 2    50   Output ~ 0
10vp_adsr_2_out
Text HLabel 6150 3850 2    50   Output ~ 0
10vp_adsr_3_out
Text HLabel 10000 3950 2    50   Output ~ 0
10vp_adsr_4_out
$Comp
L Amplifier_Operational:TL072 U8
U 1 1 5E583885
P 5700 1550
F 0 "U8" H 5700 1917 50  0000 C CNN
F 1 "TL072" H 5700 1826 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5700 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5700 1550 50  0001 C CNN
	1    5700 1550
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U8
U 2 1 5E584F40
P 9550 1600
F 0 "U8" H 9550 1967 50  0000 C CNN
F 1 "TL072" H 9550 1876 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 9550 1600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9550 1600 50  0001 C CNN
	2    9550 1600
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U11
U 1 1 5E585CCB
P 5700 4050
F 0 "U11" H 5700 4417 50  0000 C CNN
F 1 "TL072" H 5700 4326 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5700 4050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5700 4050 50  0001 C CNN
	1    5700 4050
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U11
U 2 1 5E587517
P 9550 4100
F 0 "U11" H 9550 4467 50  0000 C CNN
F 1 "TL072" H 9550 4376 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 9550 4100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9550 4100 50  0001 C CNN
	2    9550 4100
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U8
U 3 1 5E5889B4
P 1600 5800
F 0 "U8" H 1558 5846 50  0000 L CNN
F 1 "TL072" H 1558 5755 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 1600 5800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1600 5800 50  0001 C CNN
	3    1600 5800
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U11
U 3 1 5E589846
P 2750 5800
F 0 "U11" H 2708 5846 50  0000 L CNN
F 1 "TL072" H 2708 5755 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2750 5800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2750 5800 50  0001 C CNN
	3    2750 5800
	1    0    0    -1  
$EndComp
$Comp
L Analog_DAC:MCP4822 U9
U 1 1 5E595BF6
P 1850 1300
F 0 "U9" H 2100 1800 50  0000 C CNN
F 1 "MCP4822" H 2100 1700 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2650 1000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 2650 1000 50  0001 C CNN
	1    1850 1300
	1    0    0    -1  
$EndComp
$Comp
L Analog_DAC:MCP4822 U10
U 1 1 5E59776A
P 1850 2900
F 0 "U10" H 2100 3400 50  0000 C CNN
F 1 "MCP4822" H 2100 3300 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 2650 2600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 2650 2600 50  0001 C CNN
	1    1850 2900
	1    0    0    -1  
$EndComp
Text HLabel 1350 3000 0    50   Input ~ 0
spi_data_in
Text HLabel 1350 1500 0    50   Input ~ 0
spi_dac1_cs
Text HLabel 1350 3100 0    50   Input ~ 0
spi_dac2_cs
$Comp
L power:+3.3V #PWR084
U 1 1 5E81E69A
P 1850 900
F 0 "#PWR084" H 1850 750 50  0001 C CNN
F 1 "+3.3V" H 1865 1073 50  0000 C CNN
F 2 "" H 1850 900 50  0001 C CNN
F 3 "" H 1850 900 50  0001 C CNN
	1    1850 900 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR086
U 1 1 5E81ED2D
P 1850 2500
F 0 "#PWR086" H 1850 2350 50  0001 C CNN
F 1 "+3.3V" H 1865 2673 50  0000 C CNN
F 2 "" H 1850 2500 50  0001 C CNN
F 3 "" H 1850 2500 50  0001 C CNN
	1    1850 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR085
U 1 1 5E82068F
P 1850 1800
F 0 "#PWR085" H 1850 1550 50  0001 C CNN
F 1 "GND" H 1855 1627 50  0000 C CNN
F 2 "" H 1850 1800 50  0001 C CNN
F 3 "" H 1850 1800 50  0001 C CNN
	1    1850 1800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR087
U 1 1 5E820EAB
P 1850 3400
F 0 "#PWR087" H 1850 3150 50  0001 C CNN
F 1 "GND" H 1855 3227 50  0000 C CNN
F 2 "" H 1850 3400 50  0001 C CNN
F 3 "" H 1850 3400 50  0001 C CNN
	1    1850 3400
	1    0    0    -1  
$EndComp
Text HLabel 1350 1200 0    50   Input ~ 0
spi_clk_in
Text HLabel 1350 1400 0    50   Input ~ 0
spi_data_in
$Comp
L Device:R R66
U 1 1 5E83385B
P 4200 1450
F 0 "R66" V 4100 1450 50  0000 C CNN
F 1 "50k" V 4200 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4130 1450 50  0001 C CNN
F 3 "~" H 4200 1450 50  0001 C CNN
	1    4200 1450
	0    1    1    0   
$EndComp
$Comp
L Device:R R68
U 1 1 5E8345BE
P 4700 1450
F 0 "R68" V 4600 1450 50  0000 C CNN
F 1 "200k" V 4700 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4630 1450 50  0001 C CNN
F 3 "~" H 4700 1450 50  0001 C CNN
	1    4700 1450
	0    1    1    0   
$EndComp
$Comp
L Device:R R71
U 1 1 5E834941
P 5700 1950
F 0 "R71" V 5600 1950 50  0000 C CNN
F 1 "68k" V 5700 1950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5630 1950 50  0001 C CNN
F 3 "~" H 5700 1950 50  0001 C CNN
	1    5700 1950
	0    1    1    0   
$EndComp
$Comp
L Device:R R69
U 1 1 5E835989
P 5250 2200
F 0 "R69" H 5100 2200 50  0000 C CNN
F 1 "33k" V 5250 2200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 2200 50  0001 C CNN
F 3 "~" H 5250 2200 50  0001 C CNN
	1    5250 2200
	-1   0    0    1   
$EndComp
$Comp
L Device:C C38
U 1 1 5E8367D7
P 4950 1700
F 0 "C38" H 4700 1750 50  0000 L CNN
F 1 "2n2" H 4700 1650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4988 1550 50  0001 C CNN
F 3 "~" H 4950 1700 50  0001 C CNN
	1    4950 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C39
U 1 1 5E836AFB
P 5700 1000
F 0 "C39" V 5448 1000 50  0000 C CNN
F 1 "2n2" V 5539 1000 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5738 850 50  0001 C CNN
F 3 "~" H 5700 1000 50  0001 C CNN
	1    5700 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 1000 6150 1000
Wire Wire Line
	6150 1000 6150 1550
Wire Wire Line
	6150 1550 6000 1550
Wire Wire Line
	5850 1950 6150 1950
Wire Wire Line
	6150 1950 6150 1550
Connection ~ 6150 1550
Wire Wire Line
	5550 1950 5250 1950
Wire Wire Line
	5250 1950 5250 1650
Wire Wire Line
	5250 1650 5400 1650
Wire Wire Line
	5250 1950 5250 2050
Connection ~ 5250 1950
Wire Wire Line
	4950 1550 4950 1450
$Comp
L power:GND #PWR091
U 1 1 5E8452C9
P 4950 1950
F 0 "#PWR091" H 4950 1700 50  0001 C CNN
F 1 "GND" H 4955 1777 50  0000 C CNN
F 2 "" H 4950 1950 50  0001 C CNN
F 3 "" H 4950 1950 50  0001 C CNN
	1    4950 1950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR092
U 1 1 5E845C46
P 5250 2450
F 0 "#PWR092" H 5250 2200 50  0001 C CNN
F 1 "GND" H 5255 2277 50  0000 C CNN
F 2 "" H 5250 2450 50  0001 C CNN
F 3 "" H 5250 2450 50  0001 C CNN
	1    5250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2450 5250 2350
Wire Wire Line
	4950 1950 4950 1850
$Comp
L Device:R R65
U 1 1 5E8630C3
P 4100 3950
F 0 "R65" V 4000 3950 50  0000 C CNN
F 1 "50k" V 4100 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4030 3950 50  0001 C CNN
F 3 "~" H 4100 3950 50  0001 C CNN
	1    4100 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R67
U 1 1 5E8630C9
P 4600 3950
F 0 "R67" V 4500 3950 50  0000 C CNN
F 1 "200k" V 4600 3950 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4530 3950 50  0001 C CNN
F 3 "~" H 4600 3950 50  0001 C CNN
	1    4600 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R72
U 1 1 5E8630CF
P 5700 4450
F 0 "R72" V 5600 4450 50  0000 C CNN
F 1 "68k" V 5700 4450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5630 4450 50  0001 C CNN
F 3 "~" H 5700 4450 50  0001 C CNN
	1    5700 4450
	0    1    1    0   
$EndComp
$Comp
L Device:R R70
U 1 1 5E8630D5
P 5250 4700
F 0 "R70" H 5100 4700 50  0000 C CNN
F 1 "33k" V 5250 4700 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 5180 4700 50  0001 C CNN
F 3 "~" H 5250 4700 50  0001 C CNN
	1    5250 4700
	-1   0    0    1   
$EndComp
$Comp
L Device:C C37
U 1 1 5E8630DB
P 4850 4200
F 0 "C37" H 4965 4246 50  0000 L CNN
F 1 "2n2" H 4965 4155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4888 4050 50  0001 C CNN
F 3 "~" H 4850 4200 50  0001 C CNN
	1    4850 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C40
U 1 1 5E8630E1
P 5700 3500
F 0 "C40" V 5448 3500 50  0000 C CNN
F 1 "2n2" V 5539 3500 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5738 3350 50  0001 C CNN
F 3 "~" H 5700 3500 50  0001 C CNN
	1    5700 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 3500 6150 3500
Wire Wire Line
	6150 3500 6150 4050
Wire Wire Line
	6150 4050 6000 4050
Wire Wire Line
	5850 4450 6150 4450
Wire Wire Line
	6150 4450 6150 4050
Connection ~ 6150 4050
Wire Wire Line
	5550 4450 5250 4450
Wire Wire Line
	5250 4450 5250 4150
Wire Wire Line
	5250 4150 5400 4150
Wire Wire Line
	5250 4450 5250 4550
Connection ~ 5250 4450
Wire Wire Line
	4850 4050 4850 3950
$Comp
L power:GND #PWR090
U 1 1 5E8630FB
P 4850 4450
F 0 "#PWR090" H 4850 4200 50  0001 C CNN
F 1 "GND" H 4855 4277 50  0000 C CNN
F 2 "" H 4850 4450 50  0001 C CNN
F 3 "" H 4850 4450 50  0001 C CNN
	1    4850 4450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR093
U 1 1 5E863101
P 5250 4950
F 0 "#PWR093" H 5250 4700 50  0001 C CNN
F 1 "GND" H 5255 4777 50  0000 C CNN
F 2 "" H 5250 4950 50  0001 C CNN
F 3 "" H 5250 4950 50  0001 C CNN
	1    5250 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4950 5250 4850
Wire Wire Line
	4850 4450 4850 4350
$Comp
L Device:R R73
U 1 1 5E8677A4
P 7950 4000
F 0 "R73" V 7850 4000 50  0000 C CNN
F 1 "50k" V 7950 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7880 4000 50  0001 C CNN
F 3 "~" H 7950 4000 50  0001 C CNN
	1    7950 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R75
U 1 1 5E8677AA
P 8450 4000
F 0 "R75" V 8350 4000 50  0000 C CNN
F 1 "200k" V 8450 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8380 4000 50  0001 C CNN
F 3 "~" H 8450 4000 50  0001 C CNN
	1    8450 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R80
U 1 1 5E8677B0
P 9550 4500
F 0 "R80" V 9450 4500 50  0000 C CNN
F 1 "68k" V 9550 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 4500 50  0001 C CNN
F 3 "~" H 9550 4500 50  0001 C CNN
	1    9550 4500
	0    1    1    0   
$EndComp
$Comp
L Device:R R78
U 1 1 5E8677B6
P 9100 4750
F 0 "R78" H 8950 4750 50  0000 C CNN
F 1 "33k" V 9100 4750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9030 4750 50  0001 C CNN
F 3 "~" H 9100 4750 50  0001 C CNN
	1    9100 4750
	-1   0    0    1   
$EndComp
$Comp
L Device:C C41
U 1 1 5E8677BC
P 8700 4250
F 0 "C41" H 8400 4300 50  0000 L CNN
F 1 "2n2" H 8400 4200 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8738 4100 50  0001 C CNN
F 3 "~" H 8700 4250 50  0001 C CNN
	1    8700 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C44
U 1 1 5E8677C2
P 9550 3550
F 0 "C44" V 9298 3550 50  0000 C CNN
F 1 "2n2" V 9389 3550 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9588 3400 50  0001 C CNN
F 3 "~" H 9550 3550 50  0001 C CNN
	1    9550 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	9700 3550 10000 3550
Wire Wire Line
	10000 3550 10000 4100
Wire Wire Line
	10000 4100 9850 4100
Wire Wire Line
	9700 4500 10000 4500
Wire Wire Line
	10000 4500 10000 4100
Connection ~ 10000 4100
Wire Wire Line
	9400 4500 9100 4500
Wire Wire Line
	9100 4500 9100 4200
Wire Wire Line
	9100 4200 9250 4200
Wire Wire Line
	9100 4500 9100 4600
Connection ~ 9100 4500
Wire Wire Line
	8700 4100 8700 4000
$Comp
L power:GND #PWR094
U 1 1 5E8677DC
P 8700 4500
F 0 "#PWR094" H 8700 4250 50  0001 C CNN
F 1 "GND" H 8705 4327 50  0000 C CNN
F 2 "" H 8700 4500 50  0001 C CNN
F 3 "" H 8700 4500 50  0001 C CNN
	1    8700 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR097
U 1 1 5E8677E2
P 9100 5000
F 0 "#PWR097" H 9100 4750 50  0001 C CNN
F 1 "GND" H 9105 4827 50  0000 C CNN
F 2 "" H 9100 5000 50  0001 C CNN
F 3 "" H 9100 5000 50  0001 C CNN
	1    9100 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 5000 9100 4900
Wire Wire Line
	8700 4500 8700 4400
$Comp
L Device:R R74
U 1 1 5E8C5A85
P 8000 1500
F 0 "R74" V 7900 1500 50  0000 C CNN
F 1 "50k" V 8000 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7930 1500 50  0001 C CNN
F 3 "~" H 8000 1500 50  0001 C CNN
	1    8000 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R R76
U 1 1 5E8C5A8B
P 8500 1500
F 0 "R76" V 8400 1500 50  0000 C CNN
F 1 "200k" V 8500 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8430 1500 50  0001 C CNN
F 3 "~" H 8500 1500 50  0001 C CNN
	1    8500 1500
	0    1    1    0   
$EndComp
$Comp
L Device:R R79
U 1 1 5E8C5A91
P 9550 2000
F 0 "R79" V 9450 2000 50  0000 C CNN
F 1 "68k" V 9550 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9480 2000 50  0001 C CNN
F 3 "~" H 9550 2000 50  0001 C CNN
	1    9550 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R77
U 1 1 5E8C5A97
P 9100 2250
F 0 "R77" H 8950 2250 50  0000 C CNN
F 1 "33k" V 9100 2250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9030 2250 50  0001 C CNN
F 3 "~" H 9100 2250 50  0001 C CNN
	1    9100 2250
	-1   0    0    1   
$EndComp
$Comp
L Device:C C42
U 1 1 5E8C5A9D
P 8750 1750
F 0 "C42" H 8450 1800 50  0000 L CNN
F 1 "2n2" H 8450 1700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 8788 1600 50  0001 C CNN
F 3 "~" H 8750 1750 50  0001 C CNN
	1    8750 1750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C43
U 1 1 5E8C5AA3
P 9550 1050
F 0 "C43" V 9298 1050 50  0000 C CNN
F 1 "2n2" V 9389 1050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 9588 900 50  0001 C CNN
F 3 "~" H 9550 1050 50  0001 C CNN
	1    9550 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	9700 1050 10000 1050
Wire Wire Line
	10000 1050 10000 1600
Wire Wire Line
	10000 1600 9850 1600
Wire Wire Line
	9700 2000 10000 2000
Wire Wire Line
	10000 2000 10000 1600
Connection ~ 10000 1600
Wire Wire Line
	9400 2000 9100 2000
Wire Wire Line
	9100 2000 9100 1700
Wire Wire Line
	9100 1700 9250 1700
Wire Wire Line
	9100 2000 9100 2100
Connection ~ 9100 2000
Wire Wire Line
	8750 1600 8750 1500
$Comp
L power:GND #PWR095
U 1 1 5E8C5ABD
P 8750 2000
F 0 "#PWR095" H 8750 1750 50  0001 C CNN
F 1 "GND" H 8755 1827 50  0000 C CNN
F 2 "" H 8750 2000 50  0001 C CNN
F 3 "" H 8750 2000 50  0001 C CNN
	1    8750 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR096
U 1 1 5E8C5AC3
P 9100 2500
F 0 "#PWR096" H 9100 2250 50  0001 C CNN
F 1 "GND" H 9105 2327 50  0000 C CNN
F 2 "" H 9100 2500 50  0001 C CNN
F 3 "" H 9100 2500 50  0001 C CNN
	1    9100 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 2500 9100 2400
Wire Wire Line
	8750 2000 8750 1900
Text Label 2350 1500 0    50   ~ 0
adsr_1_3.3v
Text Label 4050 1450 2    50   ~ 0
adsr_1_3.3v
Text Label 2350 1200 0    50   ~ 0
adsr_2_3.3v
Text Label 2350 3100 0    50   ~ 0
adsr_3_3.3v
Text Label 2350 2800 0    50   ~ 0
adsr_4_3.3v
Text Label 7800 4000 2    50   ~ 0
adsr_4_3.3v
Text Label 7850 1500 2    50   ~ 0
adsr_2_3.3v
Text Label 3950 3950 2    50   ~ 0
adsr_3_3.3v
Wire Wire Line
	4850 1450 4950 1450
Connection ~ 4950 1450
Wire Wire Line
	4950 1450 5400 1450
Wire Wire Line
	4350 1450 4450 1450
Wire Wire Line
	4450 1000 4450 1450
Wire Wire Line
	4450 1000 5550 1000
Connection ~ 4450 1450
Wire Wire Line
	4450 1450 4550 1450
Connection ~ 8750 1500
Wire Wire Line
	8750 1500 8650 1500
Wire Wire Line
	8150 1500 8250 1500
Wire Wire Line
	8750 1500 9250 1500
Wire Wire Line
	8250 1050 8250 1500
Wire Wire Line
	8250 1050 9400 1050
Connection ~ 8250 1500
Wire Wire Line
	8250 1500 8350 1500
Connection ~ 4850 3950
Wire Wire Line
	4850 3950 4750 3950
Wire Wire Line
	4250 3950 4350 3950
Wire Wire Line
	4850 3950 5400 3950
Wire Wire Line
	4350 3500 4350 3950
Wire Wire Line
	4350 3500 5550 3500
Connection ~ 4350 3950
Wire Wire Line
	4350 3950 4450 3950
Connection ~ 8700 4000
Wire Wire Line
	8700 4000 8600 4000
Wire Wire Line
	8100 4000 8200 4000
Wire Wire Line
	8700 4000 9250 4000
Wire Wire Line
	8200 3550 8200 4000
Wire Wire Line
	8200 3550 9400 3550
Connection ~ 8200 4000
Wire Wire Line
	8200 4000 8300 4000
$Comp
L power:GND #PWR080
U 1 1 5EBB8058
P 1350 1300
F 0 "#PWR080" H 1350 1050 50  0001 C CNN
F 1 "GND" V 1355 1172 50  0000 R CNN
F 2 "" H 1350 1300 50  0001 C CNN
F 3 "" H 1350 1300 50  0001 C CNN
	1    1350 1300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR081
U 1 1 5EBB8A8F
P 1350 2900
F 0 "#PWR081" H 1350 2650 50  0001 C CNN
F 1 "GND" V 1355 2772 50  0000 R CNN
F 2 "" H 1350 2900 50  0001 C CNN
F 3 "" H 1350 2900 50  0001 C CNN
	1    1350 2900
	0    1    1    0   
$EndComp
$Comp
L power:+12V #PWR082
U 1 1 5EBBFDBB
P 1500 5500
F 0 "#PWR082" H 1500 5350 50  0001 C CNN
F 1 "+12V" H 1515 5673 50  0000 C CNN
F 2 "" H 1500 5500 50  0001 C CNN
F 3 "" H 1500 5500 50  0001 C CNN
	1    1500 5500
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR088
U 1 1 5EBC0D5B
P 2650 5500
F 0 "#PWR088" H 2650 5350 50  0001 C CNN
F 1 "+12V" H 2665 5673 50  0000 C CNN
F 2 "" H 2650 5500 50  0001 C CNN
F 3 "" H 2650 5500 50  0001 C CNN
	1    2650 5500
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR083
U 1 1 5EBC17E3
P 1500 6100
F 0 "#PWR083" H 1500 6200 50  0001 C CNN
F 1 "-12V" H 1515 6273 50  0000 C CNN
F 2 "" H 1500 6100 50  0001 C CNN
F 3 "" H 1500 6100 50  0001 C CNN
	1    1500 6100
	-1   0    0    1   
$EndComp
$Comp
L power:-12V #PWR089
U 1 1 5EBC2145
P 2650 6100
F 0 "#PWR089" H 2650 6200 50  0001 C CNN
F 1 "-12V" H 2665 6273 50  0000 C CNN
F 2 "" H 2650 6100 50  0001 C CNN
F 3 "" H 2650 6100 50  0001 C CNN
	1    2650 6100
	-1   0    0    1   
$EndComp
Text HLabel 1350 2800 0    50   Input ~ 0
spi_clk_in
$EndSCHEMATC
