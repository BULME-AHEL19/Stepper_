#include "Robotarm.h"

Robotarm arm;
boolean dir = true;

void onMoveCommand(int x,int y);
void onCommand(char command[][C_C_STR_SPLIT_LENGTH],int len);

void setup()
{ 
  Serial.begin(9600);

  arm.getConCom()->onMoveToPos(&onMoveCommand);
  arm.getConCom()->onCommand(&onCommand);
  
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

void onCommand(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
  if(len > 3) return;

  for(int i = 0;i<len;i++)
  {
    Serial.print("[");
    Serial.print(i);
    Serial.print("]: ");
    Serial.print(command[i]);
    Serial.print("\n");
  }
  Serial.print("\n\n");

  if(strcmp(command[0],"moveToTop") == 0)
  {
    arm.moveToTop();
  }
  else if(strcmp(command[0],"moveToBot") == 0)
  {
    arm.moveToBot();
  }
}

