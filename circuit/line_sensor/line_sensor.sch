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
L LBR_127HLD U3
U 1 1 56BE8E70
P 2450 1450
F 0 "U3" H 2340 1030 50  0000 C CNN
F 1 "LBR_127HLD" H 2340 1670 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 2350 1350 60  0001 C CNN
F 3 "" H 2350 1350 60  0000 C CNN
	1    2450 1450
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 56BEE0CC
P 3100 1200
F 0 "R7" V 3180 1200 50  0000 C CNN
F 1 "120Ω" V 3100 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3030 1200 30  0001 C CNN
F 3 "" H 3100 1200 30  0000 C CNN
	1    3100 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 56BEE159
P 2950 1850
F 0 "#PWR01" H 2950 1600 50  0001 C CNN
F 1 "GND" H 2950 1700 50  0000 C CNN
F 2 "" H 2950 1850 60  0000 C CNN
F 3 "" H 2950 1850 60  0000 C CNN
	1    2950 1850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 56BEE226
P 1750 1750
F 0 "#PWR02" H 1750 1600 50  0001 C CNN
F 1 "+5V" H 1750 1890 50  0000 C CNN
F 2 "" H 1750 1750 60  0000 C CNN
F 3 "" H 1750 1750 60  0000 C CNN
	1    1750 1750
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR03
U 1 1 56BEE23E
P 3100 1050
F 0 "#PWR03" H 3100 900 50  0001 C CNN
F 1 "+5V" H 3100 1190 50  0000 C CNN
F 2 "" H 3100 1050 60  0000 C CNN
F 3 "" H 3100 1050 60  0000 C CNN
	1    3100 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 56BEE400
P 1450 1350
F 0 "#PWR04" H 1450 1100 50  0001 C CNN
F 1 "GND" H 1450 1200 50  0000 C CNN
F 2 "" H 1450 1350 60  0000 C CNN
F 3 "" H 1450 1350 60  0000 C CNN
	1    1450 1350
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 56BEE8E9
P 1600 1350
F 0 "R3" V 1680 1350 50  0000 C CNN
F 1 "4.7kΩ" V 1600 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1530 1350 30  0001 C CNN
F 3 "" H 1600 1350 30  0000 C CNN
	1    1600 1350
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U4
U 1 1 56C5C88A
P 2450 2550
F 0 "U4" H 2340 2130 50  0000 C CNN
F 1 "LBR_127HLD" H 2340 2770 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 2350 2450 60  0001 C CNN
F 3 "" H 2350 2450 60  0000 C CNN
	1    2450 2550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 56C5C890
P 3100 2300
F 0 "R8" V 3180 2300 50  0000 C CNN
F 1 "120Ω" V 3100 2300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3030 2300 30  0001 C CNN
F 3 "" H 3100 2300 30  0000 C CNN
	1    3100 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 56C5C898
P 2950 2950
F 0 "#PWR05" H 2950 2700 50  0001 C CNN
F 1 "GND" H 2950 2800 50  0000 C CNN
F 2 "" H 2950 2950 60  0000 C CNN
F 3 "" H 2950 2950 60  0000 C CNN
	1    2950 2950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 56C5C89E
P 1750 2850
F 0 "#PWR06" H 1750 2700 50  0001 C CNN
F 1 "+5V" H 1750 2990 50  0000 C CNN
F 2 "" H 1750 2850 60  0000 C CNN
F 3 "" H 1750 2850 60  0000 C CNN
	1    1750 2850
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR07
U 1 1 56C5C8A4
P 3100 2150
F 0 "#PWR07" H 3100 2000 50  0001 C CNN
F 1 "+5V" H 3100 2290 50  0000 C CNN
F 2 "" H 3100 2150 60  0000 C CNN
F 3 "" H 3100 2150 60  0000 C CNN
	1    3100 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 56C5C8AA
P 1450 2450
F 0 "#PWR08" H 1450 2200 50  0001 C CNN
F 1 "GND" H 1450 2300 50  0000 C CNN
F 2 "" H 1450 2450 60  0000 C CNN
F 3 "" H 1450 2450 60  0000 C CNN
	1    1450 2450
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 56C5C8B0
P 1600 2450
F 0 "R4" V 1680 2450 50  0000 C CNN
F 1 "4.7kΩ" V 1600 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1530 2450 30  0001 C CNN
F 3 "" H 1600 2450 30  0000 C CNN
	1    1600 2450
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U7
U 1 1 56C5CCDC
P 4550 1450
F 0 "U7" H 4440 1030 50  0000 C CNN
F 1 "LBR_127HLD" H 4440 1670 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 4450 1350 60  0001 C CNN
F 3 "" H 4450 1350 60  0000 C CNN
	1    4550 1450
	1    0    0    -1  
