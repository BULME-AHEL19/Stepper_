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

  Serial.println("Moved to top");
}
void onMoveToBot()
{
  arm.moveToBot();

  Serial.println("Moved to bottom");
}
void onMoveToPos(int x,int y)
{
  arm.headDisable();
  arm.moveToTop();
  delay(100);
  arm.midMoveDeg(x);
  delay(100);
  arm.headEnable();
  arm.headMoveDeg(y);

  Serial.print("Moved to ");
  Serial.print(x);
  Serial.print(" and ");
  Serial.println(y);
}

void onRotateCommand(int deg, bool dir)
{
  arm.rotorEnable();
  arm.rotorMoveDeg(deg, dir);

  Serial.print("Rotated to ");
  Serial.print(deg);
  Serial.print(" with direction ");
  Serial.println(dir);
}


