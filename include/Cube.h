#ifndef CUBE_H
#define CUBE_H

#include "LED.h"

class Cube
{
    public:
        Cube();

        LED getAt(const int x, const int y, const int z);

        void update();

        virtual ~Cube();

    private:
        LED *leds[8][8][8];

        const int dataPin1 = A0;
        const int latchPin1 = A1;
        const int clockPin1 = A2;
        const int dataPin2 = 11;
        const int latchPin2 = 12;
        const int clockPin2 = 13;
        const int dataPin3 = 2;
        const int latchPin3 = 3;
        const int clockPin3 = 4;
        const int dataPin4 = 5;
        const int latchPin4 = 6;
        const int clockPin4 = 7;
        //CATHODE SHIFT REGISTER PIN DEFINES
        const int dataPinN = A3;
        const int latchPinN = A4;
        const int clockPinN = A5;

};

#endif