$EndComp
$Comp
L R R15
U 1 1 56C5CCE2
P 5200 1200
F 0 "R15" V 5280 1200 50  0000 C CNN
F 1 "120Ω" V 5200 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 1200 30  0001 C CNN
F 3 "" H 5200 1200 30  0000 C CNN
	1    5200 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 56C5CCEA
P 5050 1850
F 0 "#PWR09" H 5050 1600 50  0001 C CNN
F 1 "GND" H 5050 1700 50  0000 C CNN
F 2 "" H 5050 1850 60  0000 C CNN
F 3 "" H 5050 1850 60  0000 C CNN
	1    5050 1850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR010
U 1 1 56C5CCF0
P 3850 1750
F 0 "#PWR010" H 3850 1600 50  0001 C CNN
F 1 "+5V" H 3850 1890 50  0000 C CNN
F 2 "" H 3850 1750 60  0000 C CNN
F 3 "" H 3850 1750 60  0000 C CNN
	1    3850 1750
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR011
U 1 1 56C5CCF6
P 5200 1050
F 0 "#PWR011" H 5200 900 50  0001 C CNN
F 1 "+5V" H 5200 1190 50  0000 C CNN
F 2 "" H 5200 1050 60  0000 C CNN
F 3 "" H 5200 1050 60  0000 C CNN
	1    5200 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR012
U 1 1 56C5CCFC
P 3550 1350
F 0 "#PWR012" H 3550 1100 50  0001 C CNN
F 1 "GND" H 3550 1200 50  0000 C CNN
F 2 "" H 3550 1350 60  0000 C CNN
F 3 "" H 3550 1350 60  0000 C CNN
	1    3550 1350
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 56C5CD02
P 3700 1350
F 0 "R11" V 3780 1350 50  0000 C CNN
F 1 "4.7kΩ" V 3700 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3630 1350 30  0001 C CNN
F 3 "" H 3700 1350 30  0000 C CNN
	1    3700 1350
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U8
U 1 1 56C5CD0A
P 4550 2550
F 0 "U8" H 4440 2130 50  0000 C CNN
F 1 "LBR_127HLD" H 4440 2770 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 4450 2450 60  0001 C CNN
F 3 "" H 4450 2450 60  0000 C CNN
	1    4550 2550
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 56C5CD10
P 5200 2300
F 0 "R16" V 5280 2300 50  0000 C CNN
F 1 "120Ω" V 5200 2300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5130 2300 30  0001 C CNN
F 3 "" H 5200 2300 30  0000 C CNN
	1    5200 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR013
U 1 1 56C5CD18
P 5050 2950
F 0 "#PWR013" H 5050 2700 50  0001 C CNN
F 1 "GND" H 5050 2800 50  0000 C CNN
F 2 "" H 5050 2950 60  0000 C CNN
F 3 "" H 5050 2950 60  0000 C CNN
	1    5050 2950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 56C5CD1E
P 3850 2850
F 0 "#PWR014" H 3850 2700 50  0001 C CNN
F 1 "+5V" H 3850 2990 50  0000 C CNN
F 2 "" H 3850 2850 60  0000 C CNN
F 3 "" H 3850 2850 60  0000 C CNN
	1    3850 2850
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR015
U 1 1 56C5CD24
P 5200 2150
F 0 "#PWR015" H 5200 2000 50  0001 C CNN
F 1 "+5V" H 5200 2290 50  0000 C CNN
F 2 "" H 5200 2150 60  0000 C CNN
F 3 "" H 5200 2150 60  0000 C CNN
	1    5200 2150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 56C5CD2A
