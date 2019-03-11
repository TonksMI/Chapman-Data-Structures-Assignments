#include "Faculty.h"

class FNode
{
public:

  FNode * left;
  FNode * right;
  Faculty  data;
  
  FNode(Faculty f)
  {
    data = f;
    left = nullptr;
    right = nullptr;
  }
  ~FNode()
  {

  }
};
