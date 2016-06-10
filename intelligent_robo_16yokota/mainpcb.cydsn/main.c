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
#include "Servo.h"
 
uint8 g_timerFlag = 0;  

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
    int16 count_Right, count_Left;
    uint16 j = 0;
    double rps;
    double speed;
    char value[50];
    Let let;
    
    /* 構造体の初期化 */
    let.speed = 220;
    let.number = 0;
    let.place = 0;
    let.area = 0;
    let.count = 0;
    let.count_r = 0;
    
    //let.mode = MODE_SHOOTING_TENNIS_BALL;
    //let.mode = MODE_LINE_TRACE;
    //let.mode = MODE_SEEK;
    let.mode = MODE_DEBUG;
    /* Enable global interrupts. */
    CyGlobalIntEnable;
    CyDelay(500);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    init();
    UART_servo_Start();
    isr_1_StartEx(clock_isr);
    CyDelay(500);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString("PSoC5 Start");
    /* デバッグモード */
    if(let.mode == MODE_DEBUG)
    {
        for(;;)
        {

            if(g_timerFlag == 1)
            {
                Motor_Right(300);
                Motor_Left(300);
                //PSD_Sensor(&let);
                //Ball_Seek(&let);
                //Color_Sensor(&let);
                g_timerFlag = 0;
            }
        }
    }
    
    /* アームの初期化 */
    PWM_Servo_Start();
    CyDelay(200);
    for(j=DOWN;j>UP;j--)//7500が中心+に動かすと下へ
    {
        angle_keep(j);
        CyDelayUs(50);
    }
    
    while(Debug_Switch_Read()==1){//ボタン押したらスタート
        I2C_LCD_Position(1u,0u);
        I2C_LCD_1_PrintString("Are You Ready!!");
        angle_keep(UP);
        PWM_Servo(GRAB_BALL,GRAB);
    }
    let.grab = GRAB;
    let.updown = UP;
    I2C_LCD_1_Clear();
    CyDelay(400);
    /*
    PWM_Motor_a_WriteCompare1(0);
    PWM_Motor_a_WriteCompare2(200);
    PWM_Motor_b_WriteCompare1(0);
    PWM_Motor_b_WriteCompare2(200);
    CyDelay(700);
    */
    for(;;)
    {
        /* Place your application code here. */
        //Debug_LED_Write(1);
        if(g_timerFlag == 1)
        {
            /* PWMServoへの命令 */
            angle_keep(let.updown);
            PWM_Servo(GRAB_BALL,let.grab);
            /* モードによって処理を管理 */
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
                Ball_Seek(&let);
            }
            else if(let.mode == MODE_APPROACH)
            {
                approach(&let);
            }
            else if(let.mode == MODE_CATCH)
            {
                Catch_Ball(&let);
                //Color_Sensor(&let);
                PSD_Sensor(&let);
            }
            else if(let.mode == MODE_MOVE)
            {
                move(&let);
            }
            else if(let.mode == MODE_SHOOT)
            {
                Ball_Shoot(&let);
            }
            else if(let.mode == MODE_RETURN)
            {
                //Return(&let);
            }
            g_timerFlag = 0;
        }
        
    }
}
