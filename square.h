#ifndef SQUARE_H
#define SQUARE_H
#include <string>

using namespace std;

class Board;

class Square {
  public:
    int row;
    int col;
    bool show;
    bool isOccupied;
    char setChar;
    string symbol;

    Board *board; 
    Square(int r, int c);
    void setSquare(char newChar);
    string print();
};

#endif