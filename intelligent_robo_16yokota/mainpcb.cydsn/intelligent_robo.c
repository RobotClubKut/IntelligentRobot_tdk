#include <project.h>
#include <stdio.h>
#include "intelligent_robo.h"

void PID(Let *let)
{
    int16 dif_R,def1_R,def2_R,def3_R,operation_R;
    int16 dif_L,def1_L,def2_L,def3_L,operation_L;
    int16 count_Right;
    int16 count_Left;
    char value[20];
    
    count_Right = -QuadDec_Right_GetCounter();
    QuadDec_Right_SetCounter(0);
    count_Left = QuadDec_Left_GetCounter();
    QuadDec_Left_SetCounter(0);
    sprintf(value, "R=%4d L=%4d", count_Right, count_Left);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
    UART_Line_Sensor_PutString(value);
    
    def1_R = let->speed - count_Right;
    dif_R = (int16)(((def1_R - def2_R) * 0.3) + (def1_R * 0.3) + (((def1_R - def2_R) - (def2_R - def3_R)) * 0.3));
    operation_R = operation_R + dif_R;
    def3_R = def2_R;
    def2_R = def1_R;
    
    def1_L = let->speed - count_Left;
    dif_L = (int16)(((def1_L - def2_L) * 0.3) + (def1_L * 0.3) + (((def1_L - def2_L) - (def2_L - def3_L)) * 0.3));
    operation_L = operation_L + dif_L;
    def3_L = def2_L;
    def2_L = def1_L;
    
    Motor_Right(operation_R);
    Motor_Left(operation_L);
}

void approach(Let *let)
{
    uint8 speed = 80;    
    
    PSD_Sensor(let);
    Motor_Right(speed);
    Motor_Left(speed);
    if(let->d[1]>160)
    {
        Motor_Right(0);
        Motor_Left(0);
        let->mode = MODE_CATCH;
    }
}

void move(Let *let)
{
    static uint16 count = 0;
    uint16 limit = 300;
    
    if(let->place > 0)
    {
        Line_Trace(let,MODE_FORWARD);
    }
    count++;
    if(count == (limit*let->place))
    {
        count = 0;
        let->mode = MODE_SEEK;
    }
}

