#include "Cube.h"

Cube::Cube()
{

    pinMode(dataPin0, OUTPUT);
    pinMode(latchPin0, OUTPUT);
    pinMode(clockPin0, OUTPUT);
    pinMode(dataPin1, OUTPUT);
    pinMode(latchPin1, OUTPUT);
    pinMode(clockPin1, OUTPUT);
    pinMode(dataPin2, OUTPUT);
    pinMode(latchPin2, OUTPUT);
    pinMode(clockPin2, OUTPUT);
    pinMode(dataPin3, OUTPUT);
    pinMode(latchPin3, OUTPUT);
    pinMode(clockPin3, OUTPUT);
    pinMode(dataPinN, OUTPUT);
    pinMode(latchPinN, OUTPUT);
    pinMode(clockPinN, OUTPUT);

    for(int x = 1; x <= 8; x++) {
        for(int y = 1; y <= 8; y++) {
            for(int z = 1; z <= 8; z++)
            {
                leds[x][y][y] = new LED(x, y, z);
            }
        }
    }
}

LED Cube::getAt(int x, int y, int z)
{
    return leds[x][y][z];
}

void Cube::update()
{
    for(int z = 2; z <= 8; z += 2)
    {
        int xAdd = 0;
        for(int x = 1; x <= 8; x++)
        {
            int yAdd = 0;
            for(int y = 1; y <= 8; y++) {
                LED led = leds[x][y][z];
                if(led.on)
                {
                    xAdd += 2^x;
                    yAdd += 2^y;
                }
            }
        }
        digitalWrite(latchPin0, LOW);
        digitalWrite(latchPin1, LOW);
        digitalWrite(latchPin2, LOW);
        digitalWrite(latchPin3, LOW);
        if(z == 1)
            {
            shiftOut(dataPin0, clockPin0, MSBFIRST, xAdd);
        } else if(z == 3)
        {
            shiftOut(dataPin1, clockPin1, MSBFIRST, xAdd);
        } else if(z == 5)
        {
            shiftOut(dataPin2, clockPin2, MSBFIRST, xAdd);
        } else if(z == 7)
        {
            shiftOut(dataPin3, clockPin3, MSBFIRST, xAdd);
        }
        digitalWrite(latchPinN, LOW);
        shiftOut(dataPinN, clockPinN, MSBFIRST, yAdd);
        digitalWrite(latchPinN, HIGH);

    }

    for(int z = 1; z <= 7; z += 2)
    {
        int xAdd = 0;
        for(int x = 1; x <= 8; x++)
        {
            int yAdd = 0;
            for(int y = 1; y <= 8; y++) {
                LED led = leds[x][y][z];
                if(led.on)
                {
                    xAdd += 2^x;
                    yAdd += 2^y;
                }
            }
        }
        if(z == 1) {
            shiftOut(dataPin0, clockPin0, MSBFIRST, xAdd);
        } else if(z == 3)
        {
            shiftOut(dataPin1, clockPin1, MSBFIRST, xAdd);
        } else if(z == 5)
        {
            shiftOut(dataPin2, clockPin2, MSBFIRST, xAdd);
        } else if(z == 7)
        {
            shiftOut(dataPin3, clockPin3, MSBFIRST, xAdd);
        }
        //Write verticle
        digitalWrite(latchPin0, HIGH);
        digitalWrite(latchPin1, HIGH);
        digitalWrite(latchPin2, HIGH);
        digitalWrite(latchPin3, HIGH);
        digitalWrite(latchPinN, LOW);
        shiftOut(dataPinN, clockPinN, MSBFIRST, yAdd);
        digitalWrite(latchPinN, HIGH);
    }
}

Cube::~Cube()
{

}