P 3550 2450
F 0 "#PWR016" H 3550 2200 50  0001 C CNN
F 1 "GND" H 3550 2300 50  0000 C CNN
F 2 "" H 3550 2450 60  0000 C CNN
F 3 "" H 3550 2450 60  0000 C CNN
	1    3550 2450
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 56C5CD30
P 3700 2450
F 0 "R12" V 3780 2450 50  0000 C CNN
F 1 "4.7kΩ" V 3700 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3630 2450 30  0001 C CNN
F 3 "" H 3700 2450 30  0000 C CNN
	1    3700 2450
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U1
U 1 1 56C5D155
P 2400 3750
F 0 "U1" H 2290 3330 50  0000 C CNN
F 1 "LBR_127HLD" H 2290 3970 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 2300 3650 60  0001 C CNN
F 3 "" H 2300 3650 60  0000 C CNN
	1    2400 3750
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 56C5D15B
P 3050 3500
F 0 "R5" V 3130 3500 50  0000 C CNN
F 1 "120Ω" V 3050 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2980 3500 30  0001 C CNN
F 3 "" H 3050 3500 30  0000 C CNN
	1    3050 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR017
U 1 1 56C5D163
P 2900 4150
F 0 "#PWR017" H 2900 3900 50  0001 C CNN
F 1 "GND" H 2900 4000 50  0000 C CNN
F 2 "" H 2900 4150 60  0000 C CNN
F 3 "" H 2900 4150 60  0000 C CNN
	1    2900 4150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 56C5D169
P 1700 4050
F 0 "#PWR018" H 1700 3900 50  0001 C CNN
F 1 "+5V" H 1700 4190 50  0000 C CNN
F 2 "" H 1700 4050 60  0000 C CNN
F 3 "" H 1700 4050 60  0000 C CNN
	1    1700 4050
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR019
U 1 1 56C5D16F
P 3050 3350
F 0 "#PWR019" H 3050 3200 50  0001 C CNN
F 1 "+5V" H 3050 3490 50  0000 C CNN
F 2 "" H 3050 3350 60  0000 C CNN
F 3 "" H 3050 3350 60  0000 C CNN
	1    3050 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 56C5D175
P 1400 3650
F 0 "#PWR020" H 1400 3400 50  0001 C CNN
F 1 "GND" H 1400 3500 50  0000 C CNN
F 2 "" H 1400 3650 60  0000 C CNN
F 3 "" H 1400 3650 60  0000 C CNN
	1    1400 3650
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56C5D17B
P 1550 3650
F 0 "R1" V 1630 3650 50  0000 C CNN
F 1 "4.7kΩ" V 1550 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1480 3650 30  0001 C CNN
F 3 "" H 1550 3650 30  0000 C CNN
	1    1550 3650
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U2
U 1 1 56C5D183
P 2400 4850
F 0 "U2" H 2290 4430 50  0000 C CNN
F 1 "LBR_127HLD" H 2290 5070 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 2300 4750 60  0001 C CNN
F 3 "" H 2300 4750 60  0000 C CNN
	1    2400 4850
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 56C5D189
P 3050 4600
F 0 "R6" V 3130 4600 50  0000 C CNN
F 1 "120Ω" V 3050 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2980 4600 30  0001 C CNN
F 3 "" H 3050 4600 30  0000 C CNN
	1    3050 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR021
U 1 1 56C5D191
P 2900 5250
F 0 "#PWR021" H 2900 5000 50  0001 C CNN
F 1 "GND" H 2900 5100 50  0000 C CNN
F 2 "" H 2900 5250 60  0000 C CNN
F 3 "" H 2900 5250 60  0000 C CNN
	1    2900 5250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR022
U 1 1 56C5D197
P 1700 5150
F 0 "#PWR022" H 1700 5000 50  0001 C CNN
F 1 "+5V" H 1700 5290 50  0000 C CNN
F 2 "" H 1700 5150 60  0000 C CNN
F 3 "" H 1700 5150 60  0000 C CNN
	1    1700 5150
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR023
U 1 1 56C5D19D
P 3050 4450
F 0 "#PWR023" H 3050 4300 50  0001 C CNN
F 1 "+5V" H 3050 4590 50  0000 C CNN
F 2 "" H 3050 4450 60  0000 C CNN
F 3 "" H 3050 4450 60  0000 C CNN
	1    3050 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 56C5D1A3
