#include<chrono>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void heapify(double* arr, int count , int i)
{
  int large = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if( left < count && arr[left] > arr[large])
  {
    large = left;
  }
  if(right < count && arr[right] > arr[large])
  {
    large = right;
  }
  if(large != i)
  {
    double temp = arr[i];
    arr[i] = arr[large];
    arr[large] = temp;
    heapify(arr,count,large);
  }
}
void heapSort(double* arr, int count)
{
  for(int i = count / 2 - 1; i >= 0; i--)
  {
    heapify(arr, count, i);
  }
  for(int i = count - 1; i >= 0; i--)
  {
    double temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}
void bubbleSort(double* arr, int count)
{
  for(int i = 0; i < count - 1; i++)
  {
    for(int j = 0; j < count - i - 1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        double temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
int partition(double* arr, int low, int high)
{
  double pivot = arr[high];
  int i = (low - 1);
  for(int j = low; j <= high - 1; j++)
  {
    if(arr[j] <= pivot)
    {
      i++;
      double temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  double temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}
void QuickSort(double* arr, int low, int high)
{
  if( low < high)
  {
    int par = partition(arr, low, high);
    QuickSort(arr, low, par - 1);
    QuickSort(arr, par + 1, high);
  }
}
void insertionSort(double arr[], int count)
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
bool isValid(std::string input)
{
  if(input == "exit")
  {
    return true;
  }
  ifstream file (input);
  if(file.is_open())
  {
    file.close();
    return true;
  }
  else
  {
    return false;
  }
}

int main(int argc, char * argv[])
{
  typedef std::chrono::high_resolution_clock Time;
  typedef std::chrono::milliseconds ms;
  typedef std::chrono::duration<float> fsec;
  if(argc > 1)
  {
    if(isValid(argv[1]))
    {
      ifstream file (argv[1]);
      std::string line = "";
      getline(file,line);
      int count = stoi(line);
      double db1[count];
      double db2[count];
      double db3[count];
      double db4[count];
      int i = 0;
      while(getline(file,line))
      {
        double temp = stod(line);
        db1[i] = temp;
        db2[i] = temp;
        db3[i] = temp;
        db4[i] = temp;
        i++;
      }
      auto start1 = Time::now();
      bubbleSort(db1, count);
      auto finish1 = Time::now();
      fsec fs1 = finish1 - start1;
      ms d1 = std::chrono::duration_cast<ms>(fs1);
      std::cout <<"Bubble Sort took: "<< d1.count()<< "ms" << std::endl;
      auto start2 = Time::now();
      QuickSort(db2, 0, count - 1);
      auto finish2 = Time::now();
      fsec fs2 = finish2 - start2;
      ms d2 = std::chrono::duration_cast<ms>(fs2);
      std::cout <<"Quick Sort took: "<< d2.count()<< "ms" << std::endl;
      auto start3 = Time::now();
      insertionSort(db3,count);
      auto finish3 = Time::now();
      fsec fs3 = finish3 - start3;
      ms d3 = std::chrono::duration_cast<ms>(fs3);
      std::cout <<"Insertion Sort took: "<< d3.count()<< "ms" << std::endl;
      auto start4 = Time::now();
      heapSort(db4,count);
      auto finish4 = Time::now();
      fsec fs4 = finish4 - start4;
      ms d4 = std::chrono::duration_cast<ms>(fs4);
      std::cout <<"Heap Sort took: "<< d4.count()<< "ms" << std::endl;
      return 0;
    }
    else
    {
      std::cout << "File not found" << std::endl;
    }
  }
}
