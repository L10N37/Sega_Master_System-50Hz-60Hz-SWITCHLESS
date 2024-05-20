/*
 * File:   newmain.c
 * Author: vajskids
 *
 * Created on 21 May 2024
 */


#include <xc.h>

// Configuration bits
#pragma config FOSC = INTRCIO // Internal oscillator, I/O function on GP4/5
#pragma config WDTE = OFF     // Watchdog Timer disabled
#pragma config PWRTE = OFF    // Power-up Timer disabled
#pragma config MCLRE = OFF    // MCLR pin function is digital I/O
#pragma config BOREN = OFF    // Brown-out Reset disabled
#pragma config CP = OFF       // Code Protection disabled
#define _XTAL_FREQ 4000000


void setup() {
    ANSEL = 0x00;        //All pins digital IO
    TRISIO = 0B00000100; //GP2 as input
    
    /*
     * Give console a second to init, it will start in native 50Hz momentarily and give the set
     * a chance to lock the correct sub carrier before flicking modes. It will transition to 60Hz
     * after power up (Unless holding Pause to deliberately boot into PAL 50Hz). This gave my sets
     * full colour in 60Hz mode over composite, even though it had flicked across into 60Hz 480i.
     * When changing this value to =<500ms it will boot straight into 60Hz 480i but composite was in 
     * black and white.
    */
    __delay_ms(1000);    
}

void main() {
    setup();

    while(1) {
        if (GPIObits.GP2 == 1){    //pause not pressed, set VDP 50/60Hz pin LOW
            GPIObits.GP0 = 0; 
        }
        if (GPIObits.GP2 == 0){    //pause not pressed, set VDP 50/60Hz pin HIGH
            GPIObits.GP0 = 1; 
        }

        asm("SLEEP"); // Job done, put the MCU to sleep
    }
}
