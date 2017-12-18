#ifndef CONSOLE_COMMUNICATOR
#define CONSOLE_COMMUNICATOR
#define C_C_COMMAND_LENGTH 20
#define C_C_STR_SPLIT_NUMBER 5
#define C_C_STR_SPLIT_LENGTH 10


//#define C_C_DEBUG

class ConsoleCommunicator
{
public:
  ConsoleCommunicator();
  ~ConsoleCommunicator();
  void update();
  void onCommand(void (*callback)(char command[][C_C_STR_SPLIT_LENGTH], int len));
  void onMoveToPos(void (*callback)(int x, int y));
  void onRotateToPos(void (*callback)(int deg, bool dir));
private:
  int _strSplit(char * str, int len, char result[][C_C_STR_SPLIT_LENGTH]);
  void (*_onCommandCallback)(char command[][C_C_STR_SPLIT_LENGTH], int len);
  void (*_onMoveToPosCallback)(int x, int y);
  void (*_onRotateToPosCallback)(int deg, bool dir);
    
  bool _onCommandRegistered = false;
  bool _onMoveToPosRegistered = false;
  bool _onRotateToPosRegistered = false;
};

#endif
