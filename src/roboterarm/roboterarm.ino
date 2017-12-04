#include "Robotarm.h"

Robotarm arm;
boolean dir = false;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.update();
  arm.headMoveDeg(45,dir);
  delay(1000);
  arm.headMoveDeg(45,dir);
  delay(1000);
  dir = !dir;
  
  arm.rotorMoveDeg(90,dir);
  delay(1000);
  arm.rotorMoveDeg(90,!dir);
}

