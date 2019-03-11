#include "FacultyDB.h"
#include <iostream>
#include <fstream>
using namespace std;

FacultyDB::FacultyDB()
{
  root = nullptr;
}
FacultyDB::~FacultyDB()
{
  while(root != nullptr)
  {
    deletenode(root);
  }
}
void FacultyDB::Print()
{
  recPrint(root);
}
void FacultyDB::recPrint(FNode * node)
{
  if(node == nullptr)
  {
    return;
  }
  recPrint(node->left);
  cout << node->data.toString() << endl;
  recPrint(node->right);
}
void FacultyDB::removeNode(FNode *node)
{
  node->left = nullptr;
  node->right = nullptr;
  delete node;
}
void FacultyDB::insert(FNode * node)
{
  FNode* dat = node;
  if(isEmpty())
  {
    root = node;
  }
  else
  {
    FNode *curr = root;
    FNode *parent;
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
bool FacultyDB::contains(int ID)
{
  FNode * curr = root;
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
bool FacultyDB::deletenode(FNode * node)
{
  deleteRec(node->data.getID());
}
bool FacultyDB::deleteRec(int ID)
{
  if(!contains(ID))
  {
    return false;
  }
  FNode *parent = root;
  FNode *curr = root;
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
    FNode* succ = getSuccessor(curr);
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
FNode* FacultyDB::getSuccessor(FNode *node)
{
  FNode* success = node;
  FNode* sp = node;
  FNode* curr = node->right;
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
bool FacultyDB::isEmpty()
{
  return root == nullptr;
}

std::string FacultyDB::Save()
{
  ofstream file;
  file.open("faculty.out");
  file << getString(root);
  file.close();
}
std::string FacultyDB::getString(FNode * node)
{
  if(node == nullptr)
  {
    return "";
  }
  else
  {
    string temp = getString(node->left);
    temp += node->data.toOut();
    temp += '\n';
    temp += getString(node->right);
    return temp;
  }
}
FNode* FacultyDB::find(int ID)
{
  if(contains(ID))
  {
    FNode * curr = root;
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
