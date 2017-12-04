#ifndef ROBOTARM_H
#define ROBOTARM_H

#include "middlestepper.h"
#include "headstepper.h"
#include "consolecommunicator.h"

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
  void headMoveToTop();
  void headMoveToMax();
  void headEnable();
  void headDisable();

  void moveToTop(int delayTime = 1000);
  void moveToBot();

  void update();
  
private:
  MiddleStepper _midStep;
  HeadStepper   _headStep;
  ConsoleCommunicator _conCom;
};

#endif
