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

void Robotarm::moveMidStep(int steps, boolean dir)
{
  _midStep.changeDir(dir);
  _midStep.Step(steps);
}

void Robotarm::moveMidDeg(int deg, boolean dir)
{
  _midStep.changeDir(dir);
  _midStep.moveDeg(deg);
}

void Robotarm::moveHeadStep(int steps,boolean dir)
{
  _headStep.changeDir(dir);
  _headStep.Step(steps);
}

void Robotarm::moveHeadDeg(int deg, boolean dir = false)
{
  _headStep.changeDir(dir);
  _headStep.moveDeg(deg);
}

void Robotarm::moveToTop()
{
  
}
void Robotarm::moveToBot()
{
  
}

