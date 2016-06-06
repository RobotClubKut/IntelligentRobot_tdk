#include "WS2812driver.h"

void isr_systick(){
    tick++;
    if( (tick&0xf) == 0 ){
        set_next_color();   // exec each 16ms
    }
}

// transfer & reset done
void isr_reset(){
    //transfer_LEDdriver();
}

// fifo empty. fill fifo.
void isr_fifo_empty(){
    if(current_led){
        transfer_LEDdriver();
    }
}

// start transfer
void transfer_LEDdriver(){
        unsigned char len;
    if(current_led+3<LED_LENGTH){
        WS2812driver_1_write2fifo((unsigned char*)&rgb[current_led], 9);
        current_led += 3;
    }else{
        len = LED_LENGTH - current_led;
        WS2812driver_1_write2fifo((unsigned char*)&rgb[current_led], len * 3);
        current_led = 0;
    }
}

// exec each 16ms
void set_next_color(){
    static unsigned char val;
    int i;
    
    // shift
    for(i=LED_LENGTH-1;i>0;i--){
        rgb[i].r = rgb[i-1].r;
        rgb[i].g = rgb[i-1].g;
        rgb[i].b = rgb[i-1].b;
    }
    
    if(val<32){
        rgb[0].r = val;
        rgb[0].g = 0;
        rgb[0].b = 32 - val;
    }else if(val<64){
        rgb[0].r = 64 - val;
        rgb[0].g = val - 32;
        rgb[0].b = 0;
    }else{
        rgb[0].r = 0;
        rgb[0].g = 96 - val;
        rgb[0].b = val - 64;
    }
    
    transfer_LEDdriver();
    
    if(val<96){
        val++;
    }else{
        val = 0;
    }
}