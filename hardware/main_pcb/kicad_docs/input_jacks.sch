EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 10
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
L eurocad:PJ301M-12 J?
U 1 1 5E6ADE9D
P 1400 2100
AR Path="/5E6ADE9D" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADE9D" Ref="J6"  Part="1" 
F 0 "J6" H 1408 2475 50  0000 C CNN
F 1 "gate_1_i n" H 1408 2384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 1400 2100 50  0001 C CNN
F 3 "" H 1400 2100 50  0000 C CNN
	1    1400 2100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADE97
P 1400 3100
AR Path="/5E6ADE97" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADE97" Ref="J7"  Part="1" 
F 0 "J7" H 1408 3475 50  0000 C CNN
F 1 "trigger_1_in" H 1408 3384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 1400 3100 50  0001 C CNN
F 3 "" H 1400 3100 50  0000 C CNN
	1    1400 3100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADE91
P 1400 4100
AR Path="/5E6ADE91" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADE91" Ref="J8"  Part="1" 
F 0 "J8" H 1408 4475 50  0000 C CNN
F 1 "gate_2_in" H 1408 4384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 1400 4100 50  0001 C CNN
F 3 "" H 1400 4100 50  0000 C CNN
	1    1400 4100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADE8B
P 1400 5100
AR Path="/5E6ADE8B" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADE8B" Ref="J9"  Part="1" 
F 0 "J9" H 1408 5475 50  0000 C CNN
F 1 "trigger_2_in" H 1408 5384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 1400 5100 50  0001 C CNN
F 3 "" H 1400 5100 50  0000 C CNN
	1    1400 5100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADEB5
P 6650 2100
AR Path="/5E6ADEB5" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADEB5" Ref="J10"  Part="1" 
F 0 "J10" H 6658 2475 50  0000 C CNN
F 1 "gate_3_in" H 6658 2384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 6650 2100 50  0001 C CNN
F 3 "" H 6650 2100 50  0000 C CNN
	1    6650 2100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADEAF
P 6650 3100
AR Path="/5E6ADEAF" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADEAF" Ref="J11"  Part="1" 
F 0 "J11" H 6658 3475 50  0000 C CNN
F 1 "trigger_3_in" H 6658 3384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 6650 3100 50  0001 C CNN
F 3 "" H 6650 3100 50  0000 C CNN
	1    6650 3100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADEA9
P 6650 4100
AR Path="/5E6ADEA9" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADEA9" Ref="J12"  Part="1" 
F 0 "J12" H 6658 4475 50  0000 C CNN
F 1 "gate_4_in" H 6658 4384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 6650 4100 50  0001 C CNN
F 3 "" H 6650 4100 50  0000 C CNN
	1    6650 4100
	1    0    0    1   
$EndComp
$Comp
L eurocad:PJ301M-12 J?
U 1 1 5E6ADEA3
P 6650 5100
AR Path="/5E6ADEA3" Ref="J?"  Part="1" 
AR Path="/5E673522/5E6ADEA3" Ref="J13"  Part="1" 
F 0 "J13" H 6658 5475 50  0000 C CNN
F 1 "trigger_4_in" H 6658 5384 50  0000 C CNN
F 2 "Eurocad:PJ301M-12" H 6650 5100 50  0001 C CNN
F 3 "" H 6650 5100 50  0000 C CNN
	1    6650 5100
	1    0    0    1   
$EndComp
Text HLabel 2900 1700 2    50   Output ~ 0
gate_1_input_signal
Text HLabel 3550 2700 2    50   Output ~ 0
trigger_1_input_signal
Text HLabel 4200 3700 2    50   Output ~ 0
gate_2_input_signal
Text HLabel 4850 4700 2    50   Output ~ 0
trigger_2_input_signal
Text HLabel 8200 1700 2    50   Output ~ 0
gate_3_input_signal
Text HLabel 8850 2700 2    50   Output ~ 0
trigger_3_input_signal
Text HLabel 9500 3700 2    50   Output ~ 0
gate_4_input_signal
Text HLabel 10150 4700 2    50   Output ~ 0
trigger_4_input_signal
$Comp
L Transistor_BJT:MMBT3904 Q5
U 1 1 5E59F147
P 2800 2000
F 0 "Q5" H 2991 2046 50  0000 L CNN
F 1 "MMBT3904" H 2991 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3000 1925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 2800 2000 50  0001 L CNN
	1    2800 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R49
