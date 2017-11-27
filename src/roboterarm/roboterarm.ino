#include "stepper.h"
#define BUTTON_TOP A1
#define BUTTON_BOTTOM A0

Stepper_ motor1(5, 6, 7,BUTTON_BOTTOM,BUTTON_TOP);  // is working
Stepper_ motor2(2, 3, 4,BUTTON_BOTTOM,BUTTON_TOP);

void setup()
{ 
  Serial.begin(9600);
  motor1.begin();
  motor2.begin();
}

void loop()
{
  motor1.moveToStart();
  delay(1000);
  motor1.moveToEnd();
  delay(1000);
  motor2.Step(1000);
  motor2.toggleDir();
  delay(1000);
  motor2.Step(1000);
  motor2.toggleDir();
  delay(1000);
}

