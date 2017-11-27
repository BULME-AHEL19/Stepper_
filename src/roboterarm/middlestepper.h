#ifndef MIDDLE_STEPPER_H
#define MIDDLE_STEPPER_H
#include "Arduino.h"
#define MIDDLE_SPEED 300
#define MIDDLE_STEP_COUNT 2090.0f  // 2090 steps
#define MIDDLE_DEG_COUNT 68.0f  // max 68°
#define MIDDLE_STEPS_PER_DEG (STEP_COUNT / DEG_COUNT)
#define MIDDLE_MIN_DEG 30
#define MIDDLE_MAX_DEG 98

class MiddleStepper
{
public:
  MiddleStepper_(int dir, int step_, int en);
  ~MiddleStepper_();
  
  void begin();
  int Step(int n = 1, int stepDelay = SPEED);
  void moveOneStep(int stepDelay = SPEED);
  void changeDir(boolean d);
  boolean getDir() {return motorDir;}
  
  int moveDeg(int deg);
  void toggleDir();
  
private:  
  boolean motorDir;

  const int _dir;
  const int _step;
  const int _en;
};

#endif