U 1 1 5E59F779
P 2350 2000
F 0 "R49" V 2250 2000 50  0000 C CNN
F 1 "100k" V 2350 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2280 2000 50  0001 C CNN
F 3 "~" H 2350 2000 50  0001 C CNN
	1    2350 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 2000 2550 2000
Wire Wire Line
	2900 1800 2900 1600
$Comp
L power:GND #PWR061
U 1 1 5E5A09C1
P 2900 2250
F 0 "#PWR061" H 2900 2000 50  0001 C CNN
F 1 "GND" H 2905 2077 50  0000 C CNN
F 2 "" H 2900 2250 50  0001 C CNN
F 3 "" H 2900 2250 50  0001 C CNN
	1    2900 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2250 2900 2200
$Comp
L power:+3.3V #PWR060
U 1 1 5E5A1653
P 2900 1250
F 0 "#PWR060" H 2900 1100 50  0001 C CNN
F 1 "+3.3V" H 2915 1423 50  0000 C CNN
F 2 "" H 2900 1250 50  0001 C CNN
F 3 "" H 2900 1250 50  0001 C CNN
	1    2900 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 1250 2900 1300
$Comp
L Transistor_BJT:MMBT3904 Q7
U 1 1 5E5ABFF5
P 4100 4000
F 0 "Q7" H 4291 4046 50  0000 L CNN
F 1 "MMBT3904" H 4291 3955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4300 3925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4100 4000 50  0001 L CNN
	1    4100 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R53
U 1 1 5E5ABFFB
P 3650 4000
F 0 "R53" V 3550 4000 50  0000 C CNN
F 1 "100k" V 3650 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3580 4000 50  0001 C CNN
F 3 "~" H 3650 4000 50  0001 C CNN
	1    3650 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R54
U 1 1 5E5AC001
P 4200 3450
F 0 "R54" H 4270 3496 50  0000 L CNN
F 1 "10k" V 4200 3400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4130 3450 50  0001 C CNN
F 3 "~" H 4200 3450 50  0001 C CNN
	1    4200 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 4000 3850 4000
Wire Wire Line
	4200 3800 4200 3600
$Comp
L power:GND #PWR065
U 1 1 5E5AC009
P 4200 4250
F 0 "#PWR065" H 4200 4000 50  0001 C CNN
F 1 "GND" H 4205 4077 50  0000 C CNN
F 2 "" H 4200 4250 50  0001 C CNN
F 3 "" H 4200 4250 50  0001 C CNN
	1    4200 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 4250 4200 4200
$Comp
L power:+3.3V #PWR064
U 1 1 5E5AC010
P 4200 3250
F 0 "#PWR064" H 4200 3100 50  0001 C CNN
F 1 "+3.3V" H 4215 3423 50  0000 C CNN
F 2 "" H 4200 3250 50  0001 C CNN
F 3 "" H 4200 3250 50  0001 C CNN
	1    4200 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 3250 4200 3300
$Comp
L Transistor_BJT:MMBT3904 Q9
U 1 1 5E5ACEF7
P 8100 2000
F 0 "Q9" H 8291 2046 50  0000 L CNN
F 1 "MMBT3904" H 8291 1955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8300 1925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 8100 2000 50  0001 L CNN
	1    8100 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R57
U 1 1 5E5ACEFD
P 7650 2000
F 0 "R57" V 7550 2000 50  0000 C CNN
F 1 "100k" V 7650 2000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7580 2000 50  0001 C CNN
F 3 "~" H 7650 2000 50  0001 C CNN
	1    7650 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R58
U 1 1 5E5ACF03
P 8200 1450
F 0 "R58" H 8270 1496 50  0000 L CNN
F 1 "10k" V 8200 1400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8130 1450 50  0001 C CNN
F 3 "~" H 8200 1450 50  0001 C CNN
	1    8200 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2000 7850 2000
Wire Wire Line
	8200 1800 8200 1600
