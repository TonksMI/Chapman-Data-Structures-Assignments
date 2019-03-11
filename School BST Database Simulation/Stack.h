#include <string>
using namespace std;
#include <iostream>

template<class T>
class Stack
{
private:
  T * list;
  int count;
public:
  Stack();
  ~Stack();

  void add(T input);
  T pop();
};
template<class T>
Stack<T>::Stack()
{
  list = new T[5];
  count = 0;
}
template<class T>
Stack<T>::~Stack()
{

}
template<class T>
void Stack<T>::add(T input)
{
  if(count < 5)
  {
    list[count] = input;
    count++;
  }
  else
  {
    for(int i = 1; i < 5; i++)
    {
      list[i - 1] = list[i];
    }
    list[4] = input;
  }
}

template<class T>
T Stack<T>::pop()
{
  if(count != 0)
  {
    T temp = list[count - 1];
    count--;
    return temp;
  }
  return "";
}
