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
LIBS:Main_PCB_ver2-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L BTM7752G U4
U 1 1 56C8772A
P 6000 2050
F 0 "U4" H 6000 1950 60  0000 C CNN
F 1 "BTM7752G" H 6000 2050 60  0000 C CNN
F 2 "user_IC:PG-DSO-36" H 6000 2050 60  0001 C CNN
F 3 "" H 6000 2050 60  0000 C CNN
	1    6000 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1450 5450 1750
Connection ~ 5450 1650
Connection ~ 5450 1700
Wire Wire Line
	5450 2100 5450 2250
Connection ~ 5450 2200
Connection ~ 5450 2150
Wire Wire Line
	5450 2300 5450 2550
Connection ~ 5450 2350
Connection ~ 5450 2400
Wire Wire Line
	6550 2300 6550 2550
Connection ~ 6550 2400
Connection ~ 6550 2350
Wire Wire Line
	6550 2100 6550 2250
Connection ~ 6550 2200
Connection ~ 6550 2150
Wire Wire Line
	6550 1800 6550 1950
Connection ~ 6550 1900
Connection ~ 6550 1850
Wire Wire Line
	6550 1450 6550 1750
Connection ~ 6550 1700
Connection ~ 6550 1650
Wire Wire Line
	5450 1800 5450 1950
Connection ~ 5450 1850
Connection ~ 5450 1900
Text HLabel 4800 2000 0    60   Input ~ 0
IN_a-1
Text HLabel 4800 2100 0    60   Input ~ 0
IN_a-2
Text GLabel 6750 1800 2    60   Input ~ 0
VS
Text GLabel 5100 2250 0    60   Input ~ 0
VS
Wire Wire Line
	5450 2250 5100 2250
Wire Wire Line
	6750 1800 6550 1800
Wire Wire Line
	5450 2000 5100 2000
Wire Wire Line
	5100 2100 5350 2100
Wire Wire Line
	5350 2100 5350 2050
Wire Wire Line
	5350 2050 5450 2050
Wire Wire Line
	6550 2550 5450 2550
Connection ~ 5450 2450
Connection ~ 6550 2450
Text HLabel 5100 2450 0    60   Input ~ 0
motor_a-OUT1
Wire Wire Line
	5450 2450 5100 2450
Wire Wire Line
	5100 2450 5100 2550
$Comp
L R R6
U 1 1 56C9A9D5
P 4950 2550
F 0 "R6" V 5030 2550 50  0000 C CNN
F 1 "10kΩ" V 4950 2550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4880 2550 30  0001 C CNN
F 3 "" H 4950 2550 30  0000 C CNN
	1    4950 2550
	0    1    1    0   
$EndComp
Text HLabel 4800 2550 0    60   3State ~ 0
GND
Text HLabel 5100 1600 0    60   Input ~ 0
motor_a-OUT2
Wire Wire Line
	5450 1600 5100 1600
Wire Wire Line
	5100 1600 5100 1700
$Comp
L R R5
U 1 1 56C9AA91
P 4950 1700
F 0 "R5" V 5030 1700 50  0000 C CNN
F 1 "10kΩ" V 4950 1700 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4880 1700 30  0001 C CNN
F 3 "" H 4950 1700 30  0000 C CNN
	1    4950 1700
	0    1    1    0   
$EndComp
Text HLabel 4800 1700 0    60   3State ~ 0
GND
Wire Wire Line
	6550 1450 5450 1450
Connection ~ 5450 1600
Connection ~ 6550 1600
Connection ~ 5100 1600
Connection ~ 5100 2450
Wire Wire Line
	5450 1850 5150 1850
Text HLabel 5150 1850 0    60   3State ~ 0
GND
Text HLabel 6800 2250 2    60   3State ~ 0
GND
Wire Wire Line
	6550 2250 6800 2250
