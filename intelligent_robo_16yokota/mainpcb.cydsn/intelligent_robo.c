#include <project.h>
#include <stdio.h>
#include "intelligent_robo.h"

void Color_Sensor(Let *let)
{
    uint8 r=0,g=0,b=0,x=0;
    unsigned char txReadStatus = 0x03;
    unsigned char rxBuf[8] = {1,0,0,0,0,0,0,0};
    char value[40];
    //Debug_LED_Write(1);
    Sensor_LED_Write(1);
    I2C_1_MasterWriteBuf(0x2A,(uint8*)&txReadStatus,1,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_WR_CMPLT));
    /*
    {
        if(g_timerFlag==1){
            x++;
        }
        if(x>50){
            Debug_LED_Write(1);
            I2C_Color_init();
            x = 0;
            break;
        }
        g_timerFlag=0;
    }*/
    I2C_1_MasterClearStatus();
    I2C_1_MasterReadBuf(0x2A,(uint8 *)&rxBuf,8,I2C_1_MODE_COMPLETE_XFER);
    while(0u==(I2C_1_MasterStatus() & I2C_1_MSTAT_RD_CMPLT));
    /*
    {
        if(g_timerFlag==1){
            x++;
        }
        if(x>50){
            Debug_LED_Write(1);
            I2C_Color_init();
            x = 0;
            break;
        }
        g_timerFlag=0;
    }
    */
    I2C_1_MasterClearStatus();
    r = rxBuf[0]<< 8|rxBuf[1];
    g = rxBuf[2]<< 8|rxBuf[3];
    b = rxBuf[4]<< 8|rxBuf[5];
    
    I2C_LCD_1_Clear();
    //色判断して構造体に格納
    if((r > b) && (g > b))
    {
        if(r < g)
        {
            let->color = YELLO;
            I2C_LCD_Position(1u,7u);
            I2C_LCD_1_PrintString("YELLO");
        }
        else if(r > g)
        {
            let->color = RED;
            I2C_LCD_Position(1u,7u);
            I2C_LCD_1_PrintString("RED");
        }
    }
    else if((g > b) && (b > r))
    {
        let->color = BLUE;
        I2C_LCD_Position(1u,7u);
        I2C_LCD_1_PrintString("BLUE");
    }
    if(((45<r)&&(r<70))&&((70<g)&&(g<98))&&((20<b)&&(b<40)))
    {
        let->color = MISS;
        I2C_LCD_Position(1u,7u);
        I2C_LCD_1_PrintString("MISS");
    }
    /*
    sprintf(value, "r=%3d g=%3d",r,g);
    I2C_LCD_Position(0u,0u);
    I2C_LCD_1_PrintString(value);
    sprintf(value, "b=%3d",b);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
    
    sprintf(value, "r=%3d g=%3d b=%3d\n",r,g,b);
    UART_Line_Sensor_PutString(value);
    */
    return;
}


void Ball_Shoot(Let *let)
{
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(let->color == BLUE)
    { 
        if(step == 0)
        {
            Motor_Right(0);
            Motor_Left(0);   
            let->updown = 4000;
            limit = 50;
        }else 
        if(step == 1)
        {
            let->updown = DOWN;
            let->grab = RELEASE;
            limit = 100;
        }else
        if(step == 2)
        {
            let->updown = UP;
            PID_Motor_Right(-150);
            PID_Motor_Left(150);
            limit = 110;
        }else
        if(step == 3)
        {
            Motor_Right(0);
            Motor_Left(0);
            limit = 0;
            step = 0;
            let->color = MISS;
            let->area++;
            let->mode = MODE_LINE_TRACE;
        }
    }
    else
    {
        if(step == 0)
        {
            PID_Motor_Right(-150);
            PID_Motor_Left(150);
            limit = 70;
        }else 
        if(step == 1)
        {
            Motor_Right(0);
            Motor_Left(0);
            let->updown = DOWN;
            let->grab = RELEASE;
            limit = 100;
        }else
        if(step == 2)
        {
            let->updown = UP;
            PID_Motor_Right(-150);
            PID_Motor_Left(150);
            limit = 60;
        }else
        if(step == 3)
        {
            Motor_Right(0);
            Motor_Left(0);
            limit = 0;
            step = 0;
            let->area++;
            let->mode = MODE_LINE_TRACE;
        }
    }
    
    if(limit == count)
    {
        count = 0;
        step++;
        return;
    }
    count++;
}

