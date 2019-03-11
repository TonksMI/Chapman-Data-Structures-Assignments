class Array2dBool
{
  private:
    bool *arrB;
    int row;
    int col;
  public:
    Array2dBool();
    Array2dBool(int row, int column);
    Array2dBool(bool* arr1, int row1, int col1);
    ~Array2dBool();
    void insert(int row, int column, bool val);
    bool getCell(int row, int column);
    int getRow();
    int getCol();
};
