#include "Arduino.h"
#define SPEED 300
#define BUTTON_TOP A1
#define BUTTON_BOTTOM A0

class Stepper_
{
public:
  Stepper_(int dir, int step_, int en, int but_bot, int but_top);
  ~Stepper_();
  
  void begin();
  int getSteps();
  int moveToStart(int delayTime);
  int moveToEnd(int delayTime);
  int moveUntilHit(int delayTime);
  int Step(int n = 1, int stepDelay = 300);
  void moveOneStep(int stepDelay = 300);
  bool checkIfHit();
  void changeDir(boolean d);
private:  
  boolean motorDir;

  const int _dir;
  const int _step;
  const int _en;
  const int _but_bot;
  const int _but_top;
};
