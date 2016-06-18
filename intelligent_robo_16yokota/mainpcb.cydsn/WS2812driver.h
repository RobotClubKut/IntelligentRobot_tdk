#ifndef WS2812DRIVER_H
#define WS2812DRIVER_H

#include <project.h>

#define LED_LENGTH 8

typedef struct _RGB_tag{
	unsigned char g;
	unsigned char r;
	unsigned char b;
} rgb_tag;

rgb_tag rgb[LED_LENGTH];
unsigned int tick, current_led;

void isr_systick();
void isr_reset();
void isr_fifo_empty();
void transfer_LEDdriver();
void set_next_color();
#endif /* WS2812DRIVER_H */