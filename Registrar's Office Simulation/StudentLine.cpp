#include "StudentLine.h"

StudentLine::StudentLine()
{
  line = DblLinkListStu();
  total = 0;
}
StudentLine::~StudentLine()
{

}
void StudentLine::enterLine(int wait)
{
  line.insertBack(wait);
  total++;
}
void StudentLine::enterLine(int wait,int time)
{
  line.insertFront(wait,time);
  total++;
}
void StudentLine::exitLine()
{
  line.deleteFront();
}
int StudentLine::peekWaitTime()
{
  return line.front->waitTime;
}
int StudentLine::peekTimeWaited()
{
  return line.front->timeWaited;
}
int StudentLine::getTotal()
{
  return total;
}
void StudentLine::outputWaitTimes()
{
  line.outWait();
}
void StudentLine::incrementTimeWaited()
{
  line.incrementTW();
}
bool StudentLine::isEmpty()
{
  return line.isEmpty();
}
void StudentLine::outputStats()
{

}
