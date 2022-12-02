#ifndef SQUARE_H
#define SQUARE_H
#include <string>

using namespace std;

class Board;

class Square {
  public:
  //  int row;
  //  int col;
    bool show;
    bool isOccupied;
    char setChar;
    // bool isBlind?;
    Board *board; 
    Square();
    void setSquare(char newChar);
    string print();
};

#endif