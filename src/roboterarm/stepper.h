#ifndef STEPPER_H
#define STEPPER_H
#include "Arduino.h"
#define SPEED 300

class Stepper_
{
public:
  Stepper_(int dir, int step_, int en);
  ~Stepper_();
  
  virtual void begin();
  int Step(int n = 1, int stepDelay = SPEED);
  void moveOneStep(int stepDelay = SPEED);
  void changeDir(boolean d);
  boolean getDir() {return motorDir;}
  void toggleDir();
  
protected:  
  boolean motorDir;

  const int _dir;
  const int _step;
  const int _en;
};

#endif
