#include "Robotarm.h"

Robotarm arm;
boolean dir = true;

void onMoveCommand(int x,int y);

void setup()
{ 
  Serial.begin(9600);

  arm.getConCom()->onMoveToPos(&onMoveCommand);
  
  arm.begin();
}

void loop()
{
  /*arm.rotorHalfTurn(dir);
  delay(1000);
  dir = !dir;*/

  arm.update();
}

void onMoveCommand(int x,int y)
{
  arm.moveToTop();
  arm.midMoveDeg(x);
  arm.headEnable();
  arm.headMoveDeg(y);
}

