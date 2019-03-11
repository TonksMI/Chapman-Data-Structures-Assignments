#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

//checks if the file string is valid
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
//constructor destructor
Board::Board()
{
  genNum = 0;
}
Board::~Board()
{

}
//get functions
Array2dInt Board::getIntBoard()
{
  return boardInt;
}
Array2dBool Board::getBoolBoard()
{
  return boardBool;
}
//output bool into console
void Board::outputBool()
{
  cout << "Generation number: "<< genNum << endl;
  for (int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      if(boardBool.getCell(i,j))
      {
        cout << "X ";
      }
      else
      {
        cout << "- ";
      }
    }
    cout << endl;
  }
}
//Output int to conscole
void Board::outputInt()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      cout << boardInt.getCell(i,j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}
//Standard mode
void Board::calcStandard()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      boardInt.insert(i,j,0);
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int count = 0;

      if(i > 0 && j  > 0 && i  < row - 1  && j < height - 1)
      {
        if(boardBool.getCell(i - 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i, j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (j == height - 1 && i > 0 && i < row - 1)
      {
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1 ,j))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (i == 0 && j > 0 && j < height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j+1))
        {
          count++;
        }
        if(boardBool.getCell(i+1,j-1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }

        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (j == 0 && i > 0 && i < row - 1)
      {
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i ,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (i == row - 1 && j > 0 && j < height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i ,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == 0 && j == 0)
      {
        if(boardBool.getCell(1,0))
        {
          count++;
        }
        if(boardBool.getCell(1,1))
        {
          count++;
        }
        if(boardBool.getCell(0,1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == 0 && j == height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j - 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == row - 1 && j == 0)
      {
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == row - 1 && j == height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
    }
  }
}
//Initializes values into the board class
bool Board::initializeFile(string filename)
{
  string val = filename;
  val = validName(val);
  if(val == "exit")
  {
    return false;
  }
  else
  {
    ifstream fil;
    fil.open(val);
    if(fil.is_open())
    {
      string line = " ";
      int i = 0, k = 0;
      while(getline(fil,line))
      {
        if(i == 0)
        {
          stringstream s1 (line);
          s1 >> row;
          i = 1;
        }
        else if(i == 1)
        {
          stringstream s2 (line);
          s2 >> height;
          boardBool = Array2dBool(row, height);
          boardInt = Array2dInt(row,height);
          NextBoardBool = Array2dBool(row,height);
          i = 2;
        }
        else
        {
          for(int j = 0; j < height; j++)
          {
            if(line[j] == 'X')
            {
              boardBool.insert(k,j,true);
            }
            else
            {
              boardBool.insert(k,j,false);
            }
          }
          k++;
        }
      }
      return true;
    }
    else
    {
      cout << "error opening file" << endl;
      return false;
    }
  }
}
//calculates next board
void Board::calcNextBoard()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      if(boardInt.getCell(i,j)  <= 1)
      {
        NextBoardBool.insert(i,j,false);
      }
      else if (boardInt.getCell(i,j) == 2 && boardBool.getCell(i,j))
      {
        NextBoardBool.insert(i,j,true);
      }
      else if (boardInt.getCell(i,j) == 3)
      {
        NextBoardBool.insert(i,j,true);
      }
      else
      {
        NextBoardBool.insert(i,j,false);
      }
    }
  }
}
//outputs next board
void Board::outNext()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      cout << NextBoardBool.getCell(i,j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}
//sets nextgenboard to boardBool
void Board::nextGen()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      boardBool.insert(i,j,NextBoardBool.getCell(i,j));
      NextBoardBool.insert(i,j,false);
    }
  }
  genNum++;
}
//calculate Mirror mode
void Board::calcMirror()
{
  for(int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      boardInt.insert(i,j,0);
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < height; j++)
    {
      int count = 0;

      if(i > 0 && j  > 0 && i  < row - 1  && j < height - 1)
      {
        if(boardBool.getCell(i - 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i, j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (j == height - 1 && i > 0 && i < row - 1)
      {
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1 ,j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i, j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (i == 0 && j > 0 && j < height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j+1))
        {
          count++;
        }
        if(boardBool.getCell(i+1,j-1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i, j))
        {
          count++;
        }
        if(boardBool.getCell(i,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (j == 0 && i > 0 && i < row - 1)
      {
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i ,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i, j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if (i == row - 1 && j > 0 && j < height - 1)
      {
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i, j))
        {
          count++;
        }
        if(boardBool.getCell(i ,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == 0 && j == 0)
      {
        if(boardBool.getCell(i,j))
        {
          count += 3;
        }
        if(boardBool.getCell(1,0))
        {
          count++;
        }
        if(boardBool.getCell(1,1))
        {
          count++;
        }
        if(boardBool.getCell(0,1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == 0 && j == height - 1)
      {
        if(boardBool.getCell(i,j))
        {
          count += 3;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i + 1, j))
        {
          count++;
        }
        if(boardBool.getCell(i + 1,j - 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == row - 1 && j == 0)
      {
        if(boardBool.getCell(i,j))
        {
          count += 3;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j + 1))
        {
          count++;
        }
        if(boardBool.getCell(i,j + 1))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
      if(i == row - 1 && j == height - 1)
      {
        if(boardBool.getCell(i,j))
        {
          count += 3;
        }
        if(boardBool.getCell(i,j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1, j - 1))
        {
          count++;
        }
        if(boardBool.getCell(i - 1,j))
        {
          count++;
        }
        boardInt.insert(i,j,count);
        count = 0;
        continue;
      }
    }
  }
}
//Calculates donut mode
void Board::calcDonut()
{
  {
    for(int i = 0; i < row; i++)
    {
      for(int j = 0; j < height; j++)
      {
        boardInt.insert(i,j,0);
      }
    }
    for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < height; j++)
      {
        int count = 0;

        if(i > 0 && j  > 0 && i  < row - 1  && j < height - 1)
        {
          if(boardBool.getCell(i - 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i, j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i + 1,j + 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if (j == height - 1 && i > 0 && i < row - 1)
        {
          if(boardBool.getCell(i - 1,j))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1 ,j))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, 0))
          {
            count++;
          }
          if(boardBool.getCell(i, 0))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,0))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if (i == 0 && j > 0 && j < height - 1)
        {
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i,j+1))
          {
            count++;
          }
          if(boardBool.getCell(i+1,j-1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i + 1,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(row - 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(row - 1, j))
          {
            count++;
          }
          if(boardBool.getCell(row -1,j + 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if (j == 0 && i > 0 && i < row - 1)
        {
          if(boardBool.getCell(i - 1,j))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i ,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i + 1,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, height - 1))
          {
            count++;
          }
          if(boardBool.getCell(i, height - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,height - 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if (i == row - 1 && j > 0 && j < height - 1)
        {
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(0,j + 1))
          {
            count++;
          }
          if(boardBool.getCell(0, j))
          {
            count++;
          }
          if(boardBool.getCell(0 ,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,j + 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if(i == 0 && j == 0)
        {
          if(boardBool.getCell(0, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, 0))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(1,0))
          {
            count++;
          }
          if(boardBool.getCell(1,1))
          {
            count++;
          }
          if(boardBool.getCell(0,1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if(i == 0 && j == height - 1)
        {
          if(boardBool.getCell(0, 0))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, 0))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(i,j))
          {
            count += 3;
          }
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i + 1, j))
          {
            count++;
          }
          if(boardBool.getCell(i + 1,j - 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if(i == row - 1 && j == 0)
        {
          if(boardBool.getCell(0, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(0, 0))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(i - 1,j))
          {
            count++;
          }
          if(boardBool.getCell(i - 1, j + 1))
          {
            count++;
          }
          if(boardBool.getCell(i,j + 1))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
        if(i == row - 1 && j == height - 1)
        {
          if(boardBool.getCell(0, height - 1))
          {
            count ++;
          }
          if(boardBool.getCell(row - 1, 0))
          {
            count ++;
          }
          if(boardBool.getCell(0, 0))
          {
            count ++;
          }
          if(boardBool.getCell(i,j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1, j - 1))
          {
            count++;
          }
          if(boardBool.getCell(i - 1,j))
          {
            count++;
          }
          boardInt.insert(i,j,count);
          count = 0;
          continue;
        }
      }
    }
  }
}
//initializes with input from user and randomly generating answers
void Board::initializeValue(double b, int row1, int col)
{
  boardBool = Array2dBool(row1, col);
  boardInt = Array2dInt(row1, col);
  NextBoardBool = Array2dBool(row1, col);
  row = row1;
  height = col;
  int count = b * row1 * col;
  cout << count <<endl;
  for (int u = 0; u < row1; u++)
  {
    for(int j = 0; j < col; j++)
    {
      boardBool.insert(u,j,false);
    }
  }
  for(int i = 0; i < count; i++)
  {
    int x = rand() % row1;
    int y = rand() % col;
    while(boardBool.getCell(x,y))
    {
      x = rand() % row1;
      y = rand() % col;
    }
    cout << x <<  " " << y << endl;
    boardBool.insert(x,y,true);
  }
}
//checks if empty
bool Board::isEmpty()
{
  for (int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      if(boardBool.getCell(i,j))
      {
        return false;
      }
    }
  }
  return true;
}
//check if isStabilized
bool Board::isStabilized()
{
  for (int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      if(boardBool.getCell(i,j) != NextBoardBool.getCell(i,j))
      {
        return false;
      }
    }
  }
  return true;
}
void Board::outputFile()
{
  ofstream stream;
  stream.open("log.out", ofstream::app);
  stream << "Generation: " << genNum + 1<< endl;
  stream << row << endl;
  stream << height << endl;
  for (int i = 0; i < row; i++)
  {
    for(int j = 0; j < height; j++)
    {
      if(boardBool.getCell(i,j))
      {
        stream << "X ";
      }
      else
      {
        stream << "- ";
      }
    }
    stream << endl;
  }
  stream.close();
}
//output initializeOutFile
void Board::initializeOutFile()
{
  ofstream st("log.out");
  st.close();
}
