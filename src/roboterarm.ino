#include "stepper.h"

Stepper_ motor1(5, 6, 7);

void setup()
{ 
  Serial.begin(9600);
  motor1.begin();
  /*motor1.moveToEnd();
  
  delay(2000);
  motor1.moveToStart();*/
  Serial.print("Number of steps: ");
  Serial.println(motor1.getSteps());
}
void loop()
{
}

