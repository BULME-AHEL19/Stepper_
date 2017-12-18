#include "Robotarm.h"

Robotarm arm;

void onMoveToTop();
void onMoveToBot();
void onMoveToPos(int x,int y);
void onEnable(char which[30]);
void onDisable(char which [30]);

void setup()
{ 
  Serial.begin(9600);
  
  arm.getConCom()->onMoveToTop(&onMoveToTop);
  arm.getConCom()->onMoveToBot(&onMoveToBot);
  arm.getConCom()->onMoveToPos(&onMoveToPos);
  arm.getConCom()->onRotateToPos(&onRotateCommand);
  arm.getConCom()->onEnable(&onEnable);
  arm.getConCom()->onDisable(&onDisable);
  
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
  delay(100);
  arm.midMoveDeg(x);
  delay(100);
  arm.headEnable();
  arm.headMoveDeg(y);
}

void onRotateCommand(int deg, bool dir)
{
  arm.rotorEnable();
  arm.rotorMoveDeg(deg, dir);
}

void onEnable(char which[30])
{
  if(strcmp(which,"mid") == 0)
    arm.midEnable();
  else if(strcmp(which,"head") == 0)
    arm.headEnable();
  else if(strcmp(which,"rotor") == 0)
    arm.rotorEnable();
  else if(strcmp(which,"ALL") == 0)
  {
    arm.midEnable();
    arm.headEnable();
    arm.rotorEnable();    
  }
}
void onDisable(char which [30])
{
  if(strcmp(which,"mid") == 0)
    arm.midDisable();
  else if(strcmp(which,"head") == 0)
    arm.headDisable();
  else if(strcmp(which,"rotor") == 0)
    arm.rotorDisable();
  else if(strcmp(which,"ALL") == 0)
  {
    arm.midDisable();
    arm.headDisable();
    arm.rotorDisable();    
  }
}


