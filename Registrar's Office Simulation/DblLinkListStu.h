#include "StNode.h"

class DblLinkListStu
{
public:
  StNode * front;
  StNode * back;

  DblLinkListStu();
  ~DblLinkListStu();
  void insertFront(int wait);
  void insertFront(int wait, int timew);
  void insertBack(int wait);
  StNode* deleteFront();
  void outWait();
  void incrementTW();
  bool isEmpty();
};
