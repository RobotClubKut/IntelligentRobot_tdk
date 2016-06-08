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
#include "Servo.h"

void Servo_Dataset(Servo_Data* servo, uint8 id, uint8 speed, uint8 stretch, int angle){
    servo->id = id;
    servo->speed = speed;
    servo->stretch = stretch;
    servo->angle = angle;
}

void EEPROM_rx(Servo_Data* servo){
    uint16 count = 0;
    uint8 i;
    unsigned char tx[2];
    unsigned char rx[68];
    char buf[32];
    tx[0] = 0xA0 | servo->id;
    tx[1] = 0x00;
    for(i = 0; i < 2; i++){
            UART_servo_PutChar(rx[i]);
    }
    for(i = 0; i < 68; i++){
        rx[i] = (unsigned char)UART_servo_GetChar();
    }
    UART_servo_ClearRxBuffer();
    for(i = 4; i < 68; i++){
        sprintf(buf, "%3d:0x%x\n", (int)(i - 3), (int)rx[i]);
        UART_PC_PutString(buf);
    }
}

void read_ID(void){
    uint16 count = 0;
    uint8 i, id;
    unsigned char tx[4];
    unsigned char rx[5];
    char buf[32];
    tx[0] = 0xFF;
    tx[1] = 0x00;
    tx[2] = 0x00;
    tx[3] = 0x00;
    for(i = 0; i < 4; i++){
        UART_servo_PutChar(tx[i]);
    }
    while(UART_servo_GetRxBufferSize() < 5){
        count += 1;
        if(count > 500){
            count = 0;
            sprintf(buf, "error: read_ID\n");
            UART_PC_PutString(buf);
        }
        CyDelayUs(1);
    }
    for(i = 0; i < 5; i++){
        rx[i] = (unsigned char)UART_servo_GetChar();
    }
    CyDelay(500);
    id = (uint16) rx[4] & 0x1F;
    sprintf(buf, "id:%d\n", (int)id);
    UART_PC_PutString(buf);
    UART_servo_ClearRxBuffer();
}

cystatus init_ID(uint8 id){
    uint16 count = 0;
    unsigned char tx[4];
    tx[0] = 0xE0 | id;
    tx[1] = 0x01;
    tx[2] = 0x01;
    tx[3] = 0x01;
    UART_servo_PutArray(tx, 4);
    while(UART_servo_GetRxBufferSize() < 5){
        count += 1;
        if(count > 500){
            count = 0;
            return CYRET_EMPTY;
        }
        CyDelayUs(1);
    }
    CyDelay(500);
    UART_servo_ClearRxBuffer();
    return CYRET_SUCCESS;
}

cystatus init_stretch(Servo_Data* servo){
    uint16 count = 0;
    unsigned char tx[3];
    tx[0] = 0xC0 | servo->id;
    tx[1] = 0x01;
    tx[2] = (unsigned char) servo->stretch;
    UART_servo_PutArray(tx, 3);
    while(UART_servo_GetRxBufferSize() < 6){
        count += 1;
        if(count > 500){
            count = 0;
            return CYRET_EMPTY;
        }
        CyDelayUs(1);
    }
    UART_servo_ClearRxBuffer();
    return CYRET_SUCCESS;
}

cystatus speed_set(Servo_Data* servo){
    uint16 count = 0;
    unsigned char tx[3];
    tx[0] = 0xC0 | servo->id;
    tx[1] = 0x02;
    tx[2] = (unsigned char) servo->speed;
    UART_servo_PutArray(tx, 3);
    CyDelay(1);
    UART_servo_ClearRxBuffer();
    return CYRET_SUCCESS;
}

void angle_set(Servo_Data* servo, int16 angle){
    uint16 pos;
    unsigned char tx[3];
    char buf[32];
    servo->angle = angle;
    pos = (angle * 29.6296296296296296f) + 7500;
    tx[0] = 0x80 | servo->id;
    tx[1] = (unsigned char)(pos >> 7) & 0x7F;
    tx[2] = (unsigned char) pos & 0x7F;
    UART_servo_PutArray(tx, 3);
    CyDelay(1);
}

void angle_get(uint8 id) {
    uint8 i;
    uint16 pos;
    int16 angle;
    unsigned char tx[3];
    unsigned char rx[6];
    char buf[32];
    tx[0] = 0x80 | id;
    tx[1] = 0x00;
    tx[2] = 0x00;
    UART_servo_PutArray(tx, 3);
    CyDelay(1);
    for(i = 0; i < 6; i++){
        rx[i] = (unsigned char) UART_servo_GetChar();
    }
    pos = (((uint16)rx[4] & 0x7f) << 7) | ((uint16)rx[5] & 0x7f);
    angle = ((int16)pos - 7500) / 29.6296296296296296f;
    if((angle >= -135) && (angle <= 135)) {
        sprintf(buf, "%d\n", (int)angle);
        UART_PC_PutString(buf);
    }
}

void angle_keep(uint16 pos){
    unsigned char tx[3];
    tx[0] = 0x80;
    tx[1] = (unsigned char)(pos >> 7) & 0x7F;
    tx[2] = (unsigned char) pos & 0x7F;
    UART_servo_PutArray(tx, 3);
    CyDelay(1);
}

/* [] END OF FILE */
