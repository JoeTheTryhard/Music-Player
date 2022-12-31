/*
 * File:   main.c
 * Author: Josue
 *
 * Created on December 29, 2022, 8:21 PM
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
#define _XTAL_FREQ 4000000
#define DURATION 150
#define MUSIC_GPIO 0
void initialize()
{
    TRIS = 0b1000;
    OPTION = 0b11011111;
}
void playB(void)
{
    for (int i = 0; i<DURATION; i++)
    {
       GPIO ^= 1UL << MUSIC_GPIO;
       __delay_us(1013);
    }
}

void play2Nothing(void)
{
    for (int i = 0; i<DURATION; i++)
    {
       __delay_us(1013);
    }
}
void playNothing(void)
{
    for (int i = 0; i<DURATION/2; i++)
    {
       __delay_us(1013);
    }
}
void playF(void)
{
    for (int i = 0; i<2*DURATION; i++)
    {
       GPIO ^= 1UL << MUSIC_GPIO;
       __delay_us(676);
    }
}
void playA(void)
{
    for (int i = 0; i<2*DURATION; i++)
    {
       GPIO ^= 1UL << MUSIC_GPIO;
       __delay_us(568);
    }
}
void playTest(void)
{
    for (int i = 0; i<2*DURATION; i++)
    {
       GPIO ^= 1UL << MUSIC_GPIO;
       __delay_us(1);
    }
}
void main(void)
{
    initialize();
    while (1)
    {
        playB();
        play2Nothing();
        playF();
        playNothing();
        playA();
        playF();
        playB();
        playNothing();
        playF();
        playNothing();
        playA();
        playF();
    }
}
