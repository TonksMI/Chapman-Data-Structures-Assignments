#include "System.h"
#include <fstream>
using namespace std;

bool isValid(string s)
{
  if(s == "exit")
  {
    return true;
  }
  fstream file (s);
  if(file)
  {
    return true;
  }
  else
  {
    return false;
  }
}
//prompts user to input a file
string validName(string file)
{
  if (file != "")
  {
    while(!isValid(file)){
      cout << "Enter a vaild file name (or exit): " << file <<endl;
      getline(cin,file);
    }
    return file;
  }
  else
  {
    do{
      cout << "Enter a vaild file name (or exit):" << endl;
      getline(cin,file);
    }while(!isValid(file));
    return file;
  }
}
void System::addStudent(Student st)
{
  int facid = st.getFacID();
  int id = st.getID();
  FNode * n = fac.find(facid);
  n->data.addStudents(id);
  SNode * node = new SNode(st);
  stud.insert(node);
  string temp = "rs";
  temp += std::to_string(id);
  stack->add(temp);
}
void System::addFaculty(Faculty st)
{
  int id = st.getID();
  FNode * node = new FNode(st);
  fac.insert(node);
  string temp = "rf";
  temp += std::to_string(id);
  stack->add(temp);
  cout << temp << endl;
}
void System::removeStudent(int ID)
{
  if(stud.contains(ID))
  {
    int id = ID;
    string temp = "as";
    temp+=stud.find(ID)->data.toOut();
    SNode * ndoe = stud.find(ID);
    int facid = ndoe->data.getFacID();
    FNode * n = fac.find(facid);
    n->data.removeStudent(ID);
    stud.deleteRec(ID);
    stack->add(temp);
  }
}
void System::removeFaculty(int ID)
{
  int id = ID;
  string temp = "af";
  cout << "1" << endl;
  temp+= fac.find(id)->data.toOut();
  cout << "1" << endl;
  FNode * node = fac.find(id);
  int len = node->data.getStudCount();
  if(len != 0)
  {
    cout << "1" << endl;
    FNode * succ = fac.getSuccessor(fac.find(id));
    cout << "1" << endl;
    for(int i = 0; i <  len - 1; i++)
    {//stud.find(studid[i])->data.toString()
      cout << "1" << endl;
      SNode * n = stud.find(node->data.getStudentList()[i]);
      cout << "1" << endl;

      n->data.setFacID(succ->data.getID());
    }
  }
  fac.deleteRec(id);
  stack->add(temp);
}
void System::outputFacs()
{
  fac.Print();
}
void System::outputStuds()
{
  stud.Print();
}
void System::outFiles()
{
  /*
  if(!stud.isEmpty())
  {
    stud.Save();
  }
  if(!fac.isEmpty())
  {
    stud.Save();
  }*/
}
void System::initializeFiles()
{
  if(isValid("student.out") && isValid("faculty.out"))
  {
    fstream Sstream ("student.out", 	ios::in);
    if(Sstream.is_open())
    {
      string line = "";
      while(getline(Sstream,line))
      {
        Student temp1 (line);
        SNode* t = new SNode(temp1);
        stud.insert(t);
      }
      Sstream.close();
    }
    fstream Fstream ("faculty.out",	ios::in);
    if(Fstream.is_open())
    {
      string line = "";
      while(getline(Fstream,line))
      {
        Faculty temp2 (line);
        FNode* t = new FNode(temp2);
        fac.insert(t);
      }
      Fstream.close();
    }
  }
}
void System::run()
{
  //initializeFiles();
  string choice = "";
  while (choice != "14")
  {
    cout << "Enter choice:" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    getline(cin,choice);
    int ch = stoi(choice);
    if(ch == 1)
    {
      outputStuds();
    }
    else if(ch == 2)
    {
      outputFacs();
    }
    else if(ch == 3)
    {
      cout << "Enter the Students ID number: " << endl;
      string temp = "";
      getline(cin,temp);
      int sid = stoi(temp);
      if(stud.contains(sid))
      {
        outputStudent(sid);
      }
    }
    else if(ch == 4)
    {
      cout << "Enter the Faculty ID number: " << endl;
      string temp = "";
      getline(cin,temp);
      int sid = stoi(temp);
      if(fac.contains(sid))
      {
        outputFaculty(sid);
      }
    }
    else if(ch == 5)
    {
      cout << "Enter the Students ID number: " << endl;
      string temp = "";
      getline(cin,temp);
      int sid = stoi(temp);
      if(stud.contains(sid))
      {
        outputStudentsFacultyAdvisor(sid);
      }
    }
    else if(ch == 6)
    {
      cout << "Enter the Faculty ID number: " << endl;
      string temp = "";
      getline(cin,temp);
      int sid = stoi(temp);
      if(fac.contains(sid))
      {
        outputFacultyStudents(sid);
      }
    }
    else if(ch == 7)
    {
      cout << "Enter the student's name:" << endl;
      string name = "";
      getline(cin,name);
      int num = rand() % 100000;
      while(stud.contains(num))
      {
        num = rand() % 100000;
      }
      cout << "Enter Student's level" << endl;
      string lvl = "";
      getline(cin,lvl);
      cout << "Enter Student's major" << endl;
      string mg = "";
      getline(cin,mg);
      cout << "Enter student's GPA" << endl;
      string gp = "";
      getline(cin,gp);
      float gpa = stof(gp);
      cout << "Enter student's Faculty advisor's ID" << endl;
      string fcid = "";
      getline(cin,fcid);
      int fad = stoi(fcid);
      addStudent(Student(name,num,lvl,mg,gpa,fad));

    }
    else if(ch == 8)
    {
      cout << "Enter Student's ID:" << endl;
      string fcid = "";
      getline(cin,fcid);
      int fad = stoi(fcid);
      removeStudent(fad);
    }
    else if(ch == 9)
    {
      cout << "Enter the Faculty's name:" << endl;
      string name = "";
      getline(cin,name);
      int num = rand() % 100000;
      while(fac.contains(num))
      {
        num = rand() % 100000;
      }
      cout << "Enter Faculty level:" << endl;
      string lv = "";
      getline(cin,lv);
      cout << "ENter Department" << endl;
      string dept = "";
      getline(cin,dept);
      addFaculty(Faculty(name,num,lv,dept));
    }
    else if(ch == 10)
    {
      cout << "Enter the Faculty ID you want to remove" << endl;
      string id = "";
      getline(cin,id);
      int gpa = stoi(id);
      removeStudent(gpa);
    }
    else if(ch == 11)
    {
      cout << "Enter the Student ID" << endl;
      string st = "";
      getline(cin,st);
      int stu = stoi(st);
      if(stud.contains(stu))
      {
        int oldFac = stud.find(stu)->data.getFacID();
        FNode * f1 = fac.find(oldFac);
        SNode * node = stud.find(stu);
        cout << "Enter new Faculty ID:" << endl;
        getline(cin,st);
        int newFac = stoi(st);
        if(fac.contains(newFac))
        {
          node->data.setFacID(newFac);
          f1->data.removeStudent(stu);
          FNode * f2 = fac.find(newFac);
          f2->data.addStudents(stu);
        }
        else
        {
          cout << "The ID doesn't exist" << endl;
        }
      }
      else
      {
        cout << "The ID doesn't exist" << endl;
      }
    }
    else if(ch == 12)
    {
      cout << "Enter the Faculty ID" << endl;
      string fc = "";
      getline(cin,fc);
      int fct = stoi(fc);
      if(fac.contains(fct))
      {
        cout << "Enter the Student ID" << endl;
        string st = "";
        getline(cin,st);
        int stu = stoi(st);
        if(stud.contains(stu))
        {
          FNode * succ = fac.getSuccessor(fac.find(fct));
          fac.find(fct)->data.removeStudent(stu);
          SNode * s = stud.find(stu);
          s->data.setFacID(succ->data.getID());
        }
        else
        {
          cout << "The ID doesn't exist" << endl;
        }
      }
      else
      {
        cout << "The ID doesn't exist" << endl;
      }
    }
    else if(ch == 13)
    {
      undo();
    }
    else if (ch == 14)
    {
      break;
    }
    else
    {
      cout << "Enter a valid input (ie 1)" << endl;
    }
  }
  outFiles();
}
void System::outputStudent(int ID)
{
  cout << stud.find(ID)->data.toString() << endl;
}
void System::outputFaculty(int ID)
{
  cout << fac.find(ID)->data.toString() << endl;
}
void System::outputStudentsFacultyAdvisor(int studID)
{
  SNode * node = stud.find(studID);
  int facid = node->data.getFacID();
  cout << fac.find(facid)->data.toString() << endl;
}
void System::outputFacultyStudents(int facid)
{
  FNode * node = fac.find(facid);
  int len = node->data.getStudCount();
  for(int i = 0; i < len; i++)
  {
    cout << stud.find(node->data.getStudentList()[i])->data.toString() << endl;
  }
}
void System::undo()
{
  string u = stack->pop();
  string val = "";
  val+= u[0];
  val+= u[1];
  string str = "";
  int len = u.length() - 2;
  for(int i = 0; i < len;i++)
  {
    str += u[i + 2];
  }
  if(val == "rf")
  {
    int val1 = std::stoi(str);
    removeFaculty(val1);
  }
  else if(val == "rs")
  {
    int val2 = std::stoi(str);
    removeStudent(val2);
  }
  else if (val == "as")
   {
    Student s (str);
    SNode * n = new SNode(s);
    stud.insert(n);
  }
  else if(val == "af")
  {
    Faculty s (str);
    FNode * n = new FNode(s);
    fac.insert(n);
  }
}
