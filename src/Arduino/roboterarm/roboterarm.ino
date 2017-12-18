#include "Robotarm.h"

Robotarm arm;

void onMoveToTop();
void onMoveToBot();
void onMoveToPos(int x,int y);

void setup()
{
  arm.getConCom()->onMoveToTop(&onMoveToTop);
  arm.getConCom()->onMoveToBot(&onMoveToBot);
  arm.getConCom()->onMoveToPos(&onMoveToPos);
  arm.begin();
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
  
}

