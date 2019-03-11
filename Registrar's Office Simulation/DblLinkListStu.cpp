#include "DblLinkListStu.h"
#include <iostream>
using namespace std;

DblLinkListStu::DblLinkListStu()
{
  front =nullptr;
  back = nullptr;
}
DblLinkListStu::~DblLinkListStu()
{
  while(front)
  {
    StNode * temp = front;
    front = front->right;
    temp->left = nullptr;
    temp->right = nullptr;
    delete temp;
  }
}
void DblLinkListStu::insertFront(int wait, int timew)
{
  if(back == nullptr && front == nullptr)
  {
    front = new StNode(wait,timew);
    back = front;
  }
  else
  {
    StNode * temp = new StNode(wait,timew);
    temp->right = front;
    front = temp;
  }
}
void DblLinkListStu::insertFront(int wait)
{
  if(back == nullptr && front == nullptr)
  {
    front = new StNode(wait);
    back = front;
  }
  else
  {
    StNode * temp = new StNode(wait);
    temp->right = front;
    front = temp;
  }
}
void DblLinkListStu::insertBack(int wait)
{
  if(back == nullptr && front == nullptr)
  {
    front = new StNode(wait);
    back = front;
  }
  else
  {
    StNode * temp = new StNode(wait);
    back->right = temp;
    back = temp;
  }
}
StNode* DblLinkListStu::deleteFront()
{
  if(front != back)
  {
    StNode* temp = front;
    front = front->right;
    front->left = nullptr;
    temp->right  = nullptr;
    temp->left = nullptr;
    delete temp;
  }
  else
  {
    delete front;
    front = back = 0;
  }
}

void DblLinkListStu::outWait()
{
  StNode * temp = front;
  while(temp !=nullptr)
  {
    cout << temp->timeWaited << " ";
    temp = temp->right;
  }
  cout << endl;
}
void DblLinkListStu::incrementTW()
{
  StNode * temp = front;
  while(temp !=nullptr)
  {
    temp->timeWaited++;
    temp = temp->right;
  }
}
bool DblLinkListStu::isEmpty()
{
  if(front == back && front == nullptr)
  {
    return true;
  }
  return false;
}
