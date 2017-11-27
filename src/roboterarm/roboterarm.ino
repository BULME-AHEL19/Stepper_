#include "Robotarm.h"

Robotarm arm;

void setup()
{ 
  Serial.begin(9600);
  arm.begin();
}

void loop()
{
  arm.moveMid(1000,false);
  delay(1000);
  arm.moveMid(1000,true);
  delay(1000);
}