$Comp
L power:GND #PWR073
U 1 1 5E5ACF0B
P 8200 2250
F 0 "#PWR073" H 8200 2000 50  0001 C CNN
F 1 "GND" H 8205 2077 50  0000 C CNN
F 2 "" H 8200 2250 50  0001 C CNN
F 3 "" H 8200 2250 50  0001 C CNN
	1    8200 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2250 8200 2200
$Comp
L power:+3.3V #PWR072
U 1 1 5E5ACF12
P 8200 1250
F 0 "#PWR072" H 8200 1100 50  0001 C CNN
F 1 "+3.3V" H 8215 1423 50  0000 C CNN
F 2 "" H 8200 1250 50  0001 C CNN
F 3 "" H 8200 1250 50  0001 C CNN
	1    8200 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1250 8200 1300
$Comp
L Transistor_BJT:MMBT3904 Q11
U 1 1 5E5ADE43
P 9400 4000
F 0 "Q11" H 9591 4046 50  0000 L CNN
F 1 "MMBT3904" H 9591 3955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 9600 3925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 9400 4000 50  0001 L CNN
	1    9400 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R61
U 1 1 5E5ADE49
P 8950 4000
F 0 "R61" V 8850 4000 50  0000 C CNN
F 1 "100k" V 8950 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8880 4000 50  0001 C CNN
F 3 "~" H 8950 4000 50  0001 C CNN
	1    8950 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R R62
U 1 1 5E5ADE4F
P 9500 3450
F 0 "R62" H 9570 3496 50  0000 L CNN
F 1 "10k" V 9500 3400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9430 3450 50  0001 C CNN
F 3 "~" H 9500 3450 50  0001 C CNN
	1    9500 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4000 9150 4000
Wire Wire Line
	9500 3800 9500 3600
$Comp
L power:GND #PWR077
U 1 1 5E5ADE57
P 9500 4250
F 0 "#PWR077" H 9500 4000 50  0001 C CNN
F 1 "GND" H 9505 4077 50  0000 C CNN
F 2 "" H 9500 4250 50  0001 C CNN
F 3 "" H 9500 4250 50  0001 C CNN
	1    9500 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4250 9500 4200
$Comp
L power:+3.3V #PWR076
U 1 1 5E5ADE5E
P 9500 3250
F 0 "#PWR076" H 9500 3100 50  0001 C CNN
F 1 "+3.3V" H 9515 3423 50  0000 C CNN
F 2 "" H 9500 3250 50  0001 C CNN
F 3 "" H 9500 3250 50  0001 C CNN
	1    9500 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 3250 9500 3300
$Comp
L Transistor_BJT:MMBT3904 Q6
U 1 1 5E5AE767
P 3450 3000
F 0 "Q6" H 3641 3046 50  0000 L CNN
F 1 "MMBT3904" H 3641 2955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3650 2925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 3450 3000 50  0001 L CNN
	1    3450 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R51
U 1 1 5E5AE76D
P 3000 3000
F 0 "R51" V 2900 3000 50  0000 C CNN
F 1 "100k" V 3000 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2930 3000 50  0001 C CNN
F 3 "~" H 3000 3000 50  0001 C CNN
	1    3000 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 3000 3200 3000
Wire Wire Line
	3550 2800 3550 2600
$Comp
L power:GND #PWR063
U 1 1 5E5AE77B
P 3550 3250
F 0 "#PWR063" H 3550 3000 50  0001 C CNN
F 1 "GND" H 3555 3077 50  0000 C CNN
F 2 "" H 3550 3250 50  0001 C CNN
F 3 "" H 3550 3250 50  0001 C CNN
	1    3550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3250 3550 3200
$Comp
L power:+3.3V #PWR062
U 1 1 5E5AE782
P 3550 2250
F 0 "#PWR062" H 3550 2100 50  0001 C CNN
F 1 "+3.3V" H 3565 2423 50  0000 C CNN
F 2 "" H 3550 2250 50  0001 C CNN
F 3 "" H 3550 2250 50  0001 C CNN
	1    3550 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 2250 3550 2300
$Comp
L Transistor_BJT:MMBT3904 Q8
U 1 1 5E5AF3F8
P 4750 5000
F 0 "Q8" H 4941 5046 50  0000 L CNN
F 1 "MMBT3904" H 4941 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4950 4925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4750 5000 50  0001 L CNN
	1    4750 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R55
