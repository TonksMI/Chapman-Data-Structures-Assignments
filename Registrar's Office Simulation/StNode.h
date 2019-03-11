class StNode
{
public:
  StNode * left;
  StNode * right;
  int waitTime;
  int timeWaited;

  StNode();
  StNode(int waitt, int timew);
  StNode(int wait);
  ~StNode();
};
