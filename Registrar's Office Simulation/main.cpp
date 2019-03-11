#include "GameHelper.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
  GameHelper g = GameHelper();
  if(argc == 1)
  {
  g.runSim();
  }
  else
  {
    g.runSim(argv[1]);
  }
}
