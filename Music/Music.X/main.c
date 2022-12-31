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
#define _XTAL_FREQ 4000000

void initialize(void)
{
    TRIS = 0b1000;
    OPTION = 0b11010101; //Set the correct prescaler for the option register, bit 3
}
struct Sound
{
    unsigned char clocks;//frequency of the sound
    unsigned char lastTimeUpdate;
};


void toggleSound(struct Sound* sound, unsigned char pinNumber, unsigned char initialTMR0)
{
    if (initialTMR0 == (unsigned char)((*sound).lastTimeUpdate+((*sound).clocks)))
    {
        GPIO ^= 1UL << pinNumber;
        TMR0 = initialTMR0;
        (*sound).lastTimeUpdate = initialTMR0;
    }
    
}

void main(void)
{
    initialize();
    struct Sound track1 = {50, TMR0};
    struct Sound track2 = {100, TMR0};
    while(1)
    {
        toggleSound(&track1, 0, TMR0);
        toggleSound(&track2, 1, TMR0);
    }
}
