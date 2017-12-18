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
    if (len == 3)
    {
        if(_onMoveToPosRegistered && strcmp(command[0], "move") == 0)
        {
          _onMoveToPos(command,len);
        }
        
        if(_onRotateToPosRegistered && strcmp(command[0], "rotate") == 0)
        {
          _onRotateToPos(command,len);
        }
    }
    /*else if(len == 2)
    {
      if(_on)
    }*/
    else if(len == 1)
    {
      if(_onMoveToTopRegistered && strcmp(command[0],"moveToTop") == 0)
      {
        _onMoveToTop(command,len);
      }
      else if(_onMoveToBotRegistered && strcmp(command[0],"moveToBot") == 0)
      {
        _onMoveToBot(command,len);
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

void ConsoleCommunicator::_onMoveToTop(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
  _onMoveToTopCallback();
}

void ConsoleCommunicator::_onMoveToBot(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
  _onMoveToBotCallback();
}


void ConsoleCommunicator::_onRotateToPos(char command[][C_C_STR_SPLIT_LENGTH],int len)
{
  int deg = atoi(command[1]);
  bool dir;
  if(strcmp(command[2], "false") == 0)
    dir = false;
  else if(strcmp(command[2], "true") == 0)
    dir = true;
  else {
    Serial.println("Invalid parameter!");
    return;
  }

  _onRotateToPosCallback(deg, dir);
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


void ConsoleCommunicator::onMoveToTop(void (*callback)())
{
  _onMoveToTopCallback = callback;
  _onMoveToTopRegistered = true;
}

void ConsoleCommunicator::onMoveToBot(void (*callback)())
{
  _onMoveToBotCallback = callback;
  _onMoveToBotRegistered = true;
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

void ConsoleCommunicator::onRotateToPos(void (*callback)(int deg, bool dir)) {
  _onRotateToPosCallback = callback;
  _onRotateToPosRegistered = true;
}
