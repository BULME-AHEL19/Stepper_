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
  if (Serial && Serial.available()) // wait until something to read is here
  {
    char command [C_C_COMMAND_LENGTH];
    Serial.readBytesUntil('\0', command, C_C_COMMAND_LENGTH);
#ifdef C_C_DEBUG
    Serial.print("Received: ");
    Serial.println(command);
#endif

    // compare if "move" is in it
    if (strcmp(command, "move") == 0);
    {
      // filter out x and y

    }
    else
    {
      // exec callback
      if (_onCommandRegistered) // if registered
      {
        _onCommandCallback(command);
      }
    }
  }
}

void ConsoleCommunicator::onCommand(void (*callback)(char* command))
{
  _onCommandCallback = callback;
  _onCommandRegistered = true;
}

void ConsoleCommunicator::onMoveToPos(void (*callback)(int x, int y))
{
  _onMoveToPosCallback = callback;
  _onMoveToPosRegistered = true;
}
