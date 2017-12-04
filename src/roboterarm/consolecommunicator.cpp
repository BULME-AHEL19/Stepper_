#include "consolecommunicator.h"
#include "Arduino.h"

ConsoleCommunicator::ConsoleCommunicator()
{
}

ConsoleCommunicator::~ConsoleCommunicator()
{
}

void ConsoleCommunicator::update()
{
  if(Serial)  // wait until Serial Port connected
  {
     if(Serial.available())  // wait until something to read is here
     {
     }
  }
}

void ConsoleCommunicator::onCommand(void (*callback)(char* command))
{
  _onCommandCallback = callback;
}

void ConsoleCommunicator::onMoveToPos(void (*callback)(int x, int y))
{
  _onMoveToPosCallback = callback;
}
