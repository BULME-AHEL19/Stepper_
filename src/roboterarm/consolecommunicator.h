#ifndef CONSOLE_COMMUNICATOR
#define CONSOLE_COMMUNICATOR
#define C_C_COMMAND_LENGTH 20
#define C_C_STR_SPLIT_NUMBER 5
#define C_C_STR_SPLIT_LENGTH 10

#define C_C_DEBUG

class ConsoleCommunicator
{
public:
  ConsoleCommunicator();
  ~ConsoleCommunicator();
  void update();
  void onCommand(void (*callback)(char * command));
  void onMoveToPos(void (*callback)(int x, int y));
  
private:
  int _strSplit(char * str, int len, char result[][C_C_STR_SPLIT_LENGTH]);
  void (*_onCommandCallback)(char * command);
  void (*_onMoveToPosCallback)(int x, int y);
  
  bool _onCommandRegistered = false;
  bool _onMoveToPosRegistered = false;
};

#endif