U 1 1 5E5AF3FE
P 4300 5000
F 0 "R55" V 4200 5000 50  0000 C CNN
F 1 "100k" V 4300 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4230 5000 50  0001 C CNN
F 3 "~" H 4300 5000 50  0001 C CNN
	1    4300 5000
	0    1    1    0   
$EndComp
$Comp
L Device:R R56
U 1 1 5E5AF404
P 4850 4450
F 0 "R56" H 4920 4496 50  0000 L CNN
F 1 "10k" V 4850 4400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4780 4450 50  0001 C CNN
F 3 "~" H 4850 4450 50  0001 C CNN
	1    4850 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 5000 4500 5000
Wire Wire Line
	4850 4800 4850 4600
$Comp
L power:GND #PWR067
U 1 1 5E5AF40C
P 4850 5250
F 0 "#PWR067" H 4850 5000 50  0001 C CNN
F 1 "GND" H 4855 5077 50  0000 C CNN
F 2 "" H 4850 5250 50  0001 C CNN
F 3 "" H 4850 5250 50  0001 C CNN
	1    4850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 5250 4850 5200
$Comp
L power:+3.3V #PWR066
U 1 1 5E5AF413
P 4850 4250
F 0 "#PWR066" H 4850 4100 50  0001 C CNN
F 1 "+3.3V" H 4865 4423 50  0000 C CNN
F 2 "" H 4850 4250 50  0001 C CNN
F 3 "" H 4850 4250 50  0001 C CNN
	1    4850 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4250 4850 4300
$Comp
L Transistor_BJT:MMBT3904 Q10
U 1 1 5E5B0458
P 8750 3000
F 0 "Q10" H 8941 3046 50  0000 L CNN
F 1 "MMBT3904" H 8941 2955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8950 2925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 8750 3000 50  0001 L CNN
	1    8750 3000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R59
U 1 1 5E5B045E
P 8300 3000
F 0 "R59" V 8200 3000 50  0000 C CNN
F 1 "100k" V 8300 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8230 3000 50  0001 C CNN
F 3 "~" H 8300 3000 50  0001 C CNN
	1    8300 3000
	0    1    1    0   
$EndComp
$Comp
L Device:R R60
U 1 1 5E5B0464
P 8850 2450
F 0 "R60" H 8920 2496 50  0000 L CNN
F 1 "10k" V 8850 2400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 8780 2450 50  0001 C CNN
F 3 "~" H 8850 2450 50  0001 C CNN
	1    8850 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3000 8500 3000
Wire Wire Line
	8850 2800 8850 2600
$Comp
L power:GND #PWR075
U 1 1 5E5B046C
P 8850 3250
F 0 "#PWR075" H 8850 3000 50  0001 C CNN
F 1 "GND" H 8855 3077 50  0000 C CNN
F 2 "" H 8850 3250 50  0001 C CNN
F 3 "" H 8850 3250 50  0001 C CNN
	1    8850 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 3250 8850 3200
$Comp
L power:+3.3V #PWR074
U 1 1 5E5B0473
P 8850 2250
F 0 "#PWR074" H 8850 2100 50  0001 C CNN
F 1 "+3.3V" H 8865 2423 50  0000 C CNN
F 2 "" H 8850 2250 50  0001 C CNN
F 3 "" H 8850 2250 50  0001 C CNN
	1    8850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 2250 8850 2300
$Comp
L Transistor_BJT:MMBT3904 Q12
U 1 1 5E5B166E
P 10050 5000
F 0 "Q12" H 10241 5046 50  0000 L CNN
F 1 "MMBT3904" H 10241 4955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10250 4925 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 10050 5000 50  0001 L CNN
	1    10050 5000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R63
U 1 1 5E5B1674
P 9600 5000
F 0 "R63" V 9500 5000 50  0000 C CNN
F 1 "100k" V 9600 5000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 9530 5000 50  0001 C CNN
F 3 "~" H 9600 5000 50  0001 C CNN
	1    9600 5000
	0    1    1    0   
$EndComp
$Comp
L Device:R R64
U 1 1 5E5B167A
P 10150 4450
F 0 "R64" H 10220 4496 50  0000 L CNN
F 1 "10k" V 10150 4400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 10080 4450 50  0001 C CNN
F 3 "~" H 10150 4450 50  0001 C CNN
	1    10150 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 5000 9800 5000
