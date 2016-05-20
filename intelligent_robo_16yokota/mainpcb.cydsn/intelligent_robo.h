#ifndef INTELLIGENT_ROBO_H
#define INTELLIGENT_ROBO_H

#include <project.h>
#include <stdio.h>
    
#define UPDOWN 0
#define GRAB 1
    
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
    uint8 speed;//速度
    uint8 mode;//モード
    uint8 area;//エリア
    uint8 line;//ライン
    uint8 number;//ボールの個数
    uint8 color;//色
    uint8 d[3];//PSDセンサーの値
}Let;


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

#endif /* INTELLIGENT_ROBO_H */
