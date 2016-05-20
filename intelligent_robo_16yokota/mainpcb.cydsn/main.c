/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include <stdio.h>
#include "intelligent_robo.h"

uint8 g_timerFlag = 0;
uint16 g_count = 0;

#define UPDOWN 0
#define GRAB 1
#define LINE_TRACE 2
#define BLUE 3
#define RED 4
#define YELLOW 5

CY_ISR(clock_isr)
{
    g_timerFlag = 1;
}

int main()
{
    uint16 j = 0;
    char value[20];
    Let let;
    let.speed = 200;//速度変更
    
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    CyDelay(500);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    init();
    isr_1_StartEx(clock_isr);
    CyDelay(500);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString("PSoC5 Start");
    //アームの初期化
    PWM_Servo_Start();
    CyDelay(200);
    for(j=470;j<600;j++)
    {
        PWM_Servo(UPDOWN,j);
        CyDelay(8);
    }
    while(Debug_Switch_Read()==1){
        I2C_LCD_Position(1u,0u);
        I2C_LCD_1_PrintString("Are You Ready!!");
        PWM_Servo(UPDOWN,600);
        PWM_Servo(GRAB,1050);
    }
    I2C_LCD_1_Clear();   
    //Motor_Right(speed);
    //Motor_Left(speed);
    CyDelay(800);
    for(;;)
    {
        /* Place your application code here. */
        Debug_LED_Write(1);
        //Line_Trace(let);
        if(g_timerFlag == 1)
        {
            Catch_Ball();
            //Color_Sensor(&let);
            PSD_Sensor(&let);

            g_timerFlag = 0;
        }
    }
}