P 1400 4750
F 0 "#PWR024" H 1400 4500 50  0001 C CNN
F 1 "GND" H 1400 4600 50  0000 C CNN
F 2 "" H 1400 4750 60  0000 C CNN
F 3 "" H 1400 4750 60  0000 C CNN
	1    1400 4750
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 56C5D1A9
P 1550 4750
F 0 "R2" V 1630 4750 50  0000 C CNN
F 1 "4.7kΩ" V 1550 4750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1480 4750 30  0001 C CNN
F 3 "" H 1550 4750 30  0000 C CNN
	1    1550 4750
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U5
U 1 1 56C5D1B1
P 4500 3750
F 0 "U5" H 4390 3330 50  0000 C CNN
F 1 "LBR_127HLD" H 4390 3970 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 4400 3650 60  0001 C CNN
F 3 "" H 4400 3650 60  0000 C CNN
	1    4500 3750
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 56C5D1B7
P 5150 3500
F 0 "R13" V 5230 3500 50  0000 C CNN
F 1 "120Ω" V 5150 3500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5080 3500 30  0001 C CNN
F 3 "" H 5150 3500 30  0000 C CNN
	1    5150 3500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 56C5D1BF
P 5000 4150
F 0 "#PWR025" H 5000 3900 50  0001 C CNN
F 1 "GND" H 5000 4000 50  0000 C CNN
F 2 "" H 5000 4150 60  0000 C CNN
F 3 "" H 5000 4150 60  0000 C CNN
	1    5000 4150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR026
U 1 1 56C5D1C5
P 3800 4050
F 0 "#PWR026" H 3800 3900 50  0001 C CNN
F 1 "+5V" H 3800 4190 50  0000 C CNN
F 2 "" H 3800 4050 60  0000 C CNN
F 3 "" H 3800 4050 60  0000 C CNN
	1    3800 4050
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR027
U 1 1 56C5D1CB
P 5150 3350
F 0 "#PWR027" H 5150 3200 50  0001 C CNN
F 1 "+5V" H 5150 3490 50  0000 C CNN
F 2 "" H 5150 3350 60  0000 C CNN
F 3 "" H 5150 3350 60  0000 C CNN
	1    5150 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR028
U 1 1 56C5D1D1
P 3500 3650
F 0 "#PWR028" H 3500 3400 50  0001 C CNN
F 1 "GND" H 3500 3500 50  0000 C CNN
F 2 "" H 3500 3650 60  0000 C CNN
F 3 "" H 3500 3650 60  0000 C CNN
	1    3500 3650
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 56C5D1D7
P 3650 3650
F 0 "R9" V 3730 3650 50  0000 C CNN
F 1 "4.7kΩ" V 3650 3650 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3580 3650 30  0001 C CNN
F 3 "" H 3650 3650 30  0000 C CNN
	1    3650 3650
	0    1    1    0   
$EndComp
$Comp
L LBR_127HLD U6
U 1 1 56C5D1DF
P 4500 4850
F 0 "U6" H 4390 4430 50  0000 C CNN
F 1 "LBR_127HLD" H 4390 5070 50  0000 C CNN
F 2 "user_sensor:RPR-220" H 4400 4750 60  0001 C CNN
F 3 "" H 4400 4750 60  0000 C CNN
	1    4500 4850
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 56C5D1E5
P 5150 4600
F 0 "R14" V 5230 4600 50  0000 C CNN
F 1 "120Ω" V 5150 4600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5080 4600 30  0001 C CNN
F 3 "" H 5150 4600 30  0000 C CNN
	1    5150 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR029
U 1 1 56C5D1ED
P 5000 5250
F 0 "#PWR029" H 5000 5000 50  0001 C CNN
F 1 "GND" H 5000 5100 50  0000 C CNN
F 2 "" H 5000 5250 60  0000 C CNN
F 3 "" H 5000 5250 60  0000 C CNN
	1    5000 5250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR030
U 1 1 56C5D1F3
P 3800 5150
F 0 "#PWR030" H 3800 5000 50  0001 C CNN
F 1 "+5V" H 3800 5290 50  0000 C CNN
F 2 "" H 3800 5150 60  0000 C CNN
F 3 "" H 3800 5150 60  0000 C CNN
	1    3800 5150
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR031
U 1 1 56C5D1F9
P 5150 4450
F 0 "#PWR031" H 5150 4300 50  0001 C CNN
F 1 "+5V" H 5150 4590 50  0000 C CNN
F 2 "" H 5150 4450 60  0000 C CNN
F 3 "" H 5150 4450 60  0000 C CNN
	1    5150 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR032
