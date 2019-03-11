#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define PI 3.14

using namespace std;

//random float between 0.0 and 1.0
double randNum()
{
  double temp = (double)rand() / (RAND_MAX) - 1;
  return temp;
}
//random number on gaussian distribution
double GaussianDistribution()
{
  double temp1 = sqrt(2 *  exp(1.0 / randNum()));
  double temp2 = cos(2.0 * PI * randNum());
  //cout << temp1 <<  "*" << temp2 <<endl;
  return temp1 * temp2;
}
// gets count for the bigram
double value(double mean, double stdvar)
{
  double temp = stdvar * GaussianDistribution() + mean;
  return temp;
}
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
//how it outputs the file
void printFile(float mean, float variance, int sum, int aa, int ag, int ac, int at, int ga, int gg, int gc, int gt, int ca, int cg, int cc, int ct, int ta, int tg, int tc, int tt, int a, int g, int c, int t)
{
  //output basics
  int count = a + g + c + t;
  double var = sqrt(variance);
  double temp = 0;
  double proba = a * 1.0 / count;
  double probg = g * 1.0 / count;
  double probc = c * 1.0 / count;
  double probt = t * 1.0 / count;
  ofstream output;
  output.open("MatthewTonks.out");
  output.precision(10);
  output << "Matthew Tonks" << endl;
  output << "2289793" << endl;
  output << "Mean : "<< mean << endl;
  output << "Variance : " << variance << endl;
  output << "Sum : " << sum << endl;
  output << "A : " << (proba * 100) << "%" << endl;
  output << "G : " << (probg * 100) << "%" << endl;
  output << "C : " << (probc * 100) << "%" << endl;
  output << "T : " << (probt * 100) << "%" << endl;
  output << "AA : " << ((aa * 1.0 / sum) * 100) << "%" << endl;
  output << "AG : " << ((ag * 1.0 / sum) * 100) << "%" << endl;
  output << "AC : " << ((ac * 1.0 / sum) * 100) << "%" << endl;
  output << "AT : " << ((at * 1.0 / sum) * 100) << "%" << endl;
  output << "GA : " << ((ga * 1.0 / sum) * 100) << "%" << endl;
  output << "GG : " << ((gg * 1.0 / sum) * 100) << "%" << endl;
  output << "GC : " << ((gc * 1.0 / sum) * 100) << "%" << endl;
  output << "GT : " << ((gt * 1.0 / sum) * 100) << "%" << endl;
  output << "CA : " << ((ca * 1.0 / sum) * 100) << "%" << endl;
  output << "CG : " << ((cg * 1.0 / sum) * 100) << "%" << endl;
  output << "CC : " << ((cc * 1.0 / sum) * 100) << "%" << endl;
  output << "CT : " << ((ga * 1.0 / sum) * 100) << "%" << endl;
  output << "TA : " << ((ta * 1.0 / sum) * 100) << "%" << endl;
  output << "TG : " << ((tg * 1.0 / sum) * 100) << "%" << endl;
  output << "TC : " << ((tc * 1.0 / sum) * 100) << "%" << endl;
  output << "TT : " << ((tt * 1.0 / sum) * 100) << "%" << endl;
  probg += proba;
  probc += probg;
  for (int i = 0; i < 1000; i++)
  {
    temp = (int)value(mean, var);
    for (int j = 0; j < temp; j++)
    {
      double ran = (double) rand() / RAND_MAX;
      if(ran < proba)
      {
        output << "A";
      }
      else if(ran < probg)
      {
        output << "G";
      }
      else if(ran < probc)
      {
        output << "C";
      }
      else
      {
        output << "T";
      }
    }
    output << endl;
  }
}
//main method
int main(int argc, char * argv[])
{
  cout << "Matthew Tonks Assignment 1" << endl;
  string option = "";
  string txt = "";
  //gets the arguement if it was started with a value
  if (argc  >=  2)
  {
      txt = argv[1];
  }
  //loop to run the program multiple times
  while(option != "y")
  {
    string fileName = validName(txt);
    if(fileName != "exit")
    {
      string line;
      string temp;
      fstream file(fileName);

      if(file.is_open())
      {
        int aa = 0, ag = 0, at = 0, ac = 0;
        int ga = 0, gg = 0, gt = 0, gc = 0;
        int ta = 0, tg = 0, tt = 0, tc = 0;
        int ca = 0, cg = 0, ct = 0, cc = 0;
        int a = 0, g = 0, c = 0, t = 0;
        int fail = 0;
        int lineCount = 0;
        int sum = 0;
        double mean = 0.0;
        double variance = 0.0;
        while(getline(file,line))
        {
          mean += line.length();
          lineCount++;
        }
        mean /= (lineCount * 1.0);
        file.clear();
        file.seekg(0, file.beg);
        while(getline(file,line))
        {
          for(int i = 0; i < line.length(); i++)
          {
            if (isalpha(line[i]))
            {
              temp += toupper(line[i]);
              if(toupper(line[i]) == 'A')
              {
                a++;
              }
              else if (toupper(line[i]) == 'G')
              {
                g++;
              }
              else if(toupper(line[i]) == 'C')
              {
                c++;
              }
              else if(toupper(line[i]) == 'T')
              {
                t++;
              }
            }
          }
          line = temp;
          if((temp.length() + 1) % 2 == 0)
          {
            string t = "";
            for(int i = 0; i < temp.length() - 1; i++)
            {
              t[i] += temp[i];
            }
            temp = t;
          }
          //counts the bigrams
          string s = "";
          for(int i = 0; i < temp.length(); i +=2)
          {
            s += temp[i];
            s += temp[i+1];
            if(s == "AA")
            {
              aa+=1;
              sum+=1;
            }
            else if(s == "AG")
            {
              ag+=1;
              sum+=1;
            }
            else if(s == "AC")
            {
              ac+=1;
              sum+=1;
            }
            else if(s == "AT")
            {
              at+=1;
              sum+=1;
            }
            else if(s == "GA")
            {
              ga+=1;
              sum+=1;
            }
            else if(s == "GG")
            {
              gg+=1;
              sum+=1;
            }
            else if(s=="GC")
            {
              gc+=1;
              sum+=1;
            }
            else if(s == "GT")
            {
              gt+=1;
              sum+=1;
            }
            else if(s == "CA")
            {
              ca+=1;
              sum+=1;
            }
            else if(s == "CG")
            {
              cg+=1;
              sum+=1;
            }
            else if(s == "CC")
            {
              cc+=1;
              sum+=1;
            }
            else if(s == "CT")
            {
              ct+=1;
              sum+=1;
            }
            else if(s =="TA")
            {
              ta+=1;
              sum+=1;
            }
            else if (s =="TG")
            {
              tg+=1;
              sum+=1;
            }
            else if(s == "TC")
            {
              tc+=1;
              sum+=1;
            }
            else if(s == "TT")
            {
              tt+=1;
              sum+=1;
            }
            s = "";
          }
          line = "";
          temp = "";
          variance += (line.length() - mean) * (line.length() - mean);
        }
        //calcualte variance
        variance /= (lineCount - 1);
        //outputs mean and variance and then calls the printfile
        cout<< mean <<" mean" << endl;
        cout << variance << " variance" << endl;
        //print file
        printFile(mean, variance, sum, aa, ag, ac, at, ga, gg, gc, gt, ca, cg, cc, ct, ta, tg, tc, tt, a, g, c, t);
        txt = "";
      }
      else
      {
        //catches error when opening the file
        cout<<"error opening file"<<endl;
      }
    }
    //confirmation to continue or not
    cout << "Do you want to exit (y/n)" << endl;
    getline(cin, option);
  }
return 0;
}
