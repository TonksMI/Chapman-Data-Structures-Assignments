#include "StudentLine.h"

class GameHelper
{
private:
  StudentLine wline;
  StudentLine data;
  int * window;
  int * wData;
  int windowSize;
  bool isNew;
public:
  GameHelper();

  void runSim(char s[]);
  void runSim();
  void initializeWindow(int count);
  void decrementTime();
  void lineToWindow();
  void outputStatistics();
  bool isdone();
};
