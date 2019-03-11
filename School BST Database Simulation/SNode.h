#include "Student.h"

class SNode
{
public:

  SNode * left;
  SNode * right;
  Student data;

  SNode(Student f)
  {
    data = f;
    left = nullptr;
    right = nullptr;
  }
  ~SNode()
  {

  }
};
