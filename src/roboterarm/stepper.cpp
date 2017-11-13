#include "Arduino.h"
#include "stepper.h"

Stepper_::Stepper_(int dir, int step_, int en, int but_bot, int but_top): 
  _dir(dir),
  _step(step_),
  _en(en),
  _but_bot(but_bot),
  _but_top(but_top)
{ 
  changeDir(false);
}

Stepper_::~Stepper_()
{
  
}

void Stepper_::begin()
{
  pinMode(_dir, OUTPUT);
  pinMode(_step, OUTPUT);
  pinMode(_en, OUTPUT);
  pinMode(_but_top, INPUT_PULLUP);
  pinMode(_but_bot, INPUT_PULLUP);
  digitalWrite(_en, LOW);
}

int Stepper_::getSteps(int delayTime)
{
  moveToEnd(delayTime);
  return moveToStart(delayTime);
}

int Stepper_::moveToStart(int delayTime)
{
  changeDir(true);
  return moveUntilHit(delayTime);
}

int Stepper_::moveToEnd(int delayTime)
{
  changeDir(false);
  return moveUntilHit(delayTime);
}

int Stepper_::moveUntilHit(int delayTime)
{
   int i;
   for(i = 0; !checkIfHit(); i++)
   {
     moveOneStep(delayTime);
   }
   return i;
}

int Stepper_::Step(int n, int stepDelay)
{
   Serial.print("step: ");
   Serial.println(n);
    
   int i;
   for(i = 0; i < n && !checkIfHit(); i++)
   {
     moveOneStep(stepDelay);
   }
   return i;
}

void Stepper_::moveOneStep(int stepDelay)
{
  digitalWrite(_step, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(_step, LOW);
  delayMicroseconds(stepDelay);
}

bool Stepper_::checkIfHit()
{
#ifdef STEPPER_H_DEBUG
  Serial.print("button_top: ");
  Serial.println(digitalRead(_but_top));
  Serial.print("button_bottom: ");
  Serial.println(digitalRead(_but_bot));
#endif
 
  if(!motorDir)
  {
    return !digitalRead(_but_bot);
  }
  else
  {
    return !digitalRead(_but_top);
  }
}

void Stepper_::changeDir(boolean d)
{
  motorDir = d;
  digitalWrite(_dir, motorDir);
}

int Stepper_::getStepsFromDeg(int deg)
{
  return STEPS_PER_DEG * deg;
}

int Stepper_::moveDeg(int deg)
{
  deg -= 90;
  deg = min(MAX_DEG,deg);
  deg = max(MIN_DEG,deg);
  deg -= MIN_DEG;
  return Step(getStepsFromDeg(deg));
}

void Stepper_::toggleDir()
{
  changeDir(!motorDir);
}

