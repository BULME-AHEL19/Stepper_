#include "Arduino.h"
#include "stepper.h"

Stepper_::Stepper_(int dir, int step_, int en, int but_bot, int but_bot): 
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

int Stepper_::getSteps()
{
  moveToEnd(400);
  return moveToStart(400);
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
  Serial.println(digitalRead(BUTTON_TOP));
  Serial.print("button_bottom: ");
  Serial.println(digitalRead(BUTTON_BOTTOM));
#endif 
 
  if(!motorDir)
  {
    return !digitalRead(BUTTON_BOTTOM);
  }
  else
  {
    return !digitalRead(BUTTON_TOP);
  }
}

void Stepper_::changeDir(boolean d)
{
  motorDir = d;
  digitalWrite(_dir, motorDir);
}
