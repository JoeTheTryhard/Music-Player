/*
 * File:   main.c
 * Author: Josue
 *
 * Created on December 27, 2022, 6:09 PM
 * 
 * Documentation:
 * The output will be on GP0
 */

// PIC10F200 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable (GP3/MCLR pin function  is MCLR)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "MusicPlayer.h"


#define _XTAL_FREQ 4000000

void main(void)
{
    initialize();
    struct Track track1;
    struct Track track2;
    while(1)
    {
        track1.clocks = 16;
        track2.clocks = 31;
        playSound(&track1, &track2);
        track1.clocks = 0;
        track2.clocks = 0;
        playSound(&track1, &track2);
        playSound(&track1, &track2);
        playSound(&track1, &track2);
        track1.clocks = 10;
        track2.clocks = 0;
        playSound(&track1, &track2);
        track1.clocks = 0;
        track2.clocks = 0;
        playSound(&track1, &track2);
        playSound(&track1, &track2);
        playSound(&track1, &track2);
        track1.clocks = 8;
        track2.clocks = 0;
        playSound(&track1, &track2);
        track1.clocks = 0;
        track2.clocks = 0;
        playSound(&track1, &track2);
        track1.clocks = 10;
        track2.clocks = 0;
        playSound(&track1, &track2);
        track1.clocks = 0;
        track2.clocks = 0;
        playSound(&track1, &track2);
    }
}



