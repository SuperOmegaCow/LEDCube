#include "Cube.h"

Cube::Cube()
{
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            for(int z = 0; z < 8; z++)
            {
                leds[x][y][y] = new LED(x + 1, y + 1, z + 1);
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

}

Cube::~Cube()
{

}
