#include "FNode.h"
#include <fstream>
class FacultyDB
{
private:
  FNode * root;
public:
  FacultyDB();
  ~FacultyDB();

  FNode* find(int ID);
  void insert(FNode * node);
  bool contains(int ID);
  bool deletenode(FNode* node);
  bool deleteRec(int ID);
  bool isEmpty();
  void recPrint(FNode * node);
  void Print();
  FNode * getSuccessor(FNode * node);
  void removeNode(FNode * node);
  std::string Save();
  std::string getString(FNode * node);
};
