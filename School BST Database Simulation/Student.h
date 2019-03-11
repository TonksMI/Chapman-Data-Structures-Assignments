using namespace std;
#include <string>
#include <iostream>
class Student
{
private:
  std::string Name;
  int ID;
  std::string level;
  std::string major;
  double GPA;
  int FacultyID;
public:
  Student(std::string name, int id, std::string l, std::string m, double gpa, int facid)
  {
    Name = name;
    ID = id;
    level = l;
    major = m;
    GPA = gpa;
    FacultyID = facid;
  }
  Student(std::string str)
  {
    int i = 0;
    int len = str.length();
    string temp = "";
    while(str[i] != '|')
    {
      temp += str[i];
      i++;
    }

    Name = temp;
    temp = "";
    i++;
    while(str[i] != '|')
    {
      temp += str[i];
      i++;
    }


    ID = std::stoi(temp);
    temp = "";
    i++;
    while(str[i] != '|')
    {
      temp += str[i];
      i++;
    }


    major = temp;
    temp = "";
    i++;
    while(str[i] != '|')
    {
      temp += str[i];
      i++;
    }


    level = temp;
    temp = "";
    i++;
    while(str[i] != '|')
    {
      temp += str[i];
      i++;
    }


    GPA = std::stof(temp);
    temp = "";
    i++;
    while(i < len)
    {


      temp += str[i];
      i++;
    }


    FacultyID = std::stoi(temp);
  }
  Student()
  {

  }
  ~Student()
  {

  }
  int getID();
  std::string getLevel();
  std::string getMajor();
  double getGPA();
  int getFacID();
  int compare(Student s);
  void setFacID(int fac);
  std::string toString();
  std::string toOut();
};
