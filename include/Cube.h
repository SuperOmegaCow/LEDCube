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
};

#endif
