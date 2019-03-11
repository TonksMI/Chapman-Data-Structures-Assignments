#include "DblLinkListStu.h"

class StudentLine
{
private:
  DblLinkListStu line;
  int total;
public:
  StudentLine();
  ~StudentLine();
  void enterLine(int wait);
  void enterLine(int wait, int time);
  void exitLine();
  int peekWaitTime();
  int peekTimeWaited();
  int getTotal();
  void outputWaitTimes();
  void incrementTimeWaited();
  bool isEmpty();
  void outputStats();
};