Text HLabel 7150 2100 2    60   Input ~ 0
INH_a
Text HLabel 7250 2000 2    60   Input ~ 0
IS_a
Wire Wire Line
	6550 2000 7250 2000
$Comp
L R R9
U 1 1 56C9AD2F
P 7250 1850
F 0 "R9" V 7330 1850 50  0000 C CNN
F 1 "1kΩ" V 7250 1850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 1850 30  0001 C CNN
F 3 "" H 7250 1850 30  0000 C CNN
	1    7250 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 2050 6750 2050
Wire Wire Line
	6750 2050 6750 2100
Wire Wire Line
	6750 2100 6850 2100
Wire Wire Line
	7000 2000 7000 1850
Wire Wire Line
	7000 1850 7100 1850
Connection ~ 7000 2000
Text HLabel 7400 1850 2    60   3State ~ 0
GND
Text GLabel 6900 1200 0    60   Input ~ 0
VS
Text HLabel 6900 1200 2    60   Input ~ 0
VS
$Comp
L BTM7752G U5
U 1 1 56C9B081
P 6050 3700
F 0 "U5" H 6050 3600 60  0000 C CNN
F 1 "BTM7752G" H 6050 3700 60  0000 C CNN
F 2 "user_IC:PG-DSO-36" H 6050 3700 60  0001 C CNN
F 3 "" H 6050 3700 60  0000 C CNN
	1    6050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 3100 5500 3400
Connection ~ 5500 3300
Connection ~ 5500 3350
Wire Wire Line
	5500 3750 5500 3900
Connection ~ 5500 3850
Connection ~ 5500 3800
Wire Wire Line
	5500 3950 5500 4200
Connection ~ 5500 4000
Connection ~ 5500 4050
Wire Wire Line
	6600 3950 6600 4200
Connection ~ 6600 4050
Connection ~ 6600 4000
Wire Wire Line
	6600 3750 6600 3900
Connection ~ 6600 3850
Connection ~ 6600 3800
Wire Wire Line
	6600 3450 6600 3600
Connection ~ 6600 3550
Connection ~ 6600 3500
Wire Wire Line
	6600 3100 6600 3400
Connection ~ 6600 3350
Connection ~ 6600 3300
Wire Wire Line
	5500 3450 5500 3600
Connection ~ 5500 3500
Connection ~ 5500 3550
Text HLabel 4850 3650 0    60   Input ~ 0
IN_b-1
Text HLabel 4850 3750 0    60   Input ~ 0
IN_b-2
Text GLabel 6800 3450 2    60   Input ~ 0
VS
Text GLabel 5150 3900 0    60   Input ~ 0
VS
Wire Wire Line
	5500 3900 5150 3900
Wire Wire Line
	6800 3450 6600 3450
Wire Wire Line
	5500 3650 5150 3650
Wire Wire Line
	5150 3750 5400 3750
Wire Wire Line
	5400 3750 5400 3700
Wire Wire Line
	5400 3700 5500 3700
Wire Wire Line
	6600 4200 5500 4200
Connection ~ 5500 4100
Connection ~ 6600 4100
Text HLabel 5150 4100 0    60   Input ~ 0
motor_b-OUT1
Wire Wire Line
	5500 4100 5150 4100
Wire Wire Line
	5150 4100 5150 4200
$Comp
L R R8
U 1 1 56C9B0AF
P 5000 4200
F 0 "R8" V 5080 4200 50  0000 C CNN
F 1 "10kΩ" V 5000 4200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4930 4200 30  0001 C CNN
F 3 "" H 5000 4200 30  0000 C CNN
	1    5000 4200
	0    1    1    0   
$EndComp
Text HLabel 4850 4200 0    60   3State ~ 0
GND
Text HLabel 5150 3250 0    60   Input ~ 0
motor_b-OUT2
Wire Wire Line
	5500 3250 5150 3250
Wire Wire Line
	5150 3250 5150 3350
