#ifndef MIDDLE_STEPPER_H
#define MIDDLE_STEPPER_H
#include "stepper.h"
#define MIDDLE_STEP_COUNT 2090.0f  // 2090 steps
#define MIDDLE_DEG_COUNT 68.0f  // max 68°
#define MIDDLE_STEPS_PER_DEG (MIDDLE_STEP_COUNT / MIDDLE_DEG_COUNT)
#define MIDDLE_MIN_DEG 30
#define MIDDLE_MAX_DEG 98

class MiddleStepper : public Stepper_
{
public:
  MiddleStepper();
  ~MiddleStepper();
  
  void begin() override;
  int moveDeg(int deg);

  int getStepsFromDeg(int deg);
protected:
  const int _buttonTop;
  const int _buttonBot;
};

#endif
