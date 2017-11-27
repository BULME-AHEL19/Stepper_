#ifndef CONSOLE_COMMUNICATOR
#define CONSOLE_COMMUNICATOR
#define C_C_COMMAND_LENGTH 20

class ConsoleCommunicator
{
  ConsoleCommunicator();
  ~ConsoleCommunicator();
  
public:
  void run();
  void onCommand(&void callback(char * command));
  void onMoveToPos(&void callback(int x, int y));
  
private:
  void (*_onCommandCallback)(char * command);
  void (*_onMoveToPosCallback)(int x, int y);
};

#endif
