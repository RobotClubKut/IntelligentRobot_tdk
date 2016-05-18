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

uint8 g_timerFlag = 0;
uint16 g_count = 0;

#define UPDOWN 0
#define GRAB 1
#define LINE_TRACE 2
#define BLUE 3
#define RED 4
#define YELLOW 5

union Slave{
    uint8 Trans;
    
    struct
    {
        uint8 a     : 1;//right
        uint8 b     : 1;
        uint8 c     : 1;
        uint8 d     : 1;
        uint8 e     : 1;
        uint8 f     : 1;
        uint8 g     : 1;
        uint8 h     : 1;//left
    }status;
};

typedef struct{
    union Slave slave;
}Line;

typedef struct{
    union Slave slave;
    uint8 speed;
    uint8 Area;
    uint8 position;
    uint8 unmber;
    uint8 color;
    uint8 d[3];
}Let;

CY_ISR(clock_isr)
{
    g_timerFlag = 1;
}

void init(void);
void I2C_Color_init(void);
void I2C_LCD_Position(uint8 row, uint8 column);
void I2C_LCD_Init(void);
void Motor_Right(int16 speed);
void Motor_Left(int16 speed);
void PWM_Servo(uint8 id,uint16 value);
void Catch_Ball(void);
void Line_Trace(Let *let);
void Color_Sensor(Let *let);
void PSD_Sensor(Let *let);

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
        PWM_Servo(GRAB,500);
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
            //Catch_Ball();
            //Color_Sensor(&let);
            PSD_Sensor(&let);
            
            
            g_timerFlag = 0;
        }
    }
}

void Line_Trace(Let *let){
    uint8 s = 0;
    uint8 AreaFlag = 0, aFlag = 0, hFlag = 0;
    double p = 0, p0 = 0, p1 = 0, p2 = 0, dif = 0;
    char value[20];
    if(UART_Line_Sensor_GetRxBufferSize())
    {
        let->slave.Trans = (uint8)UART_Line_Sensor_GetChar();
    }
    p = (double)(let->slave.status.h*(-3)+let->slave.status.g*(-2)+let->slave.status.f*(-1)+let->slave.status.e*(0)+
    let->slave.status.d*(1)+let->slave.status.c*(2)+let->slave.status.b*(3)+let->slave.status.a*(4));
    s = let->slave.status.h + let->slave.status.g + let->slave.status.f + let->slave.status.e + 
    let->slave.status.d + let->slave.status.c + let->slave.status.b + let->slave.status.a;
    
    if(s!=0)
    {
        p/=(double)s;
        p2 = p1;
        p1 = p0;
        p0 = p;
        dif += 16.1 * (p0-p1);//speed=200のとき
        //dif += 16.5 * (p0-p1) + 0.15 * p0 + 3.3 *((p0-p1) - (p1-p2));
        if(dif > let->speed)
        {
            dif = let->speed;
        }
        else if(dif < -let->speed)
        {
            dif = -let->speed;
        }
        Motor_Right(let->speed - (int)dif);
        Motor_Left(let->speed + (int)dif);
        
        if(dif>0)
        {
            I2C_LCD_Position(1u,7u);
            I2C_LCD_1_PrintString("right");
        }
        else if(dif<0)
        {
            I2C_LCD_Position(1u,7u);
            I2C_LCD_1_PrintString("left");
        }
    }

    //ライン読む
    if(let->slave.status.a==1)
    {
        aFlag = 1;
    }
    if(let->slave.status.h==1)
    {
        hFlag = 1;
    }
    if((aFlag == 1)&&(hFlag == 1))
    {
        AreaFlag++;
        aFlag = 0;
        hFlag = 0;    
        if(AreaFlag == 4)
        {
            Motor_Right(0);
            Motor_Left(0);
            sprintf(value, "Area=%d",AreaFlag);
            I2C_LCD_Position(1u,0u);
            I2C_LCD_1_PrintString(value);
            for(;;);
        }
        CyDelay(150);
        //いずれ書き直す
    }
    sprintf(value, "Area=%d",AreaFlag);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
}