U 1 1 56C5D1FF
P 3500 4750
F 0 "#PWR032" H 3500 4500 50  0001 C CNN
F 1 "GND" H 3500 4600 50  0000 C CNN
F 2 "" H 3500 4750 60  0000 C CNN
F 3 "" H 3500 4750 60  0000 C CNN
	1    3500 4750
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 56C5D205
P 3650 4750
F 0 "R10" V 3730 4750 50  0000 C CNN
F 1 "4.7kΩ" V 3650 4750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3580 4750 30  0001 C CNN
F 3 "" H 3650 4750 30  0000 C CNN
	1    3650 4750
	0    1    1    0   
$EndComp
$Comp
L GND #PWR033
U 1 1 56C5DAE2
P 5150 1000
F 0 "#PWR033" H 5150 750 50  0001 C CNN
F 1 "GND" H 5150 850 50  0000 C CNN
F 2 "" H 5150 1000 60  0000 C CNN
F 3 "" H 5150 1000 60  0000 C CNN
	1    5150 1000
	1    0    0    -1  
$EndComp
Text GLabel 1500 1200 0    60   Input ~ 0
PIN_1
Text GLabel 3600 1200 0    60   Input ~ 0
PIN_5
Text GLabel 1500 2300 0    60   Input ~ 0
PIN_2
Text GLabel 1450 3500 0    60   Input ~ 0
PIN_3
Text GLabel 1450 4600 0    60   Input ~ 0
PIN_4
Text GLabel 3600 2300 0    60   Input ~ 0
PIN_6
Text GLabel 3550 3500 0    60   Input ~ 0
PIN_7
Text GLabel 3550 4600 0    60   Input ~ 0
PIN_8
$Comp
L CY8C4245AXI-483 U9
U 1 1 56C60BAA
P 8050 2900
F 0 "U9" H 8025 2575 60  0000 C CNN
F 1 "CY8C4245AXI-483" H 8025 3100 60  0000 C CNN
F 2 "Housings_QFP:LQFP-44_10x10mm_Pitch0.8mm" H 8450 2950 60  0001 C CNN
F 3 "" H 8450 2950 60  0000 C CNN
	1    8050 2900
	1    0    0    -1  
$EndComp
Text GLabel 6950 2500 0    60   Input ~ 0
PIN_1
Text GLabel 6950 2600 0    60   Input ~ 0
PIN_2
Text GLabel 6950 2700 0    60   Input ~ 0
PIN_3
Text GLabel 6950 2800 0    60   Input ~ 0
PIN_4
Text GLabel 6950 2900 0    60   Input ~ 0
PIN_5
Text GLabel 6950 3000 0    60   Input ~ 0
PIN_6
Text GLabel 6950 3100 0    60   Input ~ 0
PIN_7
Text GLabel 6950 3200 0    60   Input ~ 0
PIN_8
$Comp
L C_Small C2
U 1 1 56C61F5D
P 7950 4450
F 0 "C2" H 7960 4520 50  0000 L CNN
F 1 "0.1uF" H 7960 4370 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 7950 4450 60  0001 C CNN
F 3 "" H 7950 4450 60  0000 C CNN
	1    7950 4450
	1    0    0    -1  
$EndComp
$Comp
L C_Small C3
U 1 1 56C61FAE
P 8200 4450
F 0 "C3" H 8210 4520 50  0000 L CNN
F 1 "1uF" H 8210 4370 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 8200 4450 60  0001 C CNN
F 3 "" H 8200 4450 60  0000 C CNN
	1    8200 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR034
U 1 1 56C62569
P 8200 4750
F 0 "#PWR034" H 8200 4500 50  0001 C CNN
F 1 "GND" H 8200 4600 50  0000 C CNN
F 2 "" H 8200 4750 60  0000 C CNN
F 3 "" H 8200 4750 60  0000 C CNN
	1    8200 4750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 56C628AF
P 8250 1500
F 0 "C4" H 8260 1570 50  0000 L CNN
F 1 "0.1uF" H 8260 1420 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 8250 1500 60  0001 C CNN
F 3 "" H 8250 1500 60  0000 C CNN
	1    8250 1500
	1    0    0    -1  
