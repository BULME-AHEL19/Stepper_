#include "rotationstepper.h"

RotationStepper::RotationStepper() : Stepper_(5,6,7)
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

