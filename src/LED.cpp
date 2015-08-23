#include "LED.h"

LED::LED(char x, char y, char z)
{
    LED::x = x;
    LED::y = y;
    LED::z = z;
}

void setOn(bool value)
{
    on = value;
}

LED::~LED()
{

}
