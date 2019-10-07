EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:RoboKUT_communication
LIBS:RoboKUT_conn
LIBS:RoboKUT_conn_KRP
LIBS:RoboKUT_IC
LIBS:RoboKUT_Passive
LIBS:RoboKUT_regul
LIBS:RoboKUT_sensor
LIBS:RoboKUT_special
LIBS:RoboKUT_SW
LIBS:RoboKUT_uC
LIBS:color_sensor-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L s11059-02DT color_sensor1
U 1 1 5674E2CB
P 4750 2150
F 0 "color_sensor1" H 4800 1850 60  0000 C CNN
F 1 "s11059-02DT" H 4750 2450 60  0000 C CNN
F 2 "user_IC:S11059-02DT" H 4500 2250 60  0001 C CNN
F 3 "" H 4500 2250 60  0000 C CNN
	1    4750 2150
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5674E309
P 5750 1900
F 0 "R2" V 5830 1900 50  0000 C CNN
F 1 "2.2kΩ" V 5700 1900 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 5680 1900 30  0001 C CNN
F 3 "" H 5750 1900 30  0000 C CNN
	1    5750 1900
	-1   0    0    1   
$EndComp
$Comp
L R R1
U 1 1 5674E387
P 5450 1800
F 0 "R1" V 5530 1800 50  0000 C CNN
F 1 "2.2kΩ" V 5400 1800 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 5380 1800 30  0001 C CNN
F 3 "" H 5450 1800 30  0000 C CNN
	1    5450 1800
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 5674E3E5
P 4150 2100
F 0 "C1" H 4175 2200 50  0000 L CNN
F 1 "0.1μF" H 3950 2000 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4188 1950 30  0001 C CNN
F 3 "" H 4150 2100 60  0000 C CNN
	1    4150 2100
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 56760177
P 7800 3350
F 0 "R3" V 7880 3350 50  0000 C CNN
F 1 "120Ω" V 7750 3350 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 7730 3350 30  0001 C CNN
F 3 "" H 7800 3350 30  0000 C CNN
	1    7800 3350
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 567601DB
P 7800 2900
F 0 "D1" H 7800 3000 50  0000 C CNN
F 1 "LED" H 7800 2800 50  0000 C CNN
F 2 "user_IC:LED_SMD" H 7800 2900 60  0001 C CNN
F 3 "" H 7800 2900 60  0000 C CNN
	1    7800 2900
	0    -1   -1   0   
$EndComp
$Comp
L R R4
U 1 1 56760412
P 8200 3350
F 0 "R4" V 8280 3350 50  0000 C CNN
F 1 "120Ω" V 8150 3350 50  0000 C CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" V 8130 3350 30  0001 C CNN
F 3 "" H 8200 3350 30  0000 C CNN
	1    8200 3350
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 56760418
P 8200 2900
F 0 "D2" H 8200 3000 50  0000 C CNN
F 1 "LED" H 8200 2800 50  0000 C CNN
F 2 "user_IC:LED_SMD" H 8200 2900 60  0001 C CNN
F 3 "" H 8200 2900 60  0000 C CNN
	1    8200 2900
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR01
U 1 1 56760716
P 4300 2350
F 0 "#PWR01" H 4300 2100 50  0001 C CNN
F 1 "GND" H 4300 2200 50  0000 C CNN
F 2 "" H 4300 2350 60  0000 C CNN
F 3 "" H 4300 2350 60  0000 C CNN
	1    4300 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5676072A
P 5300 2150
F 0 "#PWR02" H 5300 1900 50  0001 C CNN
F 1 "GND" H 5300 2000 50  0000 C CNN
F 2 "" H 5300 2150 60  0000 C CNN
F 3 "" H 5300 2150 60  0000 C CNN
	1    5300 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 56760A90
P 8200 4050
F 0 "#PWR03" H 8200 3800 50  0001 C CNN
F 1 "GND" H 8200 3900 50  0000 C CNN
F 2 "" H 8200 4050 60  0000 C CNN
F 3 "" H 8200 4050 60  0000 C CNN
	1    8200 4050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR04
U 1 1 56760AD4
P 8200 2650
F 0 "#PWR04" H 8200 2500 50  0001 C CNN
F 1 "+3.3V" H 8200 2790 50  0000 C CNN
F 2 "" H 8200 2650 60  0000 C CNN
F 3 "" H 8200 2650 60  0000 C CNN
	1    8200 2650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR05
U 1 1 56760B60
P 5750 1650
F 0 "#PWR05" H 5750 1500 50  0001 C CNN
F 1 "+3.3V" H 5750 1790 50  0000 C CNN
F 2 "" H 5750 1650 60  0000 C CNN
F 3 "" H 5750 1650 60  0000 C CNN
	1    5750 1650
	1    0    0    -1  
