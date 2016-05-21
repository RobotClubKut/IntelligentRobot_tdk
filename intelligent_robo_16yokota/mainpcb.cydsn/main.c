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

/* Mode */
#define MODE_SHOOTING_TENNIS_BALL   1
#define MODE_LINE_TRACE             2
#define MODE_SEEK                   3
#define MODE_APPROACH               4
#define MODE_CATCH                  5
#define MODE_SHOOT                  6
#define MODE_MOVE                   7

CY_ISR(clock_isr)
{
    g_timerFlag = 1;
}

int main()
{
    uint16 j = 0;
    Let let;
    
    /* 速度変更 */
    let.speed = 200;
    /* アームの初期化 */
    let.mode = MODE_SHOOTING_TENNIS_BALL;
    
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    CyDelay(500);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    init();
    isr_1_StartEx(clock_isr);
    CyDelay(500);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString("PSoC5 Start");
   
    PWM_Servo_Start();
    CyDelay(200);
    for(j=470;j<800;j++)
    {
        PWM_Servo(UPDOWN,j);
        CyDelay(8);
    }
    while(Debug_Switch_Read()==1){//ボタン押したらスタート
        I2C_LCD_Position(1u,0u);
        I2C_LCD_1_PrintString("Are You Ready!!");
        PWM_Servo(UPDOWN,800);
        PWM_Servo(GRAB,1050);
    }
    I2C_LCD_1_Clear();
    CyDelay(400);
    Motor_Right(let.speed);
    Motor_Left(let.speed);
    CyDelay(700);
    for(;;)
    {
        /* Place your application code here. */
        Debug_LED_Write(1);
        if(g_timerFlag == 1)
        {
            if(let.mode == MODE_SHOOTING_TENNIS_BALL)
            {
                Shooting_tennis_ball(&let);
            }
            else if(let.mode == MODE_LINE_TRACE)
            {
                Go_Ball_Area(&let);
            }
            else if(let.mode == MODE_SEEK)
            {
                
            }
            //Catch_Ball();
            //Color_Sensor(&let);
            //PSD_Sensor(&let);
            //Line_Trace(&let);
            g_timerFlag = 0;
        }
    }
}
