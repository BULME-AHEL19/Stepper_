#include "Robotarm.h"

Robotarm arm;
boolean dir = true;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.rotorHalfTurn(dir);
  delay(1000);
  dir = !dir;
}

