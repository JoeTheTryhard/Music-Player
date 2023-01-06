/* 
 * File:   MusicPlayer.h
 * Author: Josue
 *
 * Created on January 1, 2023, 3:59 PM
 */

#ifndef MUSICPLAYER_H
#define	MUSICPLAYER_H

#define DURATION 6000 // Value must be between 0 and 65535

void initialize()
{
    TRIS = 0b1000;
    OPTION = 0b11010101; //Set the correct prescaler for the option register, bit 3
}

struct Track
{
    unsigned char clocks;//frequency of the sound
    unsigned char lastTimeUpdate;
};


void toggleSound(struct Track* track, unsigned char pinNumber, unsigned char initialTMR0)
{
    if (initialTMR0 == (unsigned char)((*track).lastTimeUpdate+((*track).clocks)) && (*track).clocks !=0)
    {
        GPIO ^= 1UL << pinNumber;
        TMR0 = initialTMR0;
        (*track).lastTimeUpdate = initialTMR0;
    } 
}

void playSound(struct Track* track1, struct Track* track2)
{
    for (unsigned short counter = 0; counter<DURATION; counter++)
    {
        toggleSound(track1, 0, TMR0);
        toggleSound(track2, 1, TMR0);
    }


}

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MUSICPLAYER_H */

