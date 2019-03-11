using namespace std;
#include <string>
#include <iostream>

class Faculty
{
private:
  std::string Name;
  int ID;
  std::string level;
  std::string dept;
  int * students;
  int studCount;
public:
  Faculty(std::string name, int id, std::string l, std::string d)
  {
    Name = name;
    ID = id;
    level = l;
    dept = d;
    studCount = 0;
    students = new int[1];
  }
  Faculty(std::string str)
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
    i++;
    temp = "";
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
    level = temp;
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
    cout << temp << endl;
    studCount =  std::stoi(temp);
    i++;
    temp = "";
    students = new int[studCount];
    if(studCount > 0)
    {
      for(int j = 0; i < studCount; i++)
      {
        while(str[i] != ',' && i < len)
        {
          temp += str[i];
          i++;
        }
        students[j] = std::stoi(temp);
        temp = "";
      }
    }
  }
  Faculty()
  {

  }
  ~Faculty()
  {

  }
  int getStudCount();
  int getID();
  void addStudents(int studid);
  void removeStudent(int studid);
  int* getStudentList();
  int compare(Faculty f);
  std::string toString();
  std::string toOut();
};
