#include "Student.h"
#include <string>
using namespace std;

int Student::getID()
{
  return ID;
}
std::string Student::getLevel()
{
  return level;
}
std::string Student::getMajor()
{
  return major;
}
double Student::getGPA()
{
  return GPA;
}
int Student::getFacID()
{
  return FacultyID;
}
void Student::setFacID(int fac)
{
  FacultyID = fac;
}
int Student::compare(Student s)
{
  return s.getID() - getID();
}
std::string Student::toString()
{
  std::string temp =  "ID: ";
  temp += std::to_string(ID);
  temp += " Name: ";
  temp += Name;
  temp += " Current Major: ";
  temp += major;
  temp += " Current level: ";
  temp += level;
  temp += " GPA: ";
  temp += std::to_string(GPA);
  return temp;
}
std::string Student::toOut()
{
  std::string temp = Name;
  temp += "|";
  temp += std::to_string(ID);
  temp += "|";
  temp += major;
  temp += "|";
  temp += level;
  temp += "|";
  temp += std::to_string(GPA);
  temp += "|";
  temp += std::to_string(FacultyID);
  return temp;
}
