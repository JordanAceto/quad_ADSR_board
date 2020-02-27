EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1000 2750 1500 1500
U 5E5AE433
F0 "encoders" 50
F1 "encoders.sch" 50
F2 "enc_1_b_out" O R 2500 2950 50 
F3 "enc_1_a_out" O R 2500 2850 50 
F4 "enc_1_sw_out" O R 2500 3050 50 
F5 "enc_2_b_out" O R 2500 3300 50 
F6 "enc_2_a_out" O R 2500 3200 50 
F7 "enc_2_sw_out" O R 2500 3400 50 
F8 "enc_3_b_out" O R 2500 3650 50 
F9 "enc_3_a_out" O R 2500 3550 50 
F10 "enc_3_sw_out" O R 2500 3750 50 
F11 "enc_4_b_out" O R 2500 4000 50 
F12 "enc_4_a_out" O R 2500 3900 50 
F13 "enc_4_sw_out" O R 2500 4100 50 
$EndSheet
$Sheet
S 9000 1000 1500 1500
U 5E60A7A1
F0 "seven_segment_display" 50
F1 "seven_segment_display.sch" 50
F2 "digit_1_in" I L 9000 2050 50 
F3 "digit_2_in" I L 9000 2150 50 
F4 "digit_3_in" I L 9000 2250 50 
F5 "digit_4_in" I L 9000 2350 50 
F6 "seven_segment_data_in" I L 9000 1150 50 
F7 "seven_segment_clk_in" I L 9000 1250 50 
F8 "seven_segment_en_in" I L 9000 1350 50 
$EndSheet
$Sheet
S 9000 2750 1500 1500
U 5E63B0C2
F0 "leds" 50
F1 "leds.sch" 50
F2 "rg_leds_data_in" I L 9000 2900 50 
F3 "rg_leds_clk_in" I L 9000 3000 50 
F4 "rg_leds_en_in" I L 9000 3100 50 
$EndSheet
$Sheet
S 9000 4500 1500 1500
U 5E68118F
F0 "output_jacks" 50
F1 "output_jacks.sch" 50
F2 "adsr_1_output_jack" I L 9000 4650 50 
F3 "adsr_2_output_jack" I L 9000 4750 50 
F4 "adsr_3_output_jack" I L 9000 4850 50 
F5 "adsr_4_output_jack" I L 9000 4950 50 
$EndSheet
$Sheet
S 1000 4500 1500 1500
U 5E57E71D
F0 "power_supply" 50
F1 "power_supply.sch" 50
$EndSheet
Wire Wire Line
	3500 1150 2500 1150
Wire Wire Line
	3500 1250 2500 1250
Wire Wire Line
	2500 1400 3500 1400
Wire Wire Line
	3500 1500 2500 1500
Wire Wire Line
	2500 1650 3500 1650
Wire Wire Line
	3500 1750 2500 1750
Wire Wire Line
	2500 1900 3500 1900
Wire Wire Line
	3500 2000 2500 2000
Wire Wire Line
	3500 2850 2500 2850
Wire Wire Line
	2500 2950 3500 2950
Wire Wire Line
	3500 3050 2500 3050
Wire Wire Line
	2500 3200 3500 3200
Wire Wire Line
	3500 3300 2500 3300
Wire Wire Line
	2500 3400 3500 3400
Wire Wire Line
	3500 3550 2500 3550
Wire Wire Line
	2500 3650 3500 3650
Wire Wire Line
	3500 3750 2500 3750
Wire Wire Line
	2500 3900 3500 3900
Wire Wire Line
	3500 4000 2500 4000
Wire Wire Line
	2500 4100 3500 4100
Wire Wire Line
	9000 2050 6000 2050
Wire Wire Line
	9000 2150 6000 2150
Wire Wire Line
	6000 2250 9000 2250
Wire Wire Line
	9000 2350 6000 2350
Wire Wire Line
	6000 4000 6400 4000
Wire Wire Line
	6400 4000 6400 4650
Wire Wire Line
	6400 4650 6500 4650
Wire Wire Line
	6500 4750 6300 4750
Wire Wire Line
	6300 4750 6300 4100
Wire Wire Line
	6300 4100 6000 4100
Wire Wire Line
	6500 4850 6200 4850
Wire Wire Line
	6200 4850 6200 4200
Wire Wire Line
	6200 4200 6000 4200
Wire Wire Line
	6500 4950 6100 4950