void Return(Let *let)
{
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    Sensor_LED_Write(0);
    if(let->place == 0)
    {
        if(step == 0)
        {
            Motor_Right(-3500);
            Motor_Left(-3500);
            //limit = let->count + let->place*40;
            limit = let->count;
        }else
        if(step == 1)
        {
            if(let->count_r>0)
            {
                
                Motor_Right(-3000);
                Motor_Left(3000);
                limit = let->count_r;
            }
            if(let->count_r<=0)
            {
                Motor_Right(-3000);
                Motor_Left(3000);
                limit = -let->count_r;
                //limit = 100;
            }
        }else
        if(step == 2)
        {
            if((Switch_L_Read() == 1) && (Switch_R_Read() == 1))
            {
                step++;
                Motor_Right(0);
                Motor_Left(0);
                count = 0;
                return;
            }
            else
            {
                Motor_Right(-4000);
                Motor_Left(-4000);
                limit = 0;
            }
        }else
        if(step == 3)
        {
            Motor_Right(7000);
            Motor_Left(0);
            limit = 80;
        }else
        if(step == 4)
        {
            Motor_Right(4000);
            Motor_Left(4000);
            let->area = 3;
            UART_Line_Sensor_ClearRxBuffer();
            PID_init(let);
            limit = 200;
        }else
        if(step == 5)
        {
            Line_Trace(let,MODE_BACKWARD);
            limit = 0;
        }
    }
    if(let->color == RED)
    {
        if(let->area == 0)
        {
            Motor_Right(0);
            Motor_Left(0);
            count = 0;
            step = 0;
            let->mode = MODE_SHOOT;
        }
    }
    else if(let->color == YELLO)
    {
        if(let->area == 1)
        {
            Motor_Right(0);
            Motor_Left(0);
            count = 0;
            step = 0;
            let->mode = MODE_SHOOT;
        }
    }
    else if(let->color == BLUE)
    {
        if(let->area == 2)
        {
            Motor_Right(0);
            Motor_Left(0);
            count = 0;
            step = 0;
            let->mode = MODE_SHOOT;
        }
    }
    
    count++;
    if(limit == count)
    {
        count = 0;
        step++;
        return;
    }
}

