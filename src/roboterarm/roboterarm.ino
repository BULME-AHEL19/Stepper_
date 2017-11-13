#include "stepper.h"
#define BUTTON_TOP A1
#define BUTTON_BOTTOM A0

Stepper_ motor1(5, 6, 7,BUTTON_BOTTOM,BUTTON_TOP);
Stepper_ motor2(2, 3, 4,BUTTON_BOTTOM,BUTTON_TOP);
int step_amount[10] = {2200,2200,2200,2200,2200,2200,2200,2200,2200,2200};
int current_step = 0;
int steps = 0;

void setup()
{ 
  Serial.begin(9600);
  motor1.begin();
  
  Serial.println(motor1.getStepsFromDeg(20));
  
  motor1.moveToStart();
  motor1.toggleDir();
  Serial.println(motor1.moveDeg(135));
  // motor1.moveToEnd();
  
}

void loop()
{
  // Serial.print("Schritte: ");
  //motor1.Step();
  // delay(10);
  
  /*if(++steps % 2000 == 0)
   motor1.changeDir(!motor1.getDir());*/
  
  // Serial.print("Schritte: ");
  // Serial.println(motor1.getSteps()); 
  
  /*motor2.changeDir(true);
  motor2.Step(1000,2);
  delay(1000);
  motor2.changeDir(false);
  motor2.Step(1000,1);
  delay(1000);*/
  char buffer[3];
  if(Serial.available())
  {
    Serial.readBytes(buffer, 3);
    
    int degree = 0;
    
    switch(buffer[0])
    {
      case 1: degree += 100; break;
    }
    
    switch(buffer[1])
    {
      case 1: degree += 10; break;
      case 2: degree += 20; break;
      case 3: degree += 30; break;
      case 4: degree += 40; break;
      case 5: degree += 50; break;
      case 6: degree += 60; break;
      case 7: degree += 70; break;
      case 8: degree += 80; break;
      case 9: degree += 90; break;
    }
    
    switch(buffer[2])
    {
      case 1: degree += 1; break;
      case 2: degree += 2; break;
      case 3: degree += 3; break;
      case 4: degree += 4; break;
      case 5: degree += 5; break;
      case 6: degree += 6; break;
      case 7: degree += 7; break;
      case 8: degree += 8; break;
      case 9: degree += 9; break;
    }
    
    motor1.moveToStart();
    motor1.moveDeg(degree);
  }
}