Wire Wire Line
	10150 4800 10150 4600
$Comp
L power:GND #PWR079
U 1 1 5E5B1682
P 10150 5250
F 0 "#PWR079" H 10150 5000 50  0001 C CNN
F 1 "GND" H 10155 5077 50  0000 C CNN
F 2 "" H 10150 5250 50  0001 C CNN
F 3 "" H 10150 5250 50  0001 C CNN
	1    10150 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 5250 10150 5200
$Comp
L power:+3.3V #PWR078
U 1 1 5E5B1689
P 10150 4250
F 0 "#PWR078" H 10150 4100 50  0001 C CNN
F 1 "+3.3V" H 10165 4423 50  0000 C CNN
F 2 "" H 10150 4250 50  0001 C CNN
F 3 "" H 10150 4250 50  0001 C CNN
	1    10150 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 4250 10150 4300
Wire Wire Line
	7250 5250 7100 5250
Wire Wire Line
	7250 5250 7250 5400
$Comp
L power:GND #PWR071
U 1 1 5E6D14F6
P 7250 5400
F 0 "#PWR071" H 7250 5150 50  0001 C CNN
F 1 "GND" H 7255 5227 50  0000 C CNN
F 2 "" H 7250 5400 50  0001 C CNN
F 3 "" H 7250 5400 50  0001 C CNN
	1    7250 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 4250 7100 4250
Wire Wire Line
	7250 4250 7250 4400
$Comp
L power:GND #PWR070
U 1 1 5E6D8CF4
P 7250 4400
F 0 "#PWR070" H 7250 4150 50  0001 C CNN
F 1 "GND" H 7255 4227 50  0000 C CNN
F 2 "" H 7250 4400 50  0001 C CNN
F 3 "" H 7250 4400 50  0001 C CNN
	1    7250 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3250 7100 3250
Wire Wire Line
	7250 3250 7250 3400
$Comp
L power:GND #PWR069
U 1 1 5E6D9F07
P 7250 3400
F 0 "#PWR069" H 7250 3150 50  0001 C CNN
F 1 "GND" H 7255 3227 50  0000 C CNN
F 2 "" H 7250 3400 50  0001 C CNN
F 3 "" H 7250 3400 50  0001 C CNN
	1    7250 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 2250 7100 2250
Wire Wire Line
	7250 2250 7250 2400
$Comp
L power:GND #PWR068
U 1 1 5E6DACC0
P 7250 2400
F 0 "#PWR068" H 7250 2150 50  0001 C CNN
F 1 "GND" H 7255 2227 50  0000 C CNN
F 2 "" H 7250 2400 50  0001 C CNN
F 3 "" H 7250 2400 50  0001 C CNN
	1    7250 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 2250 1850 2250
Wire Wire Line
	2000 2250 2000 2400
$Comp
L power:GND #PWR056
U 1 1 5E6DCA7D
P 2000 2400
F 0 "#PWR056" H 2000 2150 50  0001 C CNN
F 1 "GND" H 2005 2227 50  0000 C CNN
F 2 "" H 2000 2400 50  0001 C CNN
F 3 "" H 2000 2400 50  0001 C CNN
	1    2000 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3250 1850 3250
Wire Wire Line
	2000 3250 2000 3400
$Comp
L power:GND #PWR057
U 1 1 5E6DD7F3
P 2000 3400
F 0 "#PWR057" H 2000 3150 50  0001 C CNN
F 1 "GND" H 2005 3227 50  0000 C CNN
F 2 "" H 2000 3400 50  0001 C CNN
F 3 "" H 2000 3400 50  0001 C CNN
	1    2000 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 4250 1850 4250
Wire Wire Line
	2000 4250 2000 4400
$Comp
L power:GND #PWR058
U 1 1 5E6DEAAD
P 2000 4400
F 0 "#PWR058" H 2000 4150 50  0001 C CNN
F 1 "GND" H 2005 4227 50  0000 C CNN
F 2 "" H 2000 4400 50  0001 C CNN
F 3 "" H 2000 4400 50  0001 C CNN
	1    2000 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5250 1850 5250
Wire Wire Line
	2000 5250 2000 5400