void Color_Sensor(Let *let)
{
    uint8 r=0,g=0,b=0;
    unsigned char txReadStatus = 0x03;
    unsigned char rxBuf[8] = {1,0,0,0,0,0,0,0};
    char value[20];
    //Debug_LED_Write(1);
    I2C_1_MasterWriteBuf(0x2A,(uint8*)&txReadStatus,1,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT)){
//        Debug_LED_Write(0);
//        if(g_timerFlag==1){
//            x++;
//        }
//        if(x>50){
//            break;
//        }
//        g_timerFlag=0;
    }
    I2C_1_MasterClearStatus();
    I2C_1_MasterReadBuf(0x2A,(uint8 *)&rxBuf,8,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_RD_CMPLT));
    //Debug_LED_Write(1);
    I2C_1_MasterClearStatus();
    r = rxBuf[0]<< 8|rxBuf[1];
    g = rxBuf[2]<< 8|rxBuf[3];
    b = rxBuf[4]<< 8|rxBuf[5];
    //sprintf(value, "r=%3d a=%3d",r,x);
    //I2C_LCD_Position(1u,0u);
    //I2C_LCD_1_PrintString(value);
    //色判断して構造体に格納
    
    //let->color = BLUE;
    //みたいな
}
void PSD_Sensor(Let *let){
    uint8 i;
    char value[20];
    for(i=0;i<3;i++)
    {
        AMux_D_Sensor_Select(i);
        ADC_DelSig_Distance_StartConvert();
        ADC_DelSig_Distance_IsEndConversion(ADC_DelSig_Distance_WAIT_FOR_RESULT);
        let->d[i] = ADC_DelSig_Distance_GetResult8();
        ADC_DelSig_Distance_StopConvert();
    }
    I2C_LCD_1_Clear();
    sprintf(value, "1=%3d 2=%3d",let->d[0],let->d[1]);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString(value);
    sprintf(value, "3=%3d",let->d[2]);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
}


void Catch_Ball(void){
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(step == 0)
    {
        PWM_Servo(GRAB,500);//450~1050
        PWM_Servo(UPDOWN,600);
        limit = 100;
    }else
    if(step == 1)
    {
        PWM_Servo(UPDOWN,600-(int)(2.6*count));
        limit = 50;
    }else
    if(step == 2)
    {
        PWM_Servo(GRAB,1050);
        limit = 100;
    }else
    if(step == 3)
    {
        PWM_Servo(UPDOWN,470+(int)(2.6*count));
        limit = 50;
    }else
    if(step == 4)
    {
        limit = 200;
    }
    else
    if(step == 5)
    {
        step = 0;
        return;
    }
    if(limit == count)
    {
        count = 0;
        step++;
        return;
    }
    count++;
}

void PWM_Servo(uint8 id, uint16 value){
    if(value>1050){
        value = 1050;
    }
    else if(value<450){
        value = 450;
    }
    if(id == 0){
        PWM_Servo_WriteCompare1(value);
    }
    else if(id == 1){
        PWM_Servo_WriteCompare2(value);
    }
}

void Motor_Right(int16 speed){
    
    if((0<speed)&&(speed<255))
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(speed);   
    }
    else if((-255<speed)&&(speed<0))
    {
        PWM_Motor_a_WriteCompare1(-speed);
        PWM_Motor_a_WriteCompare2(0);
    }
    else
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(0);
    }
}

void Motor_Left(int16 speed){
    
    if((0<speed)&&(speed<255))
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(speed);   
    }
    else if((-255<speed)&&(speed<0))
    {
        PWM_Motor_b_WriteCompare1(-speed);
        PWM_Motor_b_WriteCompare2(0);
    }
    else
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(0);
    }
}

void I2C_Color_init(void)
{
    unsigned char txCBuf[2] = { 0x0, 0x89 };
    //I2C_1_Start();
    
    I2C_1_MasterWriteBuf(0x2A,(uint8 *)&txCBuf,2,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT));
    I2C_1_MasterClearStatus();
    txCBuf[1] = 0x09;
    I2C_1_MasterWriteBuf(0x2A,(uint8 *)&txCBuf,2,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT));
    I2C_1_MasterClearStatus();
}

void I2C_LCD_Position(uint8 row, uint8 column)
{
 
  if(row == 0){
    I2C_LCD_1_SetDDRAM(0x80u + column);
  }else{
    I2C_LCD_1_SetDDRAM(0xC0u + column);
  }
}

void I2C_LCD_Init(void)
{
    CyDelay(40u);     //40mS 待機
    I2C_LCD_1_FunctionSetNormal();
    I2C_LCD_1_ReturnHome();
    I2C_LCD_1_FunctionSetExtended();
    I2C_LCD_1_InternalOscFrequency();
    I2C_LCD_1_ContrastSet();
    I2C_LCD_1_PwrIconContrast();
    I2C_LCD_1_FollowerCtrl();
    CyDelay(200u);     //200mS 待機
    I2C_LCD_1_FunctionSetNormal();
    I2C_LCD_1_DisplayOn();
    I2C_LCD_1_Clear();
    I2C_LCD_1_EntryModeSet();
    CyDelay(1);    //I2C_LCD_1_WriteControl(0x0fu); //Disp:On Cursor:On Position:On
}

void init(void)
{
    PWM_Motor_a_Start();
    PWM_Motor_b_Start();    
    Motor_Right(0);
    Motor_Left(0);
    ADC_DelSig_Distance_Start();
    ADC_DelSig_Distance_StartConvert();
    AMux_D_Sensor_Start();
    UART_Line_Sensor_Start();
    I2C_1_Start();
    I2C_LCD_1_Start();
    I2C_LCD_Init();
    I2C_Color_init();
}