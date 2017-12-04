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
  _midStep.enable();
}
void Robotarm::midDisable()
{
  _midStep.disable();
}

void Robotarm::rotorMoveStep(int steps, boolean dir) 
{
  _rotorStep.changeDir(dir);
  _rotorStep.Step(steps);
}

void Robotarm::rotorMoveDeg(int deg, boolean dir)
{
  _rotorStep.changeDir(dir);
  _rotorStep.moveDeg(deg);
}

void Robotarm::rotorEnable()
{
  _rotorStep.enable();
}

void Robotarm::rotorDisable()
{
  _rotorStep.disable();
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

void Robotarm::headMoveToTop()
{
  _headStep.changeDir(true);
  while(!hitsTop())
  {
    _headStep.moveOneStep(SPEED);
  }
}

void Robotarm::headMoveToMax()
{
  headMoveToTop();
  headMoveDeg(90,false);
}

void Robotarm::headEnable()
{
  _headStep.enable();
}

void Robotarm::headDisable()
{
  _headStep.disable();
}

void Robotarm::moveToTop(int delayTime)
{
  headDisable();
  moveToBot();
  delay(delayTime);
  midMoveDeg(105,true);
  headEnable();
}
void Robotarm::moveToBot()
{
  _midStep.changeDir(false); 
  while(!hitsBot())
  {
    _midStep.moveOneStep(SPEED);
  }
}

void Robotarm::update()
{
  _conCom.update();
}

