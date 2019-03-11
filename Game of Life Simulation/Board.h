#include "Array2dInt.h"
#include "Array2dBool.h"
#include <string>
using namespace std;

class Board
{
  private:
    Array2dBool boardBool;
    Array2dInt boardInt;
    Array2dBool NextBoardBool;
    int row;
    int height;
    unsigned int genNum;
  public:
    Board();
    ~Board();
    Array2dInt getIntBoard();
    Array2dBool getBoolBoard();

    bool isEmpty();
    bool isStabilized();

    bool initializeFile(string filename);
    void initializeValue(double d, int row1, int col);
    void initializeOutFile();

    void outputBool();
    void outputInt();
    void outNext();
    void nextGen();
    void outputFile();

    void calcNextBoard();
    void calcStandard();
    void calcMirror();
    void calcDonut();
};
