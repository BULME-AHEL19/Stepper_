#include "Robotarm.h"

Robotarm arm;
boolean dir = false;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
  arm.moveToTop();
  arm.headMoveToTop();
}

void loop()
{
 arm.headMoveDeg(45,dir);
 delay(1000);
 arm.headMoveDeg(45,dir);
 delay(1000);
 dir = !dir;
}

