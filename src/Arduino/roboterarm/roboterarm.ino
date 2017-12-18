#include "Robotarm.h"

Robotarm arm;

void onMoveToTop();
void onMoveToBot();
void onMoveToPos(int x,int y);

void setup()
{ 
  Serial.begin(9600);
  
  arm.getConCom()->onMoveToTop(&onMoveToTop);
  arm.getConCom()->onMoveToBot(&onMoveToBot);
  arm.getConCom()->onMoveToPos(&onMoveToPos);
  arm.getConCom()->onRotateToPos(&onRotateCommand);
  
  arm.begin();

  arm.moveToTop();
}

void loop()
{
  arm.update();
}

void onMoveToTop()
{
  arm.moveToTop();
}
void onMoveToBot()
{
  arm.moveToBot();
}
void onMoveToPos(int x,int y)
{
  arm.headDisable();
  arm.moveToTop();
  arm.midMoveDeg(x);
  arm.headEnable();
  arm.headMoveDeg(y);
}

void onRotateCommand(int deg, bool dir)
{
  arm.rotorEnable();
  arm.rotorMoveDeg(deg, dir);
  Serial.print("Rotate: ");
  Serial.print(deg);
  Serial.print(", ");
  Serial.println(dir);
}


