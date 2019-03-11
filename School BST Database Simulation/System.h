#include "StudentDB.h"
#include "FacultyDB.h"
#include "Stack.h"
using namespace std;

class System
{
private:
  StudentDB stud;
  FacultyDB fac;
  Stack<std::string> *stack;

public:
  System()
  {
    stud = StudentDB();
    fac = FacultyDB();
    stack = new Stack<std::string>();
  }
  ~System()
  {

  }

  void run();
  void undo();
  void addStudent(Student st);
  void addFaculty(Faculty f);
  void removeStudent(int ID);
  void removeFaculty(int ID);
  void outputStuds();
  void outputFacs();
  void outFiles();
  void initializeFiles();
  void outputStudent(int ID);
  void outputFaculty(int ID);
  void outputStudentsFacultyAdvisor(int studID);
  void outputFacultyStudents(int facid);
};
