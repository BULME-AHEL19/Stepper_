#include "middlestepper.h"

MiddleStepper::MiddleStepper() : Stepper_(5,6,7)
{ 
  changeDir(false);
}

MiddleStepper::~MiddleStepper()
{
  
}

void MiddleStepper::begin()
{
  Stepper_::begin();
}

int MiddleStepper::getStepsFromDeg(int deg)
{
  return MIDDLE_STEPS_PER_DEG * (float)deg;
}

int MiddleStepper::moveDeg(int deg)
{
  return Step(getStepsFromDeg(deg));
}

