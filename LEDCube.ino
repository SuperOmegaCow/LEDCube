#include <Arduino.h>
#include "Cube.h"

void setup()
{
	Serial.begin(9600);

	pinMode(13, OUTPUT);
}

void loop()
{

    new Cube();
	Serial.println("Hello world!");

	delay(1000);
	digitalWrite(13, HIGH);
	delay(1000);
	digitalWrite(13, LOW);
}