$Comp
L power:GND #PWR059
U 1 1 5E6DFA21
P 2000 5400
F 0 "#PWR059" H 2000 5150 50  0001 C CNN
F 1 "GND" H 2005 5227 50  0000 C CNN
F 2 "" H 2000 5400 50  0001 C CNN
F 3 "" H 2000 5400 50  0001 C CNN
	1    2000 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2100 2000 2100
Wire Wire Line
	7100 5000 9450 5000
Wire Wire Line
	7100 3000 7450 3000
Wire Wire Line
	8800 4000 7100 4000
Wire Wire Line
	7100 2000 7350 2000
Wire Wire Line
	2850 3000 2200 3000
Wire Wire Line
	2200 2000 2100 2000
Wire Wire Line
	1850 4100 2100 4100
Connection ~ 2100 2000
Wire Wire Line
	1850 5100 2200 5100
Connection ~ 2200 3000
Wire Wire Line
	2200 3000 1850 3000
Wire Wire Line
	1850 3100 2000 3100
Wire Wire Line
	2000 3100 2000 3250
Connection ~ 2000 3250
Wire Wire Line
	1850 2000 2100 2000
Wire Wire Line
	2000 2100 2000 2250
Connection ~ 2000 2250
Text Label 2650 4000 0    50   ~ 0
g_2_normalization
Text Label 2650 5000 0    50   ~ 0
t_2_normalization
Text Label 7100 2100 0    50   ~ 0
g_2_normalization
Wire Wire Line
	7350 2000 7350 4100
Wire Wire Line
	7350 4100 7100 4100
Connection ~ 7350 2000
Wire Wire Line
	7350 2000 7500 2000
Wire Wire Line
	7100 5100 7450 5100
Wire Wire Line
	7450 5100 7450 3000
Connection ~ 7450 3000
Wire Wire Line
	7450 3000 8150 3000
Text Label 7100 3100 0    50   ~ 0
t_2_normalization
$Comp
L Diode:1N4148W D6
U 1 1 5EDCE225
P 2550 2250
F 0 "D6" V 2550 2000 50  0000 L CNN
F 1 "1N4148W" V 2650 1850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 2550 2075 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2550 2250 50  0001 C CNN
	1    2550 2250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5EDCF7F3
P 2550 2400
F 0 "#PWR0108" H 2550 2150 50  0001 C CNN
F 1 "GND" H 2555 2227 50  0000 C CNN
F 2 "" H 2550 2400 50  0001 C CNN
F 3 "" H 2550 2400 50  0001 C CNN
	1    2550 2400
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148W D7
U 1 1 5EDD1AAF
P 3200 3250
F 0 "D7" V 3200 2950 50  0000 L CNN
F 1 "1N4148W" V 3300 2800 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3200 3075 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3200 3250 50  0001 C CNN
	1    3200 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5EDD1AB5
P 3200 3400
F 0 "#PWR0109" H 3200 3150 50  0001 C CNN
F 1 "GND" H 3205 3227 50  0000 C CNN
F 2 "" H 3200 3400 50  0001 C CNN
F 3 "" H 3200 3400 50  0001 C CNN
	1    3200 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 2100 2550 2000
Connection ~ 2550 2000
Wire Wire Line
	2550 2000 2500 2000
Wire Wire Line
	3200 3100 3200 3000
Connection ~ 3200 3000
Wire Wire Line
	3200 3000 3150 3000
$Comp
L Diode:1N4148W D8
U 1 1 5EE1944D
P 3850 4300
F 0 "D8" V 3850 4000 50  0000 L CNN
F 1 "1N4148W" V 3950 3850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3850 4125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3850 4300 50  0001 C CNN
	1    3850 4300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 5EE19453
P 3850 4450
F 0 "#PWR0110" H 3850 4200 50  0001 C CNN
F 1 "GND" H 3855 4277 50  0000 C CNN
F 2 "" H 3850 4450 50  0001 C CNN
F 3 "" H 3850 4450 50  0001 C CNN
	1    3850 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4150 3850 4000
Connection ~ 3850 4000
Wire Wire Line
	3850 4000 3800 4000
$Comp
L Diode:1N4148W D9
U 1 1 5EE30232
P 4500 5300
F 0 "D9" V 4500 5000 50  0000 L CNN
F 1 "1N4148W" V 4600 4850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 4500 5125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 4500 5300 50  0001 C CNN
	1    4500 5300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5EE30238
