#ifndef INTELLIGENT_ROBO_H
#define INTELLIGENT_ROBO_H

#include <project.h>
#include <stdio.h>

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
    
/* Color */
#define RED                         11
#define GREEN                       12
#define BLUE                        13
    
/* Servo */
#define UPDOWN                      0
#define GRAB_BALL                   1
#define UP                          700
#define DOWN                        470
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

/* 構造体で管理 */
typedef struct{
    union Slave slave;
    uint8 speed;//速度
    uint8 mode;//モード
    uint8 area;//エリア
    uint8 line;//ライン
    uint8 number;//ボールの個数
    uint8 place;//SeekMode中の場所
    uint8 color;//色
    uint8 d[3];//PSDセンサーの値
    uint16 grab;
    uint16 updown;
}Let;

/* 大会用 */
void PID(Let *let);
void approach(Let *let);
void move(Let *let);
void Ball_Seek(Let *let);
void Go_Ball_Area(Let *let);
void Shooting_tennis_ball(Let *let);
void Catch_Ball(void);
void Line_Trace(Let *let,uint8 mode);
/* センサー系 */
void Color_Sensor(Let *let);
void PSD_Sensor(Let *let);
/* アクチュエータ系 */
void Motor_Right(int16 speed);
void Motor_Left(int16 speed);
void PWM_Servo(uint8 id,uint16 value);
/* 通信とか */
void init(void);
void I2C_Color_init(void);
void I2C_LCD_Position(uint8 row, uint8 column);
void I2C_LCD_Init(void);

#endif /* INTELLIGENT_ROBO_H */
