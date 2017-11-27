#include "Robotarm.h"

Robotarm arm;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
  arm.moveToTop();
}

void loop()
{
}