void approach(Let *let)
{
    const uint16 speed = 90;
    static uint8 flg = 0;
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    if(flg == 0){    
        if(let->d[1]<145){
            Motor_Right(3500);
            Motor_Left(3500);
            let->count++;
        }
        else if((let->d[1]>145) && (let->d[1]<155))
        {
            if(let->d[0]>110)
            {
                Motor_Right(-2000);
                Motor_Left(2000);
            }
            else if(let->d[2]>110)
            {
                Motor_Right(2000);
                Motor_Left(-2000);
            }
            else 
            {
                Motor_Right(0);
                Motor_Left(0);
                let->d[1] = 0;
                let->mode = MODE_CATCH;
            }
        }
        else if(let->d[1] >= 155)
        {        
            flg = 1;
        }
        if(let->d[2] > 115)
        {
            Motor_Right(2000);
            Motor_Left(-2000);
        }
        else if(let->d[0] > 125)
        {
            Motor_Right(-2000);
            Motor_Left(2000);
        }   
    }
    else if(flg == 1)
    {
        Motor_Right(-3000);
        Motor_Left(-3000);
        if(let->d[1] < 155)
        {
            Motor_Right(0);
            Motor_Left(0);
            flg = 0;
            let->d[1] = 0;
            let->mode = MODE_CATCH;
        }
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
    static uint16 limit = 1;
    uint16 speed = 3000;
    
    /* ボールを見つけた時の処理 */
    if((let->d[1] > 55) &&(let->d[1] < 255))
    {
        Motor_Right(0);
        Motor_Left(0);
        let->mode = MODE_APPROACH;
        count = 0;
        step = 0;
        let->d[1] = 0;
        return;
    }
    else
    {
        if(step == 0)
        {
            /* PSDセンサの処理を追加 */
            Motor_Right(speed);
            Motor_Left(-speed);
            limit = 80;
            let->count_r--;
            //PSD_Sensor(let);
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
            Motor_Right(-speed);
            Motor_Left(speed);
            
            limit = 150;
            let->count_r++;
            //PSD_Sensor(let);
        }else
        if(step == 3)
        {
            Motor_Right(0);
            Motor_Left(0);
            //PID_Motor(0,0);
            limit = 20;
        }
        else
        if(step == 4)
        {
            Motor_Right(speed);
            Motor_Left(-speed);
            //PID_Motor(speed,-speed);
            limit = 80;
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
            Motor_Right(7000);
            Motor_Left(7000);
            //PID_Motor(220,220);
            limit = 40;
        }else
        if(step == 7)
        {
            Motor_Right(0);
            Motor_Left(0);
            //PID_Motor(0,0);
            limit = 40;
        }else
        if(step == 8)
        {
            step = 0;
            count = 0;
            let->count_r = 0;
            let->place++;
            return;
        }
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
            limit = 50;
        }else
        if(step == 1){
            PID_Motor_Left(0);
            PID_Motor_Right(0);
            limit = 50;
        }
        else
        if(step == 2)
        {
            Motor_Right(-7000);
            Motor_Left(-7000);
            limit = 60;
        }else
        if(step == 3)
        {
            Motor_Right(0);
            Motor_Left(0);   
            limit = 50;
        }
        else
        if(step == 4)
        {
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
            Motor_Right(7000);
            Motor_Left(-200);
            limit = 80;
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
            let->updown = UP;
            Motor_Right(-7000);
            limit = 75;
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
        //dif += 29.0 * (p0-p1);
        dif += 27.0 * (p0-p1) +0.1 * p0 + 2.5 *((p0-p1) - (p1-p2));
        //0.01 * p0 
        if(dif > let->speed)
        {
            dif = let->speed;
        }
        else if(dif < -let->speed)
        {
            dif = -let->speed;
        }
        Motor_Right(let->speed - (int)(dif*60));
        Motor_Left(let->speed + (int)(dif*60));
        /*
        sprintf(value,"dif=%4d\n",(int)dif);
        UART_Line_Sensor_PutString(value);
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
    I2C_LCD_1_Clear();
    sprintf(value, "Area=%d",let->area);
    I2C_LCD_Position(1u,0u);
    I2C_LCD_1_PrintString(value);
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
    /*
    sprintf(value,"1=%3d 2=%3d 3=%3d\n", let->d[0], let->d[1], let->d[2]);
    UART_Line_Sensor_PutString(value);
    */
}

//完成
void Catch_Ball(Let *let){
    static uint8 step = 0;
    static uint16 count = 0;
    static uint16 limit = 1;
    
    Motor_Right(0);
    Motor_Left(0);
    if(step == 0)
    {
        let->grab = RELEASE;
        let->updown = UP;
        limit = 100;
    }else
    if(step == 1)
    {
        let->updown = DOWN;
        limit = 100;
    }else
    if(step == 2)
    {
        let->grab = GRAB;
        limit = 100;
    }else
    if(step == 3)
    {
        let->updown = 3600;
        limit = 100;
    }else
    if(step == 4)
    {
        let->grab = 970;
        limit = 10;
    }else
    if(step == 5)
    {
        let->grab = 1050;    
        limit = 10;
    }
    else
    if(step == 6)
    {
        Color_Sensor(let);
        limit = 20;
    }
    else
    if(step == 7)
    {
        step = 0;
        let->mode = MODE_RETURN;
        return;
    }
    count++;
    if(limit == count)
    {
        count = 0;
        step++;
        return;
    }
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

void PID_Motor_Right(int16 pos){
    
    static int16 dif_R = 0;
    static int16 def1_R = 0;
    static int16 def2_R = 0;
    static int16 def3_R = 0;
    static int16 operation_R = 0;
    static int16 count_Right_1 = 0;
    double rps;
    double speed;
    int16 count_Right;
    char value[20];
    
    count_Right = -QuadDec_Right_GetCounter();
    QuadDec_Right_SetCounter(0);
    if((count_Right - count_Right_1 <= 5) && (count_Right - count_Right_1 >= -5))
    {
        count_Right_1 = count_Right;
        rps = 0.09765625f*count_Right;
        speed = rps * 188.4955592;
        
        def1_R = pos - speed;
        dif_R = (int16)(((def1_R - def2_R) *17.0) + (def1_R * 3.0)
        + (((def1_R - def2_R) - (def2_R - def3_R)) * 0.5));
        operation_R = operation_R + dif_R;
        def3_R = def2_R;
        def2_R = def1_R;
    }
    /*
    sprintf(value,"R=%4d speed=%d opeR=%d\n",count_Right,(int)speed,operation_R);
    UART_Line_Sensor_PutString(value);
    */
    if((0 < operation_R)&&(operation_R < 10000))
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(operation_R);
    }
    else if((-10000 < operation_R)&&(operation_R < 0))
    {
        PWM_Motor_a_WriteCompare1(-operation_R);
        PWM_Motor_a_WriteCompare2(0);
    }
    else if(operation_R >= 10000)
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(10000);   
    }
    else if(operation_R <= -10000)
    {
        PWM_Motor_a_WriteCompare1(10000);
        PWM_Motor_a_WriteCompare2(0);    
    }
    else
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(0);
    }
    return;
}

