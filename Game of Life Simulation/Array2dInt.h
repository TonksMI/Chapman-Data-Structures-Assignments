class Array2dInt
{
  private:
    int *arrI;
    int row;
    int col;
  public:
    Array2dInt();
    Array2dInt(int row, int column);
    Array2dInt(int *arr1, int row1, int column);
    ~Array2dInt();
    void insert(int row, int column, int val);
    int getCell(int row, int column);
    int getRow();
    int getCol();
};
