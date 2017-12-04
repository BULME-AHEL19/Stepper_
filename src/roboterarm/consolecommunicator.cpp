#include "consolecommunicator.h"
#include "Arduino.h"

ConsoleCommunicator::ConsoleCommunicator()
{
}

ConsoleCommunicator::~ConsoleCommunicator()
{
}

void ConsoleCommunicator::run()
{
  while(!Serial)  // wait until Serial Port connected
  {
  }
  
  while(true)    // run forever
  {
    while(!Serial.available())  // wait until something to read is here
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
