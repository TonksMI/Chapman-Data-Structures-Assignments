#include "Faculty.h"

int Faculty::getID()
{
  return ID;
}
void Faculty::addStudents(int studid)
{
  int temp [studCount + 1];
  temp[studCount] = studid;
  for(int i = 0; i < studCount + 1; i++)
  {
    temp[i] = students[i];
  }
  studCount++;
  students = temp;
}
int* Faculty::getStudentList()
{
  return students;
}
int Faculty::compare(Faculty f)
{
  return f.getID() - getID();
}
std::string Faculty::toString()
{
  std::string temp = "Name: ";
  temp += Name;
  temp += " ID: ";
  temp += std::to_string(ID);
  return temp;
}
std::string Faculty::toOut()
{
  std::string temp = "";
  temp += Name;
  temp += "|";
  temp += std::to_string(ID);
  temp += "|";
  temp += level;
  temp += "|";
  temp += dept;
  temp += "|";
  temp += std::to_string(studCount);
  temp += "|";
  temp += students[0];
  for(int i = 1; i < studCount; i++)
  {
    temp += ",";
    temp += std::to_string(students[i]);
  }
  return temp;
}
int Faculty::getStudCount()
{
  return studCount;
}
void Faculty::removeStudent(int studid)
{
  int m [studCount - 1];
  int index;
  for(int i = 0; i < studCount; i++)
  {
    if(students[i] != studid)
    {
      m[index] = students[i];
      index++;
    }
    else
    {
      i++;
      m[index] = students[i];
      index++;
    }
  }
}
