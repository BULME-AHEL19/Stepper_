#include "stepper.h"
#define BUTTON_TOP A1
#define BUTTON_BOTTOM A0

Stepper_ motor1(5, 6, 7,BUTTON_BOTTOM,BUTTON_TOP);  // is working
Stepper_ motor2(2, 3, 4,BUTTON_BOTTOM,BUTTON_TOP);

void setup()
{ 
  Serial.begin(9600);
  motor2.begin();

  motor2.Step(1000);
}

void loop()
{
  
}

