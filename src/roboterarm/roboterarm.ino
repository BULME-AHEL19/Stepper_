#include "Robotarm.h"

Robotarm arm;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.update();
}

