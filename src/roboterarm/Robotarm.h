#ifndef ROBOTARM_H
#define ROBOTARM_H
#include "stepper.h"

class Robotarm
{
public:
  Robotarm();
  ~Robotarm();
  
  begin();
  
private:
  Stepper_ motor_up_down;
  Stepper_ motor_left_right;
  Stepper_ motor_left_right_1;
};

#endif