$EndComp
$Comp
L C_Small C5
U 1 1 56C628B5
P 8500 1500
F 0 "C5" H 8510 1570 50  0000 L CNN
F 1 "1uF" H 8510 1420 50  0000 L CNN
F 2 "Resistors_SMD:R_1206" H 8500 1500 60  0001 C CNN
F 3 "" H 8500 1500 60  0000 C CNN
	1    8500 1500
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR035
U 1 1 56C628C3
P 8750 1200
F 0 "#PWR035" H 8750 950 50  0001 C CNN
F 1 "GND" H 8750 1050 50  0000 C CNN
F 2 "" H 8750 1200 60  0000 C CNN
F 3 "" H 8750 1200 60  0000 C CNN
	1    8750 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1350 2950 1350
Wire Wire Line
	2950 1750 2950 1850
Wire Wire Line
	1750 1350 1750 1200
Wire Wire Line
	1750 1200 1500 1200
Wire Wire Line
	3100 2450 2950 2450
Wire Wire Line
	2950 2850 2950 2950
Wire Wire Line
	1750 2450 1750 2300
Wire Wire Line
	1750 2300 1500 2300
Wire Wire Line
	5200 1350 5050 1350
Wire Wire Line
	5050 1750 5050 1850
Wire Wire Line
	3850 1350 3850 1200
Wire Wire Line
	3850 1200 3600 1200
Wire Wire Line
	5200 2450 5050 2450
Wire Wire Line
	5050 2850 5050 2950
Wire Wire Line
	3850 2450 3850 2300
Wire Wire Line
	3850 2300 3600 2300
Wire Wire Line
	3050 3650 2900 3650
Wire Wire Line
	2900 4050 2900 4150
Wire Wire Line
	1700 3650 1700 3500
Wire Wire Line
	1700 3500 1450 3500
Wire Wire Line
	3050 4750 2900 4750
Wire Wire Line
	2900 5150 2900 5250
Wire Wire Line
	1700 4750 1700 4600
Wire Wire Line
	1700 4600 1450 4600
Wire Wire Line
	5150 3650 5000 3650
Wire Wire Line
	5000 4050 5000 4150
Wire Wire Line
	3800 3650 3800 3500
Wire Wire Line
	3800 3500 3550 3500
Wire Wire Line
	5150 4750 5000 4750
Wire Wire Line
	5000 5150 5000 5250
Wire Wire Line
	3800 4750 3800 4600
Wire Wire Line
	3800 4600 3550 4600
Wire Wire Line
	6950 3300 6300 3300
Wire Wire Line
	6950 2400 6300 2400
Wire Wire Line
	6300 2400 6300 4600
Connection ~ 6300 3300
Wire Wire Line
	7950 4550 7950 4800
Wire Wire Line
	6300 4600 8500 4600
Wire Wire Line
	8200 4550 8200 4750
Wire Wire Line
	7950 4300 8350 4300
Wire Wire Line
	7950 4300 7950 4350
Connection ~ 8200 4300
Connection ~ 8200 4600
Wire Wire Line
	8250 1600 8250 1650
Wire Wire Line
	8250 1650 8500 1650
Wire Wire Line
	8500 1600 8500 1900
Wire Wire Line
	8500 1200 8500 1400
Wire Wire Line
	8500 1350 8250 1350
Wire Wire Line
	8250 1350 8250 1400
Connection ~ 8500 1350
Connection ~ 8500 1650
Wire Wire Line
	8400 1900 9500 1900
Connection ~ 8500 1900
Wire Wire Line
	8500 1200 8750 1200
$Comp
L +5V #PWR036
U 1 1 56C63075
P 8350 4250
F 0 "#PWR036" H 8350 4100 50  0001 C CNN
F 1 "+5V" H 8350 4390 50  0000 C CNN
F 2 "" H 8350 4250 60  0000 C CNN
F 3 "" H 8350 4250 60  0000 C CNN
	1    8350 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 4300 8350 4250
Wire Wire Line
	8200 4350 8200 3950
Wire Wire Line
	9000 2400 9500 2400
Connection ~ 9500 2400
$Comp
L C_Small C7
U 1 1 56C63499
P 9500 2550
F 0 "C7" H 9510 2620 50  0000 L CNN
F 1 "1uF" H 9510 2470 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 9500 2550 60  0001 C CNN
F 3 "" H 9500 2550 60  0000 C CNN
	1    9500 2550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR037
