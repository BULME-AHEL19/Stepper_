#ifndef HEAD_STEPPER_H
#define HEAD_STEPPER_H

#include "stepper.h"

#define HEAD_STEP_COUNT 2500.0f  // 2200 steps
#define HEAD_DEG_COUNT 90.0f  // max 90°
#define HEAD_STEPS_PER_DEG (HEAD_STEP_COUNT / HEAD_DEG_COUNT)

class HeadStepper : public Stepper_
{
public:
  HeadStepper();
  ~HeadStepper();

  int moveDeg(int deg);
  int getStepsFromDeg(int deg);
};

#endif

