#include "consolecommunicator.h"

ConsoleCommunicator::ConsoleCommunicator()
{
}

ConsoleCommunicator::~ConsoleCommunicator()
{
}

ConsoleCommunicator::run()
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

ConsoleCommunicator::onCommand(&void callback(char * command))
{
  _onCommandCallback = callback;
}

ConsoleCommunicator::onMoveToPos(&void callback(int x, int, y))
{
  _onMoveToPosCallback = callback;
}
