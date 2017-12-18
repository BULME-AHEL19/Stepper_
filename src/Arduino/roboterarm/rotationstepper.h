#ifndef ROTATION_STEPPER_H
#define ROTATION_STEPPER_H
#include "stepper.h"
#define ROTATION_STEPS_PER_DEG 30 * 2  // the other stepperMotorDriver uses twice the number of stepps

class RotationStepper : public Stepper_
{
public:
  RotationStepper();
  ~RotationStepper();
  
  void begin() override;
  int moveDeg(int deg);

  int getStepsFromDeg(int deg);
};

#endif
