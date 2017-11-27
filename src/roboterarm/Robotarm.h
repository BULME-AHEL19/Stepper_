#ifndef ROBOTARM_H
#define ROBOTARM_H

#include "middlestepper.h"
#include "headstepper.h"

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
  void moveHeadStep(int steps = 1,boolean dir = false);
  void moveHeadDeg(int deg, boolean dir = false);

  void moveToTop();
  void moveToBot();
  
private:
  MiddleStepper _midStep;
  HeadStepper   _headStep;
};

#endif
