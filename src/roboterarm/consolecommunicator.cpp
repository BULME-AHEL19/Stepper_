#include "consolecommunicator.h"
#include "Arduino.h"
#include "String.h"

ConsoleCommunicator::ConsoleCommunicator()
{
}

ConsoleCommunicator::~ConsoleCommunicator()
{
}

void ConsoleCommunicator::_onCommand(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
    if (len > 2)
    {
        if(_onMoveToPosRegistered && strcmp(command[0], "move") == 0)
        {
          _onMoveToPos(command,len);
        }
    }
    // exec callback
    if (_onCommandRegistered) // if registered
    {
      _onCommandCallback(command,len);
    }
}

void ConsoleCommunicator::_onMoveToPos(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
  // filter out x and y
   int x = atoi(command[1]);
   int y = atoi(command[2]);

#ifdef C_C_DEBUG
    Serial.println(x);
    Serial.println(y);
#endif
    _onMoveToPosCallback(x, y);
}

int ConsoleCommunicator::_strSplit(char * str, int len, char result[][C_C_STR_SPLIT_LENGTH])
{
  int resultCount = 0;
  char currentSegment[C_C_STR_SPLIT_LENGTH];
  int currentSegmentLength = 0;

  for (int i = 0; i < len && str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
    {
      if (currentSegmentLength != 0)
      {
        // reset
        int j;
        for (j = 0; j < currentSegmentLength; j++)
        {
          result[resultCount][j] = currentSegment[j];
        }

        result[resultCount][j] = '\0';
        currentSegmentLength = 0;
        resultCount ++;
      }
    }
    else
    {
      currentSegment[currentSegmentLength] = str[i];
      currentSegmentLength ++;
    }
  }

  int j;
  for (j = 0; j < currentSegmentLength; j++)
  {
    result[resultCount][j] = currentSegment[j];
  }
  result[resultCount][j] = '\0';
  resultCount ++;

  return resultCount;
}


void ConsoleCommunicator::update()
{
  if (Serial && Serial.available()) // wait until something to read is here
  {
    char command [C_C_COMMAND_LENGTH];
    int len = Serial.readBytesUntil('\0', command, C_C_COMMAND_LENGTH);
    command[len] = '\0';  // add \0 at the end
    len++;
    
#ifdef C_C_DEBUG
    Serial.print("Received: ");
    Serial.println(command);
#endif

    char words[C_C_STR_SPLIT_NUMBER][C_C_STR_SPLIT_LENGTH];
    int count = _strSplit(command, len, words);
    
    _onCommand(words,count);
  }
}

void ConsoleCommunicator::onCommand(void (*callback)(char command[][C_C_STR_SPLIT_LENGTH],int len))
{
  _onCommandCallback = callback;
  _onCommandRegistered = true;
}

void ConsoleCommunicator::onMoveToPos(void (*callback)(int x, int y))
{
  _onMoveToPosCallback = callback;
  _onMoveToPosRegistered = true;
}
