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
/*
* init_IDとread_IDは出来るだけ使用しない様に
* サーボの種類が違う時、数珠繋ぎで動作しない場合あり
*/

#ifndef SERVO_H
#define SERVO_H

#include <project.h>
typedef struct{
    uint8 id;
    uint8 speed;
    uint8 stretch;
    int angle;
} Servo_Data;
void Servo_Dataset(Servo_Data*, uint8 id, uint8 speed, uint8 stretch, int angle);
void EEPROM_rx(Servo_Data*);
void read_ID(void);
cystatus init_ID(uint8 id);
cystatus init_stretch(Servo_Data*);
cystatus speed_set(Servo_Data*);
void angle_set(Servo_Data*, int16 angle);
void angle_get(uint8 id);
void angle_keep(uint16 pos);

#endif /* CYAPICALLBACKS_H */   
/* [] END OF FILE */
