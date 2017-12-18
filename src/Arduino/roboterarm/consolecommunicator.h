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
  void onMoveToTop(void (*callback)());
  void onMoveToBot(void (*callback)());
  void onEnable(void (*callback)(char which[30]));
  void onDisable(void (*callback)(char which[30]));
  
private:
  void _onCommand(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onMoveToPos(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onMoveToTop(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onMoveToBot(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onRotateToPos(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onEnable(char command[][C_C_STR_SPLIT_LENGTH],int len);
  void _onDisable(char command[][C_C_STR_SPLIT_LENGTH],int len);

  int _strSplit(char * str, int len, char result[][C_C_STR_SPLIT_LENGTH]);
  
  void (*_onCommandCallback)(char command[][C_C_STR_SPLIT_LENGTH], int len);
  void (*_onMoveToPosCallback)(int x, int y);
  void (*_onRotateToPosCallback)(int deg, bool dir);
    
 
  void (*_onMoveToTopCallback)();
  void (*_onMoveToBotCallback)();
  void (*_onEnableCallback)(char which[30]);
  void (*_onDisableCallback)(char which[30]);
  
  bool _onCommandRegistered = false;
  bool _onMoveToPosRegistered = false;
  bool _onMoveToTopRegistered = false;
  bool _onMoveToBotRegistered = false;
  bool _onRotateToPosRegistered = false;
  bool _onEnableRegistered = false;
  bool _onDisableRegistered = false;
};

#endif
