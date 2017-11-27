#include "headstepper.h"

HeadStepper::HeadStepper() : Stepper_(2,3,4)
{
  
}

HeadStepper::~HeadStepper()
{
  
}

int HeadStepper::moveDeg(int deg)
{
  return Step(getStepsFromDeg(deg));
}

int HeadStepper::getStepsFromDeg(int deg)
{
  return HEAD_STEPS_PER_DEG * (float)deg;
}

