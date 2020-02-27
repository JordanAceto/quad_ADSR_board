EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 9
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
L eurocad:PJ301M-12 J?
U 1 1 5E685C87
P 5550 6100
AR Path="/5E685C87" Ref="J?"  Part="1" 
AR Path="/5E68118F/5E685C87" Ref="J17"  Part="1" 
F 0 "J17" H 5558 6475 50  0000 C CNN
F 1 "PJ301M-12" H 5558 6384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 5550 6100 50  0001 C CNN
F 3 "" H 5550 6100 50  0000 C CNN
	1    5550 6100
	-1   0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E685C8D
P 5550 4600
AR Path="/5E685C8D" Ref="J?"  Part="1" 
AR Path="/5E68118F/5E685C8D" Ref="J16"  Part="1" 
F 0 "J16" H 5558 4975 50  0000 C CNN
F 1 "PJ301M-12" H 5558 4884 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 5550 4600 50  0001 C CNN
F 3 "" H 5550 4600 50  0000 C CNN
	1    5550 4600
	-1   0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E685C93
P 5550 3100
AR Path="/5E685C93" Ref="J?"  Part="1" 
AR Path="/5E68118F/5E685C93" Ref="J15"  Part="1" 
F 0 "J15" H 5558 3475 50  0000 C CNN
F 1 "PJ301M-12" H 5558 3384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 5550 3100 50  0001 C CNN
F 3 "" H 5550 3100 50  0000 C CNN
	1    5550 3100
	-1   0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E685C99
P 5550 1600
AR Path="/5E685C99" Ref="J?"  Part="1" 
AR Path="/5E68118F/5E685C99" Ref="J14"  Part="1" 
F 0 "J14" H 5558 1975 50  0000 C CNN
F 1 "PJ301M-12" H 5558 1884 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 5550 1600 50  0001 C CNN
F 3 "" H 5550 1600 50  0000 C CNN
	1    5550 1600
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5E685EE4
P 4950 1900
F 0 "#PWR026" H 4950 1650 50  0001 C CNN
F 1 "GND" H 4955 1727 50  0000 C CNN
F 2 "" H 4950 1900 50  0001 C CNN
F 3 "" H 4950 1900 50  0001 C CNN
	1    4950 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1900 4950 1750
Wire Wire Line
	4950 1750 5100 1750
$Comp
L power:GND #PWR027
U 1 1 5E686A1D
P 4950 3400
F 0 "#PWR027" H 4950 3150 50  0001 C CNN
F 1 "GND" H 4955 3227 50  0000 C CNN
F 2 "" H 4950 3400 50  0001 C CNN
F 3 "" H 4950 3400 50  0001 C CNN
	1    4950 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3400 4950 3250
Wire Wire Line
	4950 3250 5100 3250
$Comp
L power:GND #PWR028
U 1 1 5E686FAB
P 4950 4900
F 0 "#PWR028" H 4950 4650 50  0001 C CNN
F 1 "GND" H 4955 4727 50  0000 C CNN
F 2 "" H 4950 4900 50  0001 C CNN
F 3 "" H 4950 4900 50  0001 C CNN
	1    4950 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 4900 4950 4750
Wire Wire Line
	4950 4750 5100 4750
$Comp
L power:GND #PWR029
U 1 1 5E6872DD
P 4950 6400
F 0 "#PWR029" H 4950 6150 50  0001 C CNN
F 1 "GND" H 4955 6227 50  0000 C CNN
F 2 "" H 4950 6400 50  0001 C CNN
F 3 "" H 4950 6400 50  0001 C CNN
	1    4950 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 6400 4950 6250
Wire Wire Line
	4950 6250 5100 6250
$Comp
L Device:R R23
U 1 1 5E68763A
P 4750 1500
F 0 "R23" V 4650 1500 50  0000 C CNN
F 1 "1k" V 4750 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 1500 50  0001 C CNN
F 3 "~" H 4750 1500 50  0001 C CNN
	1    4750 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 1500 4900 1500
Text HLabel 4400 1500 0    50   Input ~ 0
adsr_1_output_jack
Wire Wire Line
	4400 1500 4600 1500
$Comp
L Device:R R24
U 1 1 5E689304
P 4750 3000
F 0 "R24" V 4650 3000 50  0000 C CNN
F 1 "1k" V 4750 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 3000 50  0001 C CNN
F 3 "~" H 4750 3000 50  0001 C CNN
	1    4750 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 3000 4900 3000
Text HLabel 4400 3000 0    50   Input ~ 0
adsr_2_output_jack
Wire Wire Line
	4400 3000 4600 3000
$Comp
L Device:R R25
U 1 1 5E6898B6
P 4750 4500
F 0 "R25" V 4650 4500 50  0000 C CNN
F 1 "1k" V 4750 4500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 4500 50  0001 C CNN
F 3 "~" H 4750 4500 50  0001 C CNN
	1    4750 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 4500 4900 4500
Text HLabel 4400 4500 0    50   Input ~ 0
adsr_3_output_jack
Wire Wire Line
	4400 4500 4600 4500
$Comp
L Device:R R26
U 1 1 5E689D56
P 4750 6000
F 0 "R26" V 4650 6000 50  0000 C CNN
F 1 "1k" V 4750 6000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4680 6000 50  0001 C CNN
F 3 "~" H 4750 6000 50  0001 C CNN
	1    4750 6000
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 6000 4900 6000
Text HLabel 4400 6000 0    50   Input ~ 0
adsr_4_output_jack
Wire Wire Line
	4400 6000 4600 6000
$EndSCHEMATC
