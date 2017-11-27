#include "Arduino.h"
#include "middlestepper.h"

MiddleStepper_::Stepper_(int dir, int step_, int en): 
  _dir(dir),
  _step(step_),
  _en(en)
{ 
  changeDir(false);
}

MiddleStepper_::~Stepper_()
{
  
}

void MiddleStepper_::begin()
{
  pinMode(_dir, OUTPUT);
  pinMode(_step, OUTPUT);
  pinMode(_en, OUTPUT);
  pinMode(_but_top, INPUT_PULLUP);
  pinMode(_but_bot, INPUT_PULLUP);
  digitalWrite(_en, LOW);
}

int MiddleStepper_::Step(int n, int stepDelay)
{
   Serial.print("step: ");
   Serial.println(n);
    
   int i;
   for(i = 0; i < n; i++)
   {
     moveOneStep(stepDelay);
   }
   return i;
}

void MiddleStepper_::moveOneStep(int stepDelay)
{
  digitalWrite(_step, HIGH);
  delayMicroseconds(stepDelay);
  digitalWrite(_step, LOW);
  delayMicroseconds(stepDelay);
}

void MiddleStepper_::changeDir(boolean d)
{
  motorDir = d;
  digitalWrite(_dir, motorDir);
}

int MiddleStepper_::getStepsFromDeg(int deg)
{
  return MIDDLE_STEPS_PER_DEG * (float)deg;
}

int MiddleStepper_::moveDeg(int deg)
{
  //deg -= 90;
  //deg = min(MAX_DEG,deg);
  //deg = max(MIN_DEG,deg);
  return Step(getStepsFromDeg(deg));
}

void MiddleStepper_::toggleDir()
{
  changeDir(!motorDir);
}

