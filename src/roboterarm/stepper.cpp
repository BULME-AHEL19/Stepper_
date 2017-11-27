#include "Arduino.h"
#include "stepper.h"

Stepper_::Stepper_(int dir, int step_, int en): 
  _dir(dir),
  _step(step_),
  _en(en)
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
  digitalWrite(_en, LOW);
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

void Stepper_::changeDir(boolean d)
{
  motorDir = d;
  digitalWrite(_dir, motorDir);
}

void Stepper_::toggleDir()
{
  changeDir(!motorDir);
}

