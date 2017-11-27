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

  void midMoveStep(int steps = 1, boolean dir = false);
  void midMoveDeg(int deg, boolean dir = false);
  void midEnable();
  void midDisable();
  void headMoveStep(int steps = 1,boolean dir = false);
  void headMoveDeg(int deg, boolean dir = false);
  void headEnable();
  void headDisable();

  void moveToTop();
  void moveToBot();
  
private:
  MiddleStepper _midStep;
  HeadStepper   _headStep;
};

#endif
