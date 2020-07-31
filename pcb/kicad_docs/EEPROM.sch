EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 10
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
L Memory_EEPROM:24LC32 U13
U 1 1 5EE2D951
P 5400 3600
F 0 "U13" H 5000 4050 50  0000 C CNN
F 1 "24LC32" H 5000 3950 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5400 3600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21072G.pdf" H 5400 3600 50  0001 C CNN
	1    5400 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5EE2EA3C
P 5400 3900
F 0 "#PWR0120" H 5400 3650 50  0001 C CNN
F 1 "GND" H 5405 3727 50  0000 C CNN
F 2 "" H 5400 3900 50  0001 C CNN
F 3 "" H 5400 3900 50  0001 C CNN
	1    5400 3900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0119
U 1 1 5EE2F001
P 5400 3300
F 0 "#PWR0119" H 5400 3150 50  0001 C CNN
F 1 "+3.3V" H 5415 3473 50  0000 C CNN
F 2 "" H 5400 3300 50  0001 C CNN
F 3 "" H 5400 3300 50  0001 C CNN
	1    5400 3300
	1    0    0    -1  
$EndComp
Text HLabel 5800 3500 2    50   BiDi ~ 0
I2C2_SDA
Text HLabel 5800 3600 2    50   BiDi ~ 0
I2C2_SCL
Wire Wire Line
	5000 3500 4900 3500
Wire Wire Line
	4900 3500 4900 3600
Wire Wire Line
	4900 3700 5000 3700
Wire Wire Line
	5000 3600 4900 3600
Connection ~ 4900 3600
Wire Wire Line
	4900 3600 4900 3700
$Comp
L power:GND #PWR0118
U 1 1 5EE4A987
P 4900 3700
F 0 "#PWR0118" H 4900 3450 50  0001 C CNN
F 1 "GND" H 4905 3527 50  0000 C CNN
F 2 "" H 4900 3700 50  0001 C CNN
F 3 "" H 4900 3700 50  0001 C CNN
	1    4900 3700
	1    0    0    -1  
$EndComp
Connection ~ 4900 3700
Text Notes 4200 3650 0    50   ~ 0
address = 0xA0
$Comp
L power:GND #PWR0121
U 1 1 5EE4B0B7
P 5900 3800
F 0 "#PWR0121" H 5900 3550 50  0001 C CNN
F 1 "GND" H 5905 3627 50  0000 C CNN
F 2 "" H 5900 3800 50  0001 C CNN
F 3 "" H 5900 3800 50  0001 C CNN
	1    5900 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3800 5900 3700
Wire Wire Line
	5900 3700 5800 3700
$EndSCHEMATC