U 1 1 56C63536
P 9250 1900
F 0 "#PWR037" H 9250 1750 50  0001 C CNN
F 1 "+5V" H 9250 2040 50  0000 C CNN
F 2 "" H 9250 1900 60  0000 C CNN
F 3 "" H 9250 1900 60  0000 C CNN
	1    9250 1900
	1    0    0    -1  
$EndComp
$Comp
L PSoC_SWD CN1
U 1 1 56C637BB
P 10300 4500
F 0 "CN1" H 10150 4875 60  0000 C CNN
F 1 "PSoC_SWD" H 10325 4150 60  0000 C CNN
F 2 "user_conn:DF1E_5P" H 10850 4600 60  0001 C CNN
F 3 "" H 10850 4600 60  0000 C CNN
	1    10300 4500
	1    0    0    -1  
$EndComp
Text GLabel 9850 4400 0    60   Input ~ 0
SWDCLK
Text GLabel 9850 4300 0    60   Input ~ 0
SWDIO
Text GLabel 7600 3950 3    60   Input ~ 0
SWDIO
Text GLabel 7700 3950 3    60   Input ~ 0
SWDCLK
Text GLabel 9850 4500 0    60   Input ~ 0
XRES
Text GLabel 9000 2500 2    60   Input ~ 0
XRES
$Comp
L +5V #PWR038
U 1 1 56C63D39
P 9650 4150
F 0 "#PWR038" H 9650 4000 50  0001 C CNN
F 1 "+5V" H 9650 4290 50  0000 C CNN
F 2 "" H 9650 4150 60  0000 C CNN
F 3 "" H 9650 4150 60  0000 C CNN
	1    9650 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR039
U 1 1 56C63D6C
P 9750 4900
F 0 "#PWR039" H 9750 4650 50  0001 C CNN
F 1 "GND" H 9750 4750 50  0000 C CNN
F 2 "" H 9750 4900 60  0000 C CNN
F 3 "" H 9750 4900 60  0000 C CNN
	1    9750 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 4600 9750 4600
Wire Wire Line
	9750 4600 9750 4900
Wire Wire Line
	9850 4700 9650 4700
Wire Wire Line
	9650 4700 9650 4150
$Comp
L CONN_4_KRP P1
U 1 1 56C643DF
P 9850 3300
F 0 "P1" H 9900 2850 60  0000 C CNN
F 1 "CONN_4_KRP" H 9900 2950 60  0000 C CNN
F 2 "user_conn:DF1E_4P" H 9850 3300 60  0001 C CNN
F 3 "" H 9850 3300 60  0000 C CNN
	1    9850 3300
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR040
U 1 1 56C70C54
P 10200 3150
F 0 "#PWR040" H 10200 3000 50  0001 C CNN
F 1 "+5V" H 10200 3290 50  0000 C CNN
F 2 "" H 10200 3150 60  0000 C CNN
F 3 "" H 10200 3150 60  0000 C CNN
	1    10200 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR041
U 1 1 56C70C88
P 10750 3600
F 0 "#PWR041" H 10750 3350 50  0001 C CNN
F 1 "GND" H 10750 3450 50  0000 C CNN
F 2 "" H 10750 3600 60  0000 C CNN
F 3 "" H 10750 3600 60  0000 C CNN
	1    10750 3600
	1    0    0    -1  
$EndComp
Text GLabel 10200 3450 2    60   Input ~ 0
UART/TX
Text GLabel 10200 3350 2    60   Input ~ 0
UART/RX
Wire Wire Line
	10200 3250 10750 3250
Wire Wire Line
	10750 3250 10750 3600
$Comp
L C C1
U 1 1 56C7144F
P 7500 1750
F 0 "C1" H 7525 1850 50  0000 L CNN
F 1 "1uF" H 7525 1650 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 7538 1600 30  0001 C CNN
F 3 "" H 7500 1750 60  0000 C CNN
	1    7500 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 1600 7200 1600
Wire Wire Line
	7200 1600 7200 1750
$Comp
L GND #PWR042
U 1 1 56C71608
P 7200 1750
F 0 "#PWR042" H 7200 1500 50  0001 C CNN
F 1 "GND" H 7200 1600 50  0000 C CNN
F 2 "" H 7200 1750 60  0000 C CNN
F 3 "" H 7200 1750 60  0000 C CNN
	1    7200 1750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C6