void Ball_Seek(Let *let)
{
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 d_count = 0;
    static uint16 limit = 1;
    uint8 speed = 80;
    
    if(step == 0)
    {
        /* PSDセンサの処理を追加 */
        PSD_Sensor(let);
        Motor_Right(speed);
        Motor_Left(-speed);
        limit = 100;
    }else
    if(step == 1)
    {
        Motor_Right(0);
        Motor_Left(0);
        limit = 20;
    }
    else
    if(step == 2)
    {
        /* PSDセンサの処理を追加 */
        PSD_Sensor(let);
        Motor_Right(-speed);
        Motor_Left(speed);
        limit = 200;
    }else
    if(step == 3)
    {
        Motor_Right(0);
        Motor_Left(0);
        limit = 20;
    }
    else
    if(step == 4)
    {
        Motor_Right(speed);
        Motor_Left(-speed);
        limit = 100;
    }else
    if(step == 5)
    {
        Motor_Right(0);
        Motor_Left(0);
        limit = 50;
    }
    /* ボールが見つからなかった時の処理 */
    else if(step == 6)
    {
        let->place++;
        Motor_Right(180);
        Motor_Left(175);
        limit = 110;
    }else
    if(step == 7)
    {
        Motor_Right(0);
        Motor_Left(0);
        limit = 30;
    }else
    if(step == 8)
    {
        step = 0;
        count = 0;
        return;
    }
    /* ボールを見つけた時の処理 */
    if(let->d[1] > 50)
    {
        limit = 7;
            if(limit == d_count)
            {
                Motor_Right(0);
                Motor_Left(0);
                let->mode = MODE_APPROACH;
                count = 0;
                d_count = 0;
                step = 0;
                return;
            }
        d_count++;
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

void Go_Ball_Area(Let *let){
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(let->area != 4)
    {
        Line_Trace(let, MODE_FORWARD);
    }
    else if(let->area == 4)
    {
        if(let->place > 0)
        {
            let->mode = MODE_MOVE;
            return;
        }
        if(step == 0)
        {
            Motor_Right(0);
            Motor_Left(0);
            limit = 100;
        }else
        if(step == 1)
        {
            Motor_Right(-150);
            Motor_Left(-150);
            limit = 100;
        }else
        if(step == 2)
        {
            Motor_Right(0);
            Motor_Left(0);
            let->mode = MODE_SEEK;
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
}

void Shooting_tennis_ball(Let *let){
    
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(let->area == 0)
    {
        Line_Trace(let, MODE_FORWARD);
    }
    else if(let->area == 1)
    {
        if(step == 0)
        {
            Motor_Right(150);
            Motor_Left(-20);
            limit = 120;
        }else 
        if(step == 1)
        {
            Motor_Right(0);
            Motor_Left(0);
            let->updown = DOWN;
            let->grab = RELEASE;
            limit = 10;
        }else
        if(step == 2)
        {
            let->updown = DOWN;
            limit = 100;
        }else
        if(step == 3)
        {
            let->updown = 470 + ((int)2.3 * count );
            Motor_Right(-150);
            limit = 100;
        }else
        if(step == 4)
        {
            Motor_Right(0);
            Motor_Left(0);
            let->mode = MODE_LINE_TRACE;
        }
           
        if(limit == count)
        {
            count = 0;
            step++;
            return;
        }
        count++;
    }
}

void Line_Trace(Let *let,uint8 mode){
    uint8 s = 0;
    static uint8 AreaFlag = 0;
    static uint8 aFlag = 0;
    static uint8 hFlag = 0;
    static uint16 count = 0;
    static double p = 0;
    static double p0 = 0;
    static double p1 = 0;
    static double p2 = 0;
    static double dif = 0;
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
        p0 = p;//13.6
        //dif += 13.6 * (p0-p1);//speed=200のとき
        dif += 13.6 * (p0-p1) +0.01 * p0 + 1.8 *((p0-p1) - (p1-p2));
        //0.01 * p0 
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
        /*
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
        */
    }

    //直した
    if(AreaFlag == 0)
    {
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
            aFlag = 0;
            hFlag = 0;
            AreaFlag = 1;
            /* 探査エリアに向かうならインクリメント */
            if(mode == MODE_FORWARD)
            {
                let->area++;
            }
            /* スタートに戻るならデクリメント */
            else if(mode == MODE_BACKWARD)
            {
                let->area--;
            }
        }
    }
    else
    {
        count++;
    }
    if(count == 15)
    {
        AreaFlag = 0;
        count = 0;
    }
    sprintf(value, "Area=%d",let->area);
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
    Sensor_LED_Write(1);
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
    I2C_1_MasterClearStatus();
    r = rxBuf[0]<< 8|rxBuf[1];
    g = rxBuf[2]<< 8|rxBuf[3];
    b = rxBuf[4]<< 8|rxBuf[5];
    
    I2C_LCD_1_Clear();
    sprintf(value, "r=%3d g=%3d",r,g);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString(value);
     sprintf(value, "b=%3d",b);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
    //色判断して構造体に格納
    
    //let->color = BLUE;
    //みたいな
}
void PSD_Sensor(Let *let){//0が右端
    uint8 i;
    char value[30];
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
    sprintf(value,"1=%3d 2=%3d 3=%3d\n", let->d[0], let->d[1], let->d[2]);
    UART_Line_Sensor_PutString(value);
}

//改良する予定
void Catch_Ball(Let *let){
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(step == 0)
    {
        let->grab = RELEASE;
        let->updown = UP;
        //PWM_Servo(GRAB_BALL,RELEASE);//450~1050
        //PWM_Servo(UPDOWN,600);
        limit = 100;
    }else
    if(step == 1)
    {
        let->updown = UP-(int)(2.3*count);
        //PWM_Servo(UPDOWN,600-(int)(2.6*count));
        limit = 100;
    }else
    if(step == 2)
    {
        let->grab = GRAB;
        //PWM_Servo(GRAB_BALL,1100);
        limit = 100;
    }else
    if(step == 3)
    {
        //カラーセンサーの処理を追加予定
        let->updown = DOWN+(int)(2.4*count);
        //PWM_Servo(UPDOWN,470+(int)(2.6*count));
        limit = 100;
    }else
    if(step == 4)
    {
        limit = 200;
    }
    else
    if(step == 5)
    {
        step = 0;
        let->mode = MODE_SHOOT;
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
    if(value>1100){
        value = 1100;
    }
    else if(value<450){
        value = 450;
    }
    if(id == UPDOWN){
        PWM_Servo_WriteCompare1(value);
    }
    else if(id == GRAB_BALL){
        PWM_Servo_WriteCompare2(value);
    }
}

void Motor_Right(int16 speed){
    
    int16 dif_R,def1_R,def2_R,def3_R,operation_R;
    int16 count_Right;
    char value[20];
    
    count_Right = -QuadDec_Right_GetCounter();
    QuadDec_Right_SetCounter(0);
    /*
    sprintf(value, "R=%4d L=%4d", count_Right, count_Left);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
    UART_Line_Sensor_PutString(value);
    */
    def1_R = speed - count_Right;
    dif_R = (int16)(((def1_R - def2_R) * 0.3) + (def1_R * 0.3) + (((def1_R - def2_R) - (def2_R - def3_R)) * 0.3));
    operation_R = operation_R + dif_R;
    def3_R = def2_R;
    def2_R = def1_R;
    
    if((0<operation_R)&&(operation_R<255))
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(operation_R);
    }
    else if((-255<operation_R)&&(operation_R<0))
    {
        PWM_Motor_a_WriteCompare1(-operation_R);
        PWM_Motor_a_WriteCompare2(0);
    }
    else
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(0);
    }
}

void Motor_Left(int16 speed){

    int16 dif_L,def1_L,def2_L,def3_L,operation_L;
    int16 count_Left;
    char value[20];

    count_Left = QuadDec_Left_GetCounter();
    QuadDec_Left_SetCounter(0);
    /*
    sprintf(value, "R=%4d L=%4d", count_Right, count_Left);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
    UART_Line_Sensor_PutString(value);
    */
    
    def1_L = speed - count_Left;
    dif_L = (int16)(((def1_L - def2_L) * 0.3) + (def1_L * 0.3) + (((def1_L - def2_L) - (def2_L - def3_L)) * 0.3));
    operation_L = operation_L + dif_L;
    def3_L = def2_L;
    def2_L = def1_L;
    
    if((0<operation_L)&&(operation_L<255))
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(operation_L);   
    }
    else if((-255<operation_L)&&(operation_L<0))
    {
        PWM_Motor_b_WriteCompare1(-operation_L);
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
    QuadDec_Right_Start();
    QuadDec_Left_Start();
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