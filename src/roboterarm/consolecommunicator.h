#ifndef CONSOLE_COMMUNICATOR
#define CONSOLE_COMMUNICATOR
#define C_C_COMMAND_LENGTH 20

class ConsoleCommunicator
{
public:
  ConsoleCommunicator();
  ~ConsoleCommunicator();
  void update();
  void onCommand(void (*callback)(char * command));
  void onMoveToPos(void (*callback)(int x, int y));
  
private:
  void (*_onCommandCallback)(char * command);
  void (*_onMoveToPosCallback)(int x, int y);
};

#endif