Wire Wire Line
	6100 4950 6100 4300
Wire Wire Line
	6100 4300 6000 4300
Wire Wire Line
	8000 4650 9000 4650
Wire Wire Line
	9000 4750 8000 4750
Wire Wire Line
	8000 4850 9000 4850
Wire Wire Line
	9000 4950 8000 4950
$Sheet
S 1000 1000 1500 1500
U 5E673522
F0 "input_jacks" 50
F1 "input_jacks.sch" 50
F2 "gate_1_input_signal" O R 2500 1150 50 
F3 "trigger_1_input_signal" O R 2500 1250 50 
F4 "gate_2_input_signal" O R 2500 1400 50 
F5 "trigger_2_input_signal" O R 2500 1500 50 
F6 "gate_3_input_signal" O R 2500 1650 50 
F7 "trigger_3_input_signal" O R 2500 1750 50 
F8 "gate_4_input_signal" O R 2500 1900 50 
F9 "trigger_4_input_signal" O R 2500 2000 50 
$EndSheet
$Sheet
S 6500 4500 1500 1500
U 5E595FD4
F0 "spi_dacs_and_level_shifters" 50
F1 "spi_dacs_and_level_shifters.sch" 50
F2 "spi_clk_in" I L 6500 4650 50 
F3 "spi_data_in" I L 6500 4750 50 
F4 "spi_cs_1_in" I L 6500 4850 50 
F5 "spi_cs_2_in" I L 6500 4950 50 
F6 "10vp_adsr_1_out" O R 8000 4650 50 
F7 "10vp_adsr_2_out" O R 8000 4750 50 
F8 "10vp_adsr_3_out" O R 8000 4850 50 
F9 "10vp_adsr_4_out" O R 8000 4950 50 
$EndSheet
Wire Wire Line
	6000 1150 9000 1150
Wire Wire Line
	9000 1250 6000 1250
$Sheet
S 3500 1000 2500 3500
U 5E5662AA
F0 "stmf32" 50
F1 "stmf32.sch" 50
F2 "gate_1_in" I L 3500 1150 50 
F3 "trigger_1_in" I L 3500 1250 50 
F4 "gate_2_in" I L 3500 1400 50 
F5 "trigger_2_in" I L 3500 1500 50 
F6 "gate_3_in" I L 3500 1650 50 
F7 "trigger_3_in" I L 3500 1750 50 
F8 "gate_4_in" I L 3500 1900 50 
F9 "trigger_4_in" I L 3500 2000 50 
F10 "encoder_1_a_in" I L 3500 2850 50 
F11 "encoder_1_b_in" I L 3500 2950 50 
F12 "encoder_1_sw_in" I L 3500 3050 50 
F13 "encoder_2_a_in" I L 3500 3200 50 
F14 "encoder_2_b_in" I L 3500 3300 50 
F15 "encoder_2_sw_in" I L 3500 3400 50 
F16 "encoder_3_a_in" I L 3500 3550 50 
F17 "encoder_3_b_in" I L 3500 3650 50 
F18 "encoder_3_sw_in" I L 3500 3750 50 
F19 "encoder_4_a_in" I L 3500 3900 50 
F20 "encoder_4_b_in" I L 3500 4000 50 
F21 "encoder_4_sw_in" I L 3500 4100 50 
F22 "digit_1_out" O R 6000 2050 50 
F23 "digit_2_out" O R 6000 2150 50 
F24 "digit_3_out" O R 6000 2250 50 
F25 "digit_4_out" O R 6000 2350 50 
F26 "spi_clk_out" O R 6000 4000 50 
F27 "spi_data_out" O R 6000 4100 50 
F28 "spi_cs_1_out" O R 6000 4200 50 
F29 "spi_cs_2_out" O R 6000 4300 50 
F30 "seven_segment_data_out" O R 6000 1150 50 
F31 "seven_segment_clk_out" O R 6000 1250 50 
F32 "rg_leds_data_out" O R 6000 2900 50 
F33 "rg_leds_clk_out" O R 6000 3000 50 
F34 "seven_segment_en_out" O R 6000 1350 50 
F35 "rg_leds_en_out" O R 6000 3100 50 
$EndSheet
Wire Wire Line
	6000 2900 9000 2900
Wire Wire Line
	9000 3000 6000 3000
Wire Wire Line
	9000 3100 6000 3100
Wire Wire Line
	9000 1350 6000 1350
$EndSCHEMATC
