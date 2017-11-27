#include "Robotarm.h"

Robotarm::Robotarm()
{
  
}

Robotarm::~Robotarm()
{
  
}

void Robotarm::begin()
{
  _midStep.begin();
  _headStep.begin();

  pinMode(BUTTON_TOP,INPUT_PULLUP);
  pinMode(BUTTON_BOT,INPUT_PULLUP);
}

boolean Robotarm::hitsTop()
{
  return digitalRead(BUTTON_TOP) == LOW;
}

boolean Robotarm::hitsBot()
{
  return digitalRead(BUTTON_BOT) == LOW;
}

void Robotarm::midMoveStep(int steps, boolean dir)
{
  _midStep.changeDir(dir);
  _midStep.Step(steps);
}

void Robotarm::midMoveDeg(int deg, boolean dir)
{
  _midStep.changeDir(dir);
  _midStep.moveDeg(deg);
}

void Robotarm::midEnable()
{
  
}
void Robotarm::midDisable()
{
  
}

void Robotarm::headMoveStep(int steps,boolean dir)
{
  _headStep.changeDir(dir);
  _headStep.Step(steps);
}

void Robotarm::headMoveDeg(int deg, boolean dir = false)
{
  _headStep.changeDir(dir);
  _headStep.moveDeg(deg);
}

void Robotarm::headEnable()
{
  
}

void Robotarm::headDisable()
{
  
}

void Robotarm::moveToTop()
{
  headDisable();
  moveToBot();

  _midStep.changeDir(true);
  while(!hitsTop())
  {
    _midStep.moveOneStep(SPEED);
  }
}
void Robotarm::moveToBot()
{
  _midStep.changeDir(false); 
  while(!hitsBot())
  {
    _midStep.moveOneStep(SPEED);
  }
}

