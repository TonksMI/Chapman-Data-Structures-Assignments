#include "GameHelper.h"
#include <iostream>
#include <fstream>

using namespace std;


void inertionSort(int arr[], int count)
{
  for(int i = 0; i < count; i++)
  {
    for(int j = i; j > 0 && arr[j-1] > arr[j]; j--)
    {
      int tmp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = tmp;
    }
  }
}
GameHelper::GameHelper()
{
  data = StudentLine();
  wline = StudentLine();
  window = new int [1];
  windowSize = 0;
}
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
void GameHelper::initializeWindow(int count)
{
  window = new int[count];
  wData = new int[count];
  windowSize = count;
  for(int i = 0; i < count; i++)
  {
    window[i] = 0;
    wData[i] = 0;
  }
}
void GameHelper::decrementTime()
{
  for(int i = 0; i < windowSize; i++)
  {
    if(window[i] == 0)
    {
      wData[i]++;
    }
  }
  for(int i = 0; i < windowSize; i++)
  {
    if(window[i] != 0)
    {
      window[i]--;
    }
  }
}
void GameHelper::runSim()
{
  string filename = "";
  cout << "Matt Tonks' Assignment 4" << endl;
  filename = validName(filename);
  string l = "";
  fstream file(filename);
  if(file.is_open())
  {
    int time = 0;
    getline(file,l);
    initializeWindow(stoi(l));
    getline(file,l);
    int timeMarker = stoi(l);
    isNew = true;
    int count1 = 0;
    do
    {
      if(time == timeMarker)
      {
        isNew = false;
        getline(file,l);
        count1 = stoi(l);
        for(int i = 0; i < count1; i++)
        {
          getline(file,l);
          wline.enterLine(stoi(l));
        }
        getline(file,l);
        if(!file.eof())
        {
          timeMarker = stoi(l);
        }
      }
      lineToWindow();
      wline.incrementTimeWaited();
      if(isdone() && !isNew)
      {
        break;
      }
      decrementTime();
      time++;
    }while (true);
    outputStatistics();
  }
}
void GameHelper::runSim(char s[])
{
  string filename = s;
  cout << "Matt Tonks' Assignment 4" << endl;
  filename = validName(filename);
  string l = "";
  fstream file(filename);
  if(file.is_open())
  {
    int time = 0;
    getline(file,l);
    initializeWindow(stoi(l));
    getline(file,l);
    int timeMarker = stoi(l);
    isNew = true;
    int count1 = 0;
    do
    {
      if(time == timeMarker)
      {
        isNew = false;
        getline(file,l);
        count1 = stoi(l);
        for(int i = 0; i < count1; i++)
        {
          getline(file,l);
          wline.enterLine(stoi(l));
        }
        getline(file,l);
        if(!file.eof())
        {
          timeMarker = stoi(l);
        }
      }
      lineToWindow();
      wline.incrementTimeWaited();
      if(isdone() && !isNew)
      {
        break;
      }
      decrementTime();
      time++;
    }while (true);
    outputStatistics();
  }
}
void GameHelper::lineToWindow()
{
  for(int i = 0; i < windowSize; i++)
  {
    if(window[i] == 0 && !wline.isEmpty())
    {
      window[i] = wline.peekWaitTime();
      data.enterLine(wline.peekWaitTime(), wline.peekTimeWaited());
      wline.exitLine();
    }
  }
}
void GameHelper::outputStatistics()
{
  int count = data.getTotal();
  int tw[count];
  for (int i = 0; i < count; i++)
  {
    tw[i] = data.peekTimeWaited();
    data.exitLine();
  }
  float median;
  inertionSort(tw,count);
  if(count%2 != 0)
  {
    median = tw[count/2];
  }
  else
  {
    median = (tw[count/2] + tw[count/2 - 1])/2.0;
  }
  float meanWait = 0.0;
  int countTen = 0;
  int longestWait = 0;
  for(int i = 0; i < count; i++)
  {
    meanWait += tw[i];
    if(tw[i] > 10)
    {
      countTen++;
    }
    if(tw[i] > longestWait)
    {
      longestWait = tw[i];
    }
  }
  meanWait = meanWait / count;

  float meanIdle = 0.0;
  int longestIdle = 0;
  int idleFive = 0;
  for(int i = 0; i < windowSize; i++)
  {
    meanIdle += wData[i];
    if(wData[i] > longestIdle)
    {
      longestIdle = wData[i];
    }
    if(wData[i] > 5)
    {
      idleFive++;
    }
  }
  meanIdle = meanIdle / windowSize;
  cout << "Mean wait time: " << meanWait << endl;
  cout << "Median wait time: " << median << endl;
  cout << "Longest wait time: " << longestWait << endl;
  cout << "Count of how many waited over 10 minutes: " << countTen << endl;
  cout << "Mean window idle time: " << meanIdle << endl;
  cout << "Longest window idle time: " << longestIdle << endl;
  cout << "Number of windows idle over 5 min: " << idleFive << endl;
}
bool GameHelper::isdone()
{
  for(int i = 0; i < windowSize; i++)
  {
    if(window[i]!=0)
    {
      return false;
    }
  }
  return true;
}
