#include "SNode.h"
#include <fstream>
using namespace std;

class StudentDB
{
private:
  SNode * root;
public:
  StudentDB();
  ~StudentDB();

  SNode* find(int ID);
  void insert(SNode * node);
  bool contains(int ID);
  bool deletenode(SNode* node);
  bool deleteRec(int ID);
  bool isEmpty();
  void recPrint(SNode * node);
  void Print();
  SNode * getSuccessor(SNode * node);
  void removeNode(SNode * node);
  std::string Save();
  std::string getString(SNode * node);
};