$Comp
L R R7
U 1 1 56C9B0B9
P 5000 3350
F 0 "R7" V 5080 3350 50  0000 C CNN
F 1 "10kΩ" V 5000 3350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4930 3350 30  0001 C CNN
F 3 "" H 5000 3350 30  0000 C CNN
	1    5000 3350
	0    1    1    0   
$EndComp
Text HLabel 4850 3350 0    60   3State ~ 0
GND
Wire Wire Line
	6600 3100 5500 3100
Connection ~ 5500 3250
Connection ~ 6600 3250
Connection ~ 5150 3250
Connection ~ 5150 4100
Wire Wire Line
	5500 3500 5200 3500
Text HLabel 5200 3500 0    60   3State ~ 0
GND
Text HLabel 6850 3900 2    60   3State ~ 0
GND
Wire Wire Line
	6600 3900 6850 3900
Text HLabel 7200 3750 2    60   Input ~ 0
INH_b
Text HLabel 7300 3650 2    60   Input ~ 0
IS_b
Wire Wire Line
	6600 3650 7300 3650
$Comp
L R R10
U 1 1 56C9B0CC
P 7300 3500
F 0 "R10" V 7380 3500 50  0000 C CNN
F 1 "1kΩ" V 7300 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7230 3500 30  0001 C CNN
F 3 "" H 7300 3500 30  0000 C CNN
	1    7300 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 3700 6800 3700
Wire Wire Line
	6800 3700 6800 3750
Wire Wire Line
	6800 3750 6900 3750
Wire Wire Line
	7050 3650 7050 3500
Wire Wire Line
	7050 3500 7150 3500
Connection ~ 7050 3650
Text HLabel 7450 3500 2    60   3State ~ 0
GND
$Comp
L R R12
U 1 1 56CDE6A6
P 4950 2000
F 0 "R12" V 5030 2000 50  0000 C CNN
F 1 "4.7kΩ" V 4950 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4880 2000 30  0001 C CNN
F 3 "" H 4950 2000 30  0000 C CNN
	1    4950 2000
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 56CDE6E9
P 4950 2100
F 0 "R13" V 5030 2100 50  0000 C CNN
F 1 "4.7kΩ" V 4950 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4880 2100 30  0001 C CNN
F 3 "" H 4950 2100 30  0000 C CNN
	1    4950 2100
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 56CDEB57
P 5000 3650
F 0 "R14" V 5080 3650 50  0000 C CNN
F 1 "4.7kΩ" V 5000 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4930 3650 30  0001 C CNN
F 3 "" H 5000 3650 30  0000 C CNN
	1    5000 3650
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 56CDEB5D
P 5000 3750
F 0 "R15" V 5080 3750 50  0000 C CNN
F 1 "4.7kΩ" V 5000 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4930 3750 30  0001 C CNN
F 3 "" H 5000 3750 30  0000 C CNN
	1    5000 3750
	0    1    1    0   
$EndComp
$Comp
L R R17
U 1 1 56CDEB87
P 7050 3750
F 0 "R17" V 7130 3750 50  0000 C CNN
F 1 "4.7kΩ" V 7050 3750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6980 3750 30  0001 C CNN
F 3 "" H 7050 3750 30  0000 C CNN
	1    7050 3750
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 56CDECC8
P 7000 2100
F 0 "R16" V 7080 2100 50  0000 C CNN
F 1 "4.7kΩ" V 7000 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6930 2100 30  0001 C CNN
F 3 "" H 7000 2100 30  0000 C CNN
	1    7000 2100
	0    1    1    0   
$EndComp
Connection ~ 7150 2100
Connection ~ 6850 2100
Connection ~ 7200 3750
Connection ~ 6900 3750
Connection ~ 6600 3450
Connection ~ 6600 3900
Connection ~ 6550 2250
Connection ~ 5450 2100
Connection ~ 5450 2250
$EndSCHEMATC