void PID_Motor_Left(int16 pos){

    static int16 dif_L = 0;
    static int16 def1_L = 0;
    static int16 def2_L = 0;
    static int16 def3_L = 0;
    static int16 operation_L = 0;
    static int16 count_Left_1 = 0;
    int16 count_Left;
    double rps = 0;
    double speed = 0;
    char value[50];

    count_Left = QuadDec_Left_GetCounter();
    QuadDec_Left_SetCounter(0);
    if((count_Left - count_Left_1 <= 5) && (count_Left - count_Left_1 >= -5))
    {
        count_Left_1 = count_Left;
        rps = 0.09765625f*count_Left;
        speed = rps * 188.4955592;
        
        def1_L = pos - speed;
        dif_L = (int16)(((def1_L - def2_L) *17.0) + (def1_L * 3.0)
        + (((def1_L - def2_L) - (def2_L - def3_L)) * 0.5));
        operation_L = operation_L + dif_L;
        def3_L = def2_L;
        def2_L = def1_L;
    }
    /*
    sprintf(value,"L=%4d speed=%d opeL=%d\n", count_Left,(int)speed,operation_L);
    UART_Line_Sensor_PutString(value);
    */
    if((0 < operation_L)&&(operation_L < 10000))
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(operation_L);   
    }
    else if((-10000 < operation_L)&&(operation_L < 0))
    {
        PWM_Motor_b_WriteCompare1(-operation_L);
        PWM_Motor_b_WriteCompare2(0);
    }
    else if(operation_L >= 10000)
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(10000);   
    }
    else if(operation_L <= -10000)
    {
        PWM_Motor_b_WriteCompare1(10000);
        PWM_Motor_b_WriteCompare2(0);   
    }
    else
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(0);
    }
    return;
}

void Motor_Right(int16 pos){

    if((0 < pos)&&(pos < 10000))
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(pos);
    }
    else if((-10000 < pos)&&(pos < 0))
    {
        PWM_Motor_a_WriteCompare1(-pos);
        PWM_Motor_a_WriteCompare2(0);
    }
    else if(pos >= 10000)
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(10000);   
    }
    else if(pos <= -10000)
    {
        PWM_Motor_a_WriteCompare1(10000);
        PWM_Motor_a_WriteCompare2(0);    
    }
    else
    {
        PWM_Motor_a_WriteCompare1(0);
        PWM_Motor_a_WriteCompare2(0);    
    }
    QuadDec_Right_SetCounter(0);
    return;
}

void Motor_Left(int16 pos){

    if((0 < pos)&&(pos < 10000))
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(pos);   
    }
    else if((-10000 < pos)&&(pos < 0))
    {
        PWM_Motor_b_WriteCompare1(-pos);
        PWM_Motor_b_WriteCompare2(0);
    }
    else if(pos >= 10000)
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(10000);   
    }
    else if(pos <= -10000)
    {
        PWM_Motor_b_WriteCompare1(10000);
        PWM_Motor_b_WriteCompare2(0);   
    }
    else
    {
        PWM_Motor_b_WriteCompare1(0);
        PWM_Motor_b_WriteCompare2(0);    
    }
    QuadDec_Left_SetCounter(0);
    return;
}

void PID_init(Let *let)
{
    let->status.p = 0;
    let->status.p0 = 0;
    let->status.p1 = 0;
    let->status.p2 = 0;
    let->status.dif = 0;
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