#include "Robotarm.h"

Robotarm arm;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.moveMidDeg(45,false);
  delay(1000);
  arm.moveMidDeg(45,true);
  delay(1000);
}

