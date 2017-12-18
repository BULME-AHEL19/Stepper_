#include "rotationstepper.h"

RotationStepper::RotationStepper() : Stepper_(8,9,10)
{ 
  changeDir(false);
}

RotationStepper::~RotationStepper()
{
  
}

void RotationStepper::begin()
{
  Stepper_::begin();
}

int RotationStepper::getStepsFromDeg(int deg)
{
  return ROTATION_STEPS_PER_DEG * (float)deg;
}

int RotationStepper::moveDeg(int deg)
{
  return Step(getStepsFromDeg(deg));
}

