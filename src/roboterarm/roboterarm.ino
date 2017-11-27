#include "Robotarm.h"

Robotarm arm;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.moveMidDeg(90,false);
  delay(1000);
  arm.moveMidDeg(90,true);
  delay(1000);
  arm.moveHeadStep(1000,false);
  delay(1000);
  arm.moveHeadStep(1000,true);
  delay(1000);
}

