#ifndef INTELLIGENT_ROBO_H
#define INTELLIGENT_ROBO_H

#include <project.h>
#include <stdio.h>
#include "WS2812driver.h"
    
/* Mode */
#define MODE_SHOOTING_TENNIS_BALL   1
#define MODE_LINE_TRACE             2
#define MODE_SEEK                   3
#define MODE_APPROACH               4
#define MODE_CATCH                  5
#define MODE_SHOOT                  6
#define MODE_MOVE                   7
#define MODE_DEBUG                  8
#define MODE_BACKWARD               9
#define MODE_FORWARD                10
#define MODE_RETURN                 11
#define MODE_START                  12
    
/* Color */
#define RED                         13
#define YELLO                       14
#define BLUE                        15
#define MISS                        16
    
/* Servo */
#define UPDOWN                      0
#define GRAB_BALL                   1
#define UP                          5500
#define DOWN                        7100
#define GRAB                        1050
#define RELEASE                     500
    
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
    double p;
    double p0;
    double p1;
    double p2;
    double dif;
}Status;
typedef struct{
    uint8 g_max;
    uint8 g_min;
}Color;
/* 構造体で管理 */
typedef struct{
    union Slave slave;
    Status status;
    uint16 speed;//速度
    uint8 mode;//モード
    int8 area;//エリア
    uint8 line;//ライン
    uint8 number;//ボールの個数
    uint8 place;//SeekMode中の場所
    uint8 color;//色
    uint8 d[3];//PSDセンサーの値
    uint16 grab;
    uint16 updown;
    uint16 count;
    double count_r;
}Let;

/* 大会用 */
void Ball_Shoot(Let *let);
void Return(Let *let);
void approach(Let *let);
void approach_2(Let *let);
void move(Let *let);
void Ball_Seek(Let *let);
void Go_Ball_Area(Let *let);
void Shooting_tennis_ball(Let *let);
void Catch_Ball(Let *let, Color *color);
void Line_Trace(Let *let,uint8 mode);
/* センサー系 */
void set_color(Let *let);
void Color_Sensor(Let *let, Color *color);
void PSD_Sensor(Let *let);
/* アクチュエータ系 */
void Start(Let *let);
void PID_Motor_Right(int16 pos);
void PID_Motor_Left(int16 pos);
void Motor_Right(int16 pos);
void Motor_Left(int16 pos);
void PWM_Servo(uint8 id,uint16 value);
void PID_init(Let *let);
/* 通信とか */
void init(void);
void I2C_Color_init(void);
void I2C_LCD_Position(uint8 row, uint8 column);
void I2C_LCD_Init(void);

#endif /* INTELLIGENT_ROBO_H */
