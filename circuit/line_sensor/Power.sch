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
LIBS:line_sensor-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
L TA48M05F U2
U 1 1 56C87DEA
P 6000 1400
F 0 "U2" H 6100 1200 60  0000 C CNN
F 1 "TA48M05F" H 6000 1550 60  0000 C CNN
F 2 "user_IC:TA48M05F" H 6000 1400 60  0001 C CNN
F 3 "" H 6000 1400 60  0000 C CNN
	1    6000 1400
	1    0    0    -1  
$EndComp
$Comp
L TA48M033F U3
U 1 1 56C87E41
P 6000 2400
F 0 "U3" H 6100 2200 60  0000 C CNN
F 1 "TA48M033F" H 6000 2550 60  0000 C CNN
F 2 "KRL_IC_regulator:TA48M033F" H 6000 2400 60  0001 C CNN
F 3 "" H 6000 2400 60  0000 C CNN
	1    6000 2400
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 56C87ECE
P 5600 1500
F 0 "C6" H 5610 1570 50  0000 L CNN
F 1 "0.1uF" H 5610 1420 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 5600 1500 60  0001 C CNN
F 3 "" H 5600 1500 60  0000 C CNN
	1    5600 1500
	1    0    0    -1  
$EndComp
$Comp
L CP C9
U 1 1 56C87F5E
P 6400 1550
F 0 "C9" H 6425 1650 50  0000 L CNN
F 1 "47uF" H 6425 1450 50  0000 L CNN
F 2 "Capacitors_ThroughHole:Capacitor5x6RM2.5" H 6438 1400 30  0001 C CNN
F 3 "" H 6400 1550 60  0000 C CNN
	1    6400 1550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C7
U 1 1 56C87FB0
P 5600 2500
F 0 "C7" H 5610 2570 50  0000 L CNN
F 1 "0.1uF" H 5610 2420 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 5600 2500 60  0001 C CNN
F 3 "" H 5600 2500 60  0000 C CNN
	1    5600 2500
	1    0    0    -1  
$EndComp
$Comp
L CP C10
U 1 1 56C8802C
P 6400 2550
F 0 "C10" H 6425 2650 50  0000 L CNN
F 1 "47uF" H 6425 2450 50  0000 L CNN
F 2 "Capacitors_ThroughHole:Capacitor5x6RM2.5" H 6438 2400 30  0001 C CNN
F 3 "" H 6400 2550 60  0000 C CNN
	1    6400 2550
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV_MSM SW1
U 1 1 56C88150
P 4800 1300
F 0 "SW1" H 4601 1450 50  0000 C CNN
F 1 "SWITCH_INV_MSM" H 4550 1150 50  0000 C CNN
F 2 "user_SW:Toggle_Switch_1L" H 4800 1300 60  0001 C CNN
F 3 "" H 4800 1300 60  0000 C CNN
	1    4800 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1200 5300 1200
Wire Wire Line
	4300 1300 4300 1400
Wire Wire Line
	4300 1400 5600 1400
Connection ~ 5450 1400
Wire Wire Line
	5450 1400 5450 2400
Wire Wire Line
	5450 2400 5600 2400
Connection ~ 5600 1400
Connection ~ 5600 2400
Wire Wire Line
	6400 1400 6800 1400
Wire Wire Line
	6400 2400 6800 2400
Wire Wire Line
	5600 1600 5600 1700
Wire Wire Line
	5600 1700 6400 1700
Connection ~ 6000 1700
Wire Wire Line
	6000 1700 6000 1800
Wire Wire Line
	5600 2600 5600 2700
Wire Wire Line
	5600 2700 6400 2700
Connection ~ 6000 2700
Wire Wire Line
	6000 2700 6000 2800
Text HLabel 3900 1200 0    60   Input ~ 0
8Vin
Text HLabel 6800 1400 2    60   Output ~ 0
5V
Text HLabel 6800 2400 2    60   Output ~ 0
3.3V
Text HLabel 6000 1800 2    60   3State ~ 0
GND
Text HLabel 6000 2800 2    60   3State ~ 0
GND
$Comp
L LED D1
U 1 1 56C88C99
P 5300 1600
F 0 "D1" H 5300 1700 50  0000 C CNN
F 1 "LED" H 5300 1500 50  0000 C CNN
F 2 "user_IC:LED_HL_REG" H 5300 1600 60  0001 C CNN
F 3 "" H 5300 1600 60  0000 C CNN
	1    5300 1600
	0    -1   -1   0   
$EndComp
$Comp
L R R2
U 1 1 56C88D06
P 5300 1950
F 0 "R2" V 5380 1950 50  0000 C CNN
F 1 "1kΩ" V 5300 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5230 1950 30  0001 C CNN
F 3 "" H 5300 1950 30  0000 C CNN
	1    5300 1950
	1    0    0    -1  