P 4500 5450
F 0 "#PWR0111" H 4500 5200 50  0001 C CNN
F 1 "GND" H 4505 5277 50  0000 C CNN
F 2 "" H 4500 5450 50  0001 C CNN
F 3 "" H 4500 5450 50  0001 C CNN
	1    4500 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 5150 4500 5000
Connection ~ 4500 5000
Wire Wire Line
	4500 5000 4450 5000
$Comp
L Diode:1N4148W D10
U 1 1 5EE4CBEA
P 7850 2300
F 0 "D10" V 7850 2000 50  0000 L CNN
F 1 "1N4148W" V 7950 1850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 7850 2125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 7850 2300 50  0001 C CNN
	1    7850 2300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 5EE4CBF0
P 7850 2450
F 0 "#PWR0112" H 7850 2200 50  0001 C CNN
F 1 "GND" H 7855 2277 50  0000 C CNN
F 2 "" H 7850 2450 50  0001 C CNN
F 3 "" H 7850 2450 50  0001 C CNN
	1    7850 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 2150 7850 2000
Connection ~ 7850 2000
Wire Wire Line
	7850 2000 7800 2000
$Comp
L Diode:1N4148W D11
U 1 1 5EE63DB1
P 8500 3300
F 0 "D11" V 8500 3000 50  0000 L CNN
F 1 "1N4148W" V 8600 2850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 8500 3125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 8500 3300 50  0001 C CNN
	1    8500 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5EE63DB7
P 8500 3450
F 0 "#PWR0113" H 8500 3200 50  0001 C CNN
F 1 "GND" H 8505 3277 50  0000 C CNN
F 2 "" H 8500 3450 50  0001 C CNN
F 3 "" H 8500 3450 50  0001 C CNN
	1    8500 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 3150 8500 3000
Connection ~ 8500 3000
Wire Wire Line
	8500 3000 8450 3000
$Comp
L Diode:1N4148W D12
U 1 1 5EE7F78E
P 9150 4300
F 0 "D12" V 9150 4000 50  0000 L CNN
F 1 "1N4148W" V 9250 3850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 9150 4125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 9150 4300 50  0001 C CNN
	1    9150 4300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0114
U 1 1 5EE7F794
P 9150 4450
F 0 "#PWR0114" H 9150 4200 50  0001 C CNN
F 1 "GND" H 9155 4277 50  0000 C CNN
F 2 "" H 9150 4450 50  0001 C CNN
F 3 "" H 9150 4450 50  0001 C CNN
	1    9150 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 4150 9150 4000
Connection ~ 9150 4000
Wire Wire Line
	9150 4000 9100 4000
$Comp
L Diode:1N4148W D13
U 1 1 5EE96EE8
P 9800 5300
F 0 "D13" V 9800 5000 50  0000 L CNN
F 1 "1N4148W" V 9900 4850 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 9800 5125 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 9800 5300 50  0001 C CNN
	1    9800 5300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0115
U 1 1 5EE96EEE
P 9800 5450
F 0 "#PWR0115" H 9800 5200 50  0001 C CNN
F 1 "GND" H 9805 5277 50  0000 C CNN
F 2 "" H 9800 5450 50  0001 C CNN
F 3 "" H 9800 5450 50  0001 C CNN
	1    9800 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9800 5150 9800 5000
Connection ~ 9800 5000
Wire Wire Line
	9800 5000 9750 5000
Wire Wire Line
	2200 5100 2200 3000
Wire Wire Line
	2100 4100 2100 2000
Wire Wire Line
	3500 4000 1850 4000
$Comp
L Device:R R52
U 1 1 5E5AE773
P 3550 2450
F 0 "R52" H 3620 2496 50  0000 L CNN
F 1 "10k" V 3550 2400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3480 2450 50  0001 C CNN
F 3 "~" H 3550 2450 50  0001 C CNN
	1    3550 2450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R50
U 1 1 5E59F996
P 2900 1450
F 0 "R50" H 2970 1496 50  0000 L CNN
F 1 "10k" V 2900 1400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2830 1450 50  0001 C CNN
F 3 "~" H 2900 1450 50  0001 C CNN
	1    2900 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 5000 1850 5000
$EndSCHEMATC