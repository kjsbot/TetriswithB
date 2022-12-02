#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include "block.h"
#include "abstractlevel.h"
#include "square.h"

using namespace std;

class Board {
  int rows;
  int cols;
  vector<vector<Square>> board;
  vector<Block> blocks; // replaced with pointers?

  int player;
  int levelNum;
  //AbstractLevel *level;
  int score;
  bool isBlind;
  bool isForce;
  bool heavy;
  bool isLost;

/*  Block *currBlock;
  Block *nextBlock; // replaced */

  unique_ptr<Block> currBlock;
  unique_ptr<Block> nextBlock; 
  char blockType;
  int xPos;
  int yPos;
  int r;
  int blockSize;

  public:
    Board(int player, int level);
    ~Board();

    int clearedLines();
    void getNextBlock();
    bool isRowFilled(int row);
    void deleteRow(int row);
    //void setBlind();
    //void unsetBlind();
    bool isHeavy();
    void reset();
    void print();
    //void setForce();
    void updateLevel(int direction);
    void generateNextBlock(int x, int y, int r);
    bool validMove();
    void rotate(int direction);
    bool down();
    void sideways(int direction);
    void drop();
    void setBlock();
    //void nextBlock();
};

#endif