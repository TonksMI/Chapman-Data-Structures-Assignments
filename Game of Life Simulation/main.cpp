#include <iostream>
#include "Board.h"
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char * argv[])
{
  cout << "Matthew Tonks's Assignment" << endl;
  //initialize Board helper class
  Board m = Board();

  //initializes output file "log.out" and setting variables
  m.initializeOutFile();
  bool outfile = false, stall = false, enter = false;
  int rows = 0, columns = 0;

  //Allows someone to run a file if given at runtime
  if(argc > 1)
  {
    m.initializeFile(argv[1]);
    cout << "What mode do you Want to use? (mirror/standard/Donut)" << endl;
    string mode = "";

    //gets mode user wants to use
    while(true)
    {
      getline(cin,mode);
      if (mode == "mirror" || mode == "standard" || mode == "Donut")
      {
        break;
      }
      else
      {
        cout << "Invalid input Try again" << endl;
      }
    }
    //runs mirror mode
    if(mode == "mirror")
    {
      string temp = " ";
      cin.clear();
      cout << "Do you want a brief pause between Generations?(y/n)" << endl;
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          stall = true;
          break;
        }
        else if(temp == "n")
        {
          stall = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      cout << "Do you want to output to a File? (y/n)" << endl;
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          outfile = true;
          break;
        }
        else if(temp == "n")
        {
          outfile = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      cout << "Do you want to press enter to stop (y/n)" << endl;
      cin.clear();
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          enter = true;
          break;
        }
        else if(temp == "n")
        {
          enter = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      while(!m.isStabilized() && !m.isEmpty())
      {
        char c = 'a';
        m.calcMirror();
        m.calcNextBoard();
        if(m.isStabilized())
        {
          break;
        }
        m.nextGen();
        m.outputBool();
        if(stall)
        {
          sleep(3);
        }
        if(outfile)
        {
          m.outputFile();
        }
        if(enter)
        {
          c = getchar();
        }
      }
    }
    else if(mode == "standard")
    {
      while(!m.isStabilized() && !m.isEmpty())
      {
        char c = 'a';
        m.calcStandard();
        m.calcNextBoard();
        if(m.isStabilized())
        {
          break;
        }
        m.nextGen();
        m.outputBool();
        if(stall)
        {
          sleep(3);
        }
        if(outfile)
        {
          m.outputFile();
        }
        if (enter)
        {
          c = getchar();
        }
      }
    }
    else if(mode == "Donut")
    {
      string temp = "";
      cout << "Do you want a brief pause between Generations?(y/n)" << endl;
      cin.clear();
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          stall = true;
          break;
        }
        else if(temp == "n")
        {
          stall = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      cout << "Do you want to output to a File? (y/n)" << endl;
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          outfile = true;
          break;
        }
        else if(temp == "n")
        {
          outfile = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      cout << "Do you want to press enter to stop (y/n)" << endl;
      while(true)
      {
        getline(cin,temp);
        if (temp == "y")
        {
          enter = true;
          break;
        }
        else if(temp == "n")
        {
          enter = false;
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      while(!m.isStabilized() && !m.isEmpty())
      {
        char c = 'a';
        m.calcDonut();
        m.calcNextBoard();
        if(m.isStabilized())
        {
          break;
        }
        m.nextGen();
        m.outputBool();
        if(stall)
        {
          sleep(3);
        }
        if(outfile)
        {
          m.outputFile();
        }
        if(enter)
        {
          c = getchar();
        }
      }
    }
  }
  //run without a file input at start
  else
  {
    string s = "";
    cout << "Do you want to input a file or initialize with a value? (f/i)" << endl;
    while(true)
    {
      cin >> s;
      if (s == "i" || s == "f")
      {
        break;
      }
      else
      {
        cout << "Invalid input Try again" << endl;
      }
    }
    //create data set based on inputing values and randomly generating it
    if (s == "i")
    {
      cout << "Enter Row size" << endl;
      while(true)
      {
        if (cin >> rows)
        {
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      cout << "ENter Column size" << endl;
      while(true)
      {
        if (cin >> columns)
        {
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      double value = 0.0;
      cout << "Enter value to initialize values" << endl;
      while(true)
      {
        if (cin >> value)
        {
          if( value < 1.0 && value > 0.0)
          {
            break;
          }
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      m.initializeValue(value, rows, columns);

      //get mode
      cout << "What mode do you Want to use? (mirror/standard/Donut)" << endl;
      string mode = "";
      cin.clear();
      while(true)
      {
        cin >> mode;
        if (mode == "mirror" || mode == "standard" || mode == "Donut")
        {
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      //mirror mode
      if(mode == "mirror")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n) (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          m.outputBool();
          char c = 'a';
          m.calcMirror();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }
        }
      }
      //Standard mode
      else if(mode == "standard")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          char c = 'a';
          m.calcDonut();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          m.outputBool();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }

        }
      }
      //donut mode
      else if(mode == "Donut")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          char c = 'a';
          m.calcDonut();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          m.outputBool();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }
        }
      }
    }
    //input file mode
    else if(s == "f")
    {
      string file = "";
      cout << "Enter File Name" << endl;
      getline(cin,file);
      m.initializeFile(file);
      m.outputBool();
      cout << "What mode do you Want to use? (mirror/standard/Donut)" << endl;
      string mode = "";
      while(true)
      {
        cin >> mode;
        if (mode == "mirror" || mode == "standard" || mode == "Donut")
        {
          break;
        }
        else
        {
          cout << "Invalid input Try again" << endl;
        }
      }
      //mirror mode
      if(mode == "mirror")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n) (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          char c = 'a';
          m.calcMirror();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          m.outputBool();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }
        }
      }
      //standard mode
      else if(mode == "standard")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          char c = 'a';
          m.calcDonut();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          m.outputBool();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }
        }
      }
      else if(mode == "Donut")
      {
        string temp = "";
        cout << "Do you want a brief pause between Generations?(y/n)" << endl;
        cin.clear();
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            stall = true;
            break;
          }
          else if(temp == "n")
          {
            stall = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to output to a File? (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            outfile = true;
            break;
          }
          else if(temp == "n")
          {
            outfile = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        cout << "Do you want to press enter to stop (y/n)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "y")
          {
            enter = true;
            break;
          }
          else if(temp == "n")
          {
            enter = false;
            break;
          }
          else
          {
            cout << "Invalid input Try again" << endl;
          }
        }
        while(!m.isStabilized() && !m.isEmpty())
        {
          char c = 'a';
          m.calcDonut();
          m.calcNextBoard();
          if(m.isStabilized())
          {
            break;
          }
          m.nextGen();
          m.outputBool();
          if(stall)
          {
            sleep(3);
          }
          if(outfile)
          {
            m.outputFile();
          }
          if(enter)
          {
            c = getchar();
          }
        }
      }
    }
  }

  return 0;
}