U 1 1 56C7175D
P 8500 4050
F 0 "C6" H 8510 4120 50  0000 L CNN
F 1 "2200pF" H 8510 3970 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 8500 4050 60  0001 C CNN
F 3 "" H 8500 4050 60  0000 C CNN
	1    8500 4050
	1    0    0    -1  
$EndComp
Text GLabel 9000 2800 2    60   Input ~ 0
UART/TX
Text GLabel 9000 2900 2    60   Input ~ 0
UART/RX
NoConn ~ 6950 3400
NoConn ~ 7600 1900
NoConn ~ 7700 1900
NoConn ~ 7800 1900
NoConn ~ 7900 1900
NoConn ~ 8000 1900
NoConn ~ 8100 1900
NoConn ~ 8200 1900
NoConn ~ 8300 1900
NoConn ~ 9000 2600
NoConn ~ 9000 2700
NoConn ~ 9000 3000
NoConn ~ 9000 3100
NoConn ~ 9000 3200
NoConn ~ 9000 3300
NoConn ~ 9000 3400
NoConn ~ 8400 3950
NoConn ~ 8300 3950
NoConn ~ 8100 3950
NoConn ~ 8000 3950
NoConn ~ 7900 3950
NoConn ~ 7800 3950
NoConn ~ 7500 3950
$Comp
L PWR_FLAG #FLG043
U 1 1 56C73EF2
P 9500 1900
F 0 "#FLG043" H 9500 1995 50  0001 C CNN
F 1 "PWR_FLAG" H 9500 2080 50  0000 C CNN
F 2 "" H 9500 1900 60  0000 C CNN
F 3 "" H 9500 1900 60  0000 C CNN
	1    9500 1900
	1    0    0    -1  
$EndComp
Connection ~ 9250 1900
$Comp
L GNDREF #PWR044
U 1 1 56C742CB
P 7950 4800
F 0 "#PWR044" H 7950 4550 50  0001 C CNN
F 1 "GNDREF" H 7950 4650 50  0000 C CNN
F 2 "" H 7950 4800 60  0000 C CNN
F 3 "" H 7950 4800 60  0000 C CNN
	1    7950 4800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR045
U 1 1 56C63568
P 9500 2650
F 0 "#PWR045" H 9500 2400 50  0001 C CNN
F 1 "GND" H 9500 2500 50  0000 C CNN
F 2 "" H 9500 2650 60  0000 C CNN
F 3 "" H 9500 2650 60  0000 C CNN
	1    9500 2650
	1    0    0    -1  
$EndComp
Connection ~ 7950 4600
Wire Wire Line
	8500 4600 8500 4150
Connection ~ 3850 1350
Connection ~ 3850 2450
Connection ~ 3800 3650
Connection ~ 3800 4750
Connection ~ 1700 4750
Connection ~ 1700 3650
Connection ~ 1750 2450
Connection ~ 1750 1350
Connection ~ 9500 1900
Connection ~ 6950 3300
Connection ~ 9850 4700
Connection ~ 8400 1900
Connection ~ 10200 3150
$Comp
L R R17
U 1 1 56C812F1
P 10700 1550
F 0 "R17" V 10780 1550 50  0000 C CNN
F 1 "R" V 10700 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10630 1550 30  0001 C CNN
F 3 "" H 10700 1550 30  0000 C CNN
	1    10700 1550
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 56C8167E
P 10700 1900
F 0 "D1" H 10700 2000 50  0000 C CNN
F 1 "LED" H 10700 1800 50  0000 C CNN
F 2 "user_IC:LED_3528" H 10700 1900 60  0001 C CNN
F 3 "" H 10700 1900 60  0000 C CNN
	1    10700 1900
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR046
U 1 1 56C81967
P 10700 1400
F 0 "#PWR046" H 10700 1250 50  0001 C CNN
F 1 "+5V" H 10700 1540 50  0000 C CNN
F 2 "" H 10700 1400 60  0000 C CNN
F 3 "" H 10700 1400 60  0000 C CNN
	1    10700 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR047
U 1 1 56C8197B
P 10700 2100
F 0 "#PWR047" H 10700 1850 50  0001 C CNN
F 1 "GND" H 10700 1950 50  0000 C CNN
F 2 "" H 10700 2100 60  0000 C CNN
F 3 "" H 10700 2100 60  0000 C CNN
	1    10700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 2400 9500 2450
$EndSCHEMATC
