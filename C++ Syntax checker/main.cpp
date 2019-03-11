#include "stack.h"
#include <iostream>
#include <fstream>

using namespace std;

//Verifies file name
bool isValid(string input)
{
  if(input == "exit")
  {
    return true;
  }
  fstream file (input);
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
//main
int main(int argc, char * argv[])
{
  bool pass = true;
  cout << "Matt Tonks'syntax Assignment 3" << endl;
  string filename = "";
  //reads in filename from arguement
  if(argc = 0)
  {
    cout << "Enter a file name" << endl;
    getline(cin,filename);
    filename = validName(filename);
    if(filename == "exit")
    {
      return 0;
    }
  }
  else
  {
    filename = validName(argv[1]);
    if(filename == "exit")
    {
      return 0;
    }
  }
  //the magic variables
  stack<char> syntax;
  unsigned int lineCount = 0;
  string line;

  //actual code
  while(pass)
  {
    //open file
    fstream file(filename);
    if(file.is_open())
    {
      //reads line by line and char by char
      bool skip = false;
      unsigned int linenum = 0;
      while(getline(file,line))
      {
        lineCount++;
        stack<char> quote;
        bool open = true;
        for(int i = 0; i < line.length(); i++)
        {
          if(line[i] == '/' && line[i+1] == '/')
          {
            break;
          }
          if(line[i] == '/' && line[i+1] == '*')
          {
            i++;
            skip = true;
            linenum = lineCount;
          }
          if (line[i] == '*' && line[i+1] == '/')
          {
            i++;
            if(!skip)
            {
              cout << "Error at line " << lineCount << ": extra */ found" << endl;
              pass = false;
            }
            skip = false;
          }
          if (!skip)
          {
            if(line[i]=='\\')
            {
              i++;
              continue;
            }
            if(line[i] == '\'')
            {
              i++;
              for (;i < line.length();i++)
              {
                if(line[i]=='\\')
                {
                  i++;
                  continue;
                }
                if(line[i] == '\'')
                {
                  break;
                }
              }
            }
            else if(line[i] == '"')
            {
              i++;
              for (;i < line.length();i++)
              {
                if(line[i]=='\\')
                {
                  i++;
                  continue;
                }
                if(line[i] == '"')
                {
                  break;
                }
              }
            }
            //Char's neccessary for the computation
            if(line[i] == '[' || line[i] == '{' || line[i] == '(' || line[i] == ']' || line[i] == '}' || line[i] == ')')
            {
              //Add front part of the values to stack
              if ((line[i] == '(') || (line[i] == '[') || (line[i] == '{'))
              {
                syntax.push(line[i]);
              }
              //cases where the syntax is good
              else if ((syntax.peek() == '(') && (line[i] == ')'))
              {
                syntax.pop();
              }
              else if ((syntax.peek() == '[') && (line[i] == ']'))
              {
                syntax.pop();
              }
              else if ((syntax.peek() == '{') && (line[i] == '}'))
              {
                syntax.pop();
              }
              //Error catching when char isn't expected
              else if ((syntax.peek() == '(') && (line[i] == ']' || line[i] == '}'))
              {
                cout << "Error at line " << lineCount << ": ')' expected. '" << line[i] << "' was found instead." << endl;
                pass = false;
              }
              else if ((syntax.peek() == '[') && (line[i] == ')' || line[i] == '}'))
              {
                cout << "Error at line " << lineCount << ": ']' expected. '" << line[i] << "' was found instead." << endl;
                pass = false;
              }
              else if ((syntax.peek() == '{') && (line[i] == ']' || line[i] == ')'))
              {
                cout << "Error at line " << lineCount << ": '}' expected. '" << line[i] << "' was found instead." << endl;
                pass = false;
              }
              //error catching when there are extra characters
              else if(syntax.getCount() == 0)
              {
                if(line[i] == ')')
                {
                  cout << "Error at line " << lineCount << " : extra " << line[i] << " found." << endl;
                  pass = false;
                }
                else if(line[i] == '}')
                {
                  cout << "Error at line " << lineCount << " : extra " << line[i] << " found." << endl;
                  pass = false;
                }
                else if(line[i] == ')')
                {
                  cout << "Error at line " << lineCount << " : extra " << line[i] << " found." << endl;
                  pass = false;
                }
              }
            }
          }
        }
      }
      if(skip)
      {
        cout << "Error: open /* at line: " << linenum << endl;
        pass = false;
      }
      //the restart statement for a new file
      if(pass)
      {
        string temp = "";
        cout << "The syntax is good in file: " << filename << endl;
        cout << "Would you like to enter another file to check? (yes/no)" << endl;
        while(true)
        {
          getline(cin,temp);
          if (temp == "yes")
          {
            pass = true;
            break;
          }
          else if(temp == "no")
          {
            pass = false;
            break;
          }
          else
          {
            cout << "Invalid input. Try again." << endl;
          }
        }
      }
    }
  }
}