$EndComp
Text HLabel 5300 2100 0    60   3State ~ 0
GND
$Comp
L SWITCH_INV_MSM SW2
U 1 1 56C965B4
P 5000 3150
F 0 "SW2" H 4801 3300 50  0000 C CNN
F 1 "SWITCH_INV_MSM" H 4750 3000 50  0000 C CNN
F 2 "user_SW:Toggle_Switch_1L" H 5000 3150 60  0001 C CNN
F 3 "" H 5000 3150 60  0000 C CNN
	1    5000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 3050 5500 3050
Wire Wire Line
	4500 3150 4500 3250
Wire Wire Line
	4500 3250 5850 3250
Connection ~ 5500 3250
$Comp
L R R4
U 1 1 56C96B93
P 6000 3250
F 0 "R4" V 6080 3250 50  0000 C CNN
F 1 "120Ω" V 6000 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5930 3250 30  0001 C CNN
F 3 "" H 6000 3250 30  0000 C CNN
	1    6000 3250
	0    1    1    0   
$EndComp
$Comp
L C_Small C8
U 1 1 56C96C7B
P 6250 3550
F 0 "C8" H 6260 3620 50  0000 L CNN
F 1 "1uF" H 6260 3470 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6250 3550 60  0001 C CNN
F 3 "" H 6250 3550 60  0000 C CNN
	1    6250 3550
	1    0    0    -1  
$EndComp
Text GLabel 6450 3250 2    60   Input ~ 0
PowerSW
Wire Wire Line
	6150 3250 6450 3250
Connection ~ 6250 3250
$Comp
L CP C5
U 1 1 56C96EE3
P 3850 3300
F 0 "C5" H 3875 3400 50  0000 L CNN
F 1 "330uF" H 3875 3200 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_5x5.3" H 3888 3150 30  0001 C CNN
F 3 "" H 3850 3300 60  0000 C CNN
	1    3850 3300
	1    0    0    -1  
$EndComp
$Comp
L MOS_N+pad Q1
U 1 1 56C97006
P 5400 4150
F 0 "Q1" H 5410 4320 60  0000 R CNN
F 1 "MOS_N+pad" H 5410 4000 60  0000 R CNN
F 2 "Transistors_TO-220:TO-220_FET-GDS_Horizontal" H 5400 4150 60  0001 C CNN
F 3 "" H 5400 4150 60  0000 C CNN
	1    5400 4150
	1    0    0    -1  
$EndComp
Text GLabel 5200 4150 0    60   Input ~ 0
PowerSW
Wire Wire Line
	3850 3150 3850 3050
Connection ~ 3850 3050
Wire Wire Line
	3850 3450 3850 4350
Wire Wire Line
	3850 4350 6250 4350
Wire Wire Line
	6250 3450 6250 3250
Wire Wire Line
	6250 4350 6250 3650
Connection ~ 5500 4350
Text HLabel 5500 3950 2    60   3State ~ 0
GND
Text HLabel 3850 3050 1    60   Input ~ 0
12Vin
$Comp
L DF22L-2P CN4
U 1 1 56C978E7
P 2750 3100
F 0 "CN4" H 2800 3300 60  0000 C CNN
F 1 "DF22L-2P" H 2800 2800 60  0000 C CNN
F 2 "user_conn:CONN_RED_2P" H 2700 3100 60  0001 C CNN
F 3 "" H 2700 3100 60  0000 C CNN
	1    2750 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3200 3300 3200
Wire Wire Line
	3300 3200 3300 3450
Wire Wire Line
	3300 3450 3850 3450
Connection ~ 3850 3450
$Comp
L LED D2
U 1 1 56C99A2B
P 5750 3450
F 0 "D2" H 5750 3550 50  0000 C CNN
F 1 "LED" H 5750 3350 50  0000 C CNN
F 2 "user_IC:LED_HL_REG" H 5750 3450 60  0001 C CNN
F 3 "" H 5750 3450 60  0000 C CNN
	1    5750 3450
	0    -1   -1   0   
$EndComp
$Comp
L R R3
U 1 1 56C99C50
P 5900 3800
F 0 "R3" V 5980 3800 50  0000 C CNN
F 1 "1kΩ" V 5900 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5830 3800 30  0001 C CNN
F 3 "" H 5900 3800 30  0000 C CNN
	1    5900 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 3800 5750 3650
Wire Wire Line
	6050 3800 6250 3800
Connection ~ 6250 3800
Connection ~ 5750 3250
Connection ~ 6400 2400
Connection ~ 5300 1400
Connection ~ 6400 1400
$Comp
L C_Small C11
U 1 1 56CA9ADA
P 3550 3250
F 0 "C11" H 3560 3320 50  0000 L CNN
F 1 "1uF" H 3560 3170 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 3550 3250 60  0001 C CNN
F 3 "" H 3550 3250 60  0000 C CNN
	1    3550 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3150 3550 3050
Connection ~ 3550 3050
Wire Wire Line
	3550 3350 3550 3450
Connection ~ 3550 3450
NoConn ~ 5600 4150
$EndSCHEMATC