$EndComp
Text GLabel 5950 1950 2    60   Input ~ 0
SDA
Text GLabel 5950 2350 2    60   Input ~ 0
SCL
Text GLabel 6800 1050 2    60   Input ~ 0
SDA
Text GLabel 6800 1150 2    60   Input ~ 0
SCL
$Comp
L +3.3V #PWR06
U 1 1 56760E63
P 7150 850
F 0 "#PWR06" H 7150 700 50  0001 C CNN
F 1 "+3.3V" H 7150 990 50  0000 C CNN
F 2 "" H 7150 850 60  0000 C CNN
F 3 "" H 7150 850 60  0000 C CNN
	1    7150 850 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 56760E80
P 7150 950
F 0 "#PWR07" H 7150 700 50  0001 C CNN
F 1 "GND" H 7150 800 50  0000 C CNN
F 2 "" H 7150 950 60  0000 C CNN
F 3 "" H 7150 950 60  0000 C CNN
	1    7150 950 
	1    0    0    -1  
$EndComp
$Comp
L CONN_5_KRP P1
U 1 1 56778473
P 6450 1050
F 0 "P1" H 6200 1000 60  0000 C CNN
F 1 "CONN_5_KRP" H 6050 1100 60  0000 C CNN
F 2 "KRL_CONN:white_L_conn_5" H 6450 1100 60  0001 C CNN
F 3 "" H 6450 1100 60  0000 C CNN
	1    6450 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 1950 5950 1950
Wire Wire Line
	5200 2350 5950 2350
Connection ~ 5450 1950
Wire Wire Line
	5750 2050 5750 2350
Connection ~ 5750 2350
Wire Wire Line
	5750 1650 5750 1750
Wire Wire Line
	4300 1650 4300 1950
Wire Wire Line
	4300 1650 5750 1650
Connection ~ 5450 1650
Wire Wire Line
	5200 2050 5200 2250
Connection ~ 5200 2150
Wire Wire Line
	4300 2050 4300 2350
Connection ~ 4300 2150
Connection ~ 4300 2250
Wire Wire Line
	5200 2150 5300 2150
Wire Wire Line
	4300 1950 4150 1950
Wire Wire Line
	4300 2250 4150 2250
Wire Wire Line
	7800 3100 7800 3200
Wire Wire Line
	8200 3100 8200 3200
Wire Wire Line
	7800 3500 8200 3500
Wire Wire Line
	8200 3500 8200 3550
Wire Wire Line
	7800 2700 8200 2700
Wire Wire Line
	8200 2700 8200 2650
Connection ~ 5750 1650
Connection ~ 5750 1750
Connection ~ 5750 2050
Connection ~ 5200 1950
Connection ~ 5200 2050
Connection ~ 5200 2250
Connection ~ 5200 2350
Connection ~ 4300 2050
Connection ~ 4300 1950
Connection ~ 4150 1950
Connection ~ 4150 2250
Connection ~ 4300 2350
Connection ~ 7800 2700
Connection ~ 8200 2700
Connection ~ 8200 3100
Connection ~ 8200 3200
Connection ~ 7800 3100
Connection ~ 7800 3200
Connection ~ 8200 3500
Connection ~ 7800 3500
Wire Wire Line
	7150 850  6800 850 
Wire Wire Line
	6800 950  7150 950 
Connection ~ 6800 850 
Connection ~ 6800 950 
Connection ~ 6800 1050
Connection ~ 6800 1150
Connection ~ 7150 850 
Connection ~ 7150 950 
Connection ~ 8200 3550
Connection ~ 7900 3750
Text GLabel 7900 3750 0    60   Input ~ 0
LED
Connection ~ 6800 1250
Wire Wire Line
	7100 1250 6800 1250
Text GLabel 7100 1250 2    60   Input ~ 0
LED
$Comp
L Q_NMOS_GSD Q1
U 1 1 567791C1
P 8100 3750
F 0 "Q1" H 8400 3800 50  0000 R CNN
F 1 "Q_NMOS_GSD" H 8750 3700 50  0000 R CNN
F 2 "user_IC:sot23_a" H 8300 3850 29  0001 C CNN
F 3 "" H 8100 3750 60  0000 C CNN
	1    8100 3750
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 567D3846
P 7900 3900
F 0 "R5" V 7980 3900 50  0000 C CNN
F 1 "1kΩ" V 7900 3900 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7830 3900 30  0001 C CNN
F 3 "" H 7900 3900 30  0000 C CNN
	1    7900 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 4050 8200 4050
Wire Wire Line
	8200 4050 8200 3950
Connection ~ 8200 4050
Connection ~ 8200 3950
Connection ~ 7900 4050
$EndSCHEMATC