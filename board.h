#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <memory>
#include <iostream>
#include "block.h"
#include "abstractlevel.h"
#include "square.h"
#include "blockpart.h"

using namespace std;

class AbstractLevel;

class Board {
  public:
  int rows;
  int cols;
  vector<vector<Square>> board;
  vector<Block> blocks; // replaced with pointers?

  int player;
  int levelNum;
  AbstractLevel *level;
  int score;
  bool isBlind;
  bool isForce;
  bool heavy;
  bool lost;

    string fileName;

  //unique_ptr<Block> currBlock;
  //unique_ptr<Block> nextBlock;
  Block *currBlock;
  Block *nextBlock;

  char blockType;
  int xPos;
  int yPos;
  int r;
  int blockSize;

    Board(int player, int level, string f);
    ~Board();

    void printRow(int row);

    int getPlayer();
    bool isLost();
    
    bool isRowFilled(int row);
    int deleteRows();
    void deleteRow(int row);

    void updateLevel(int direction);
    Block* getNextBlock();

    bool validMove();

    void setLevel();

    bool isHeavy();


    void generateNextBlock(int x, int y, int r);
    void drop();
    void down();
    
    //void reset();
    /*
    int clearedLines();
    
    //void setBlind();
    //void unsetBlind();
    
    
    //void setForce();
    
    void generateNextBlock(int x, int y, int r);
    void rotate(int direction);
    void down();
    void downHeavy();
    bool downNorm();
    void sideways(int direction);
    void setBlock();
    //void nextBlock();
    void updateBlocksPerRow();*/

    vector<int> blockspartsPerRow;
/*
    bool newGame;

    Block* currBlockMove;
    char blockType;
    int x;
    int y;
    int r;
    int blockSize;

        int turns;
    
    void addTurn();
    int getTurns();
    void playerLost();
    int updateRow(int row);
    void addTurns();
    int getTurns();
    void addTurns();
    int getTurns();
    int getx();
    int gety();
    int getr();
    void makeNewBlock();
    void updateCurrBlock(int xNew, int yNew, int rNew);
    Block* generateNextBlock(char type, int x, int y, int r);
    void setBlockType(char type, char replacedBlock);*/
};

#endif