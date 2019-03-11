#include "StNode.h"

StNode::StNode()
{
  left = nullptr;
  right = nullptr;
  waitTime = 0;
  timeWaited = 0;
}
StNode::StNode(int waitt, int timew)
{
  left = nullptr;
  right = nullptr;
  waitTime = waitt;
  timeWaited = timew;
}
StNode::StNode(int wait)
{
  left = nullptr;
  right = nullptr;
  waitTime = wait;
  timeWaited = 0;
}
StNode::~StNode()
{

}
