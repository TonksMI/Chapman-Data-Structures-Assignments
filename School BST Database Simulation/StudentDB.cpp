#include "StudentDB.h"
#include <iostream>
using namespace std;

StudentDB::StudentDB()
{
  root = nullptr;
}
StudentDB::~StudentDB()
{
  deletenode(root);
}
void StudentDB::Print()
{
  recPrint(root);
}
void StudentDB::recPrint(SNode * node)
{
  if(node == nullptr)
  {
    return;
  }
  recPrint(node->left);
  cout << node->data.toString() << endl;
  recPrint(node->right);
}
void StudentDB::removeNode(SNode *node)
{
  node->left = nullptr;
  node->right = nullptr;
  delete node;
}
void StudentDB::insert(SNode * node)
{
  SNode* dat = node;
  if(isEmpty())
  {
    root = node;
  }
  else
  {
    SNode *curr = root;
    SNode *parent;
    while(true)
    {
      parent = curr;
      if(dat->data.compare(curr->data) > 0)
      {
        curr = curr->left;
        if (curr == nullptr)
        {
          parent->left = node;
          break;
        }
      }
      else
      {
        curr = curr->right;
        if (curr == nullptr)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}
bool StudentDB::contains(int ID)
{
  SNode * curr = root;
  while(curr != nullptr)
  {
    if (curr->data.getID() == ID)
    {
      return true;
    }
    else if (curr->data.getID() > ID)
    {
      curr = curr->left;
    }
    else
    {
      curr = curr->right;
    }
  }
  return false;
}
bool StudentDB::deletenode(SNode * node)
{
  deleteRec(node->data.getID());
}
bool StudentDB::deleteRec(int ID)
{
  if(!contains(ID))
  {
    return false;
  }
  SNode *parent = root;
  SNode *curr = root;
  bool isLeft = true;

  while(curr->data.getID() != ID)
  {
    parent = curr;
    if(curr->data.getID() > ID)
    {
      isLeft = true;
      curr = curr->left;
    }
    else
    {
      isLeft = false;
      curr = curr->right;
    }
    if(curr == nullptr)
    {
      return false;
    }
  }
  if(curr->left == nullptr && curr->right == nullptr)
  {
    if(parent == curr)
    {
      root = nullptr;
      return true;
    }
    else if(isLeft)
    {
      parent->left = nullptr;
      return true;
    }
    else
    {
      parent->right = nullptr;
      return true;
    }
    delete curr;
  }
  else if(curr->left != nullptr && curr->right == nullptr)
  {
    if(parent == curr)
    {
      root = curr->left;
      return true;
    }
    else if(isLeft)
    {
      parent->left = curr->left;
      return true;
    }
    else if(!isLeft)
    {
      parent->right = curr->left;
      return true;
    }
    curr->left = nullptr;
    delete curr;
  }
  else if(curr->right != nullptr && curr->left == nullptr)
  {
    if(parent == curr)
    {
      root = curr->right;
      return true;
    }
    else if(isLeft)
    {
      parent->left = curr->right;
      return true;
    }
    else if(!isLeft)
    {
      parent->right = curr->right;
      return true;
    }
    curr->right = nullptr;
    delete curr;
  }
  else
  {
    SNode* succ = getSuccessor(curr);
    if(curr == root)
    {
      root = succ;
    }
    else if(isLeft)
    {
      parent->left = succ;
      return true;
    }
    else
    {
      parent->right = succ;
      return true;
    }
    succ->left = curr->left;
  }
  return true;
}
SNode* StudentDB::getSuccessor(SNode *node)
{
  SNode* success = node;
  SNode* sp = node;
  SNode* curr = node->right;
  while(curr != nullptr)
  {
    sp = success;
    success = curr;
    curr = curr->left;
  }
  if(success != node->right)
  {
    sp->left = success->right;
    success->right = curr->right;
  }
  return success;
}
bool StudentDB::isEmpty()
{
  return root == nullptr;
}
string StudentDB::Save()
{
  ofstream file;
  file.open("student.out");
  file << getString(root);
  file.close();
}
std::string StudentDB::getString(SNode * node)
{
  if(node == nullptr)
  {
    return "";
  }
  else
  {
    string temp = getString(node->left);
    temp += node->data.toOut();
    temp += "\n";
    temp += getString(node->right);
    return temp;
  }
}
SNode* StudentDB::find(int ID)
{
  if(contains(ID))
  {
    SNode * curr = root;
    while(curr != nullptr)
    {
      if (curr->data.getID() == ID)
      {
        return curr;
      }
      else if (curr->data.getID() > ID)
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }
  }
  return nullptr;
}
