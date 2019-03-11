#include <iostream>
#include "Array2dBool.h"

Array2dBool::Array2dBool()
{

}
Array2dBool::Array2dBool(int row1, int col1)
{
  arrB = new bool [row1 * col1];
  row = row1;
  col = col1;
  for(int i = 0; i < row1 * col1; i++)
  {
    arrB[i] = false;
  }
}
Array2dBool::Array2dBool(bool* arr1, int row1, int col1)
{
  arrB = arr1;
  row = row1;
  col = col1;
}
Array2dBool::~Array2dBool()
{

}
bool Array2dBool::getCell(int row1, int col1)
{
    return arrB[row1 * col + col1];
}
void Array2dBool::insert(int row2, int column2, bool val)
{
  arrB[row2 * col + column2] = val;
}
int Array2dBool::getRow()
{
  return row;
}
int Array2dBool::getCol()
{
  return col;
}
