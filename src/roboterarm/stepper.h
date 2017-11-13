#ifndef STEPPER_H
#define STEPPER_H
#include "Arduino.h"
#define SPEED 300
#define STEP_COUNT 2090  // 2090 steps
#define DEG_COUNT 68  // max 68°
#define STEPS_PER_DEG STEP_COUNT / DEG_COUNT
#define MIN_DEG 30
#define MAX_DEG 98

class Stepper_
{
public:
  Stepper_(int dir, int step_, int en, int but_bot, int but_top);
  ~Stepper_();
  
  void begin();
  int getSteps(int delayTime = SPEED);
  int moveToStart(int delayTime = SPEED);
  int moveToEnd(int delayTime = SPEED);
  int moveUntilHit(int delayTime = SPEED);
  int Step(int n = 1, int stepDelay = SPEED);
  void moveOneStep(int stepDelay = SPEED);
  bool checkIfHit();
  void changeDir(boolean d);
  boolean getDir() {return motorDir;}
  
  int getStepsFromDeg(int deg);
  int moveDeg(int deg);
  void toggleDir();
  
  
  
private:  
  boolean motorDir;

  const int _dir;
  const int _step;
  const int _en;
  const int _but_bot;
  const int _but_top;
};

#endif
