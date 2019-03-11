#include <iostream>
#include "Array2dInt.h"

using namespace std;

Array2dInt::Array2dInt()
{

}
Array2dInt::Array2dInt(int row1, int column1)
{
  arrI = new int [row1 * column1];
  row = row1;
  col = column1;
  for(int i = 0; i < row1 * column1; i++)
  {
    arrI[i] = 0;
  }
}
Array2dInt::Array2dInt(int *arr1, int row1, int col1)
{
  arrI = arr1;
  row = row1;
  col = col1;
}
Array2dInt::~Array2dInt()
{

}
int Array2dInt::getCell(int row1, int column1)
{
  if(row1 < row && column1 < col)
  {
    return arrI[row1 * col + column1];
  }
}
void Array2dInt::insert(int row2, int column2, int val)
{
  arrI[row2 * col + column2] = val;
}
int Array2dInt::getRow()
{
  return row;
}
int Array2dInt::getCol()
{
  return col;
}
