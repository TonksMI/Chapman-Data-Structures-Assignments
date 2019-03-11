#include <iostream>

using namespace std;

template <class T>
class stack
{
private:
  T *st;
  int front;
  int size;
public:
  stack();
  ~stack();

  void push(T data);
  T peek();
  T pop();
  int getCount();
};
template <class T>
stack<T>::stack()
{
  st = new T[5];
  front = - 1;
  size = 5;
}
template <class T>
stack<T>::~stack()
{

}
template <class T>
void stack<T>::push(T data)
{
  if(front + 1 == size)
  {
    T *temp;
    temp = new T[size*2];
    for(int i = 0; i < size; i++)
    {
      temp[i] = st[i];
    }
    st = temp;
    size = size * 2;
  }
  front++;
  st[front] = data;
}
template <class T>
T stack<T>::peek()
{
  return st[front];
}
template <class T>
T stack<T>::pop()
{
  if(front < 0)
  {
    return 'O';
  }
  else
  {
    T tem = st[front];
    front--;
    return tem;
  }
}
template <class T>
int stack<T>::getCount()
{
  return front + 1;
}
