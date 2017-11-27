#ifndef ROBOTARM_H
#define ROBOTARM_H

#include "middlestepper.h"

#define BUTTON_TOP A1
#define BUTTON_BOT A0

class Robotarm
{
public:
  Robotarm();
  ~Robotarm();
  
  void begin();

  boolean hitsTop();
  boolean hitsBot();

  void moveMidStep(int steps = 1, boolean dir = false);
  void moveMidDeg(int deg, boolean dir = false);
private:
  MiddleStepper _midStep;
};

#endif
