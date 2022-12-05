#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include <string>
#include "blockpart.h"

using namespace std;

class Block {
  public:
    char symbol;

    //int x;
    //int y;
    //virtual int rotation;

    vector<BlockPart> parts;
    //int xPos(int part);
    //int yPos(int part);
    virtual string printBlock() = 0; // Used for printing block in the display (outside the game)
    //virtual void addPart(int x, int y) = 0;
    //virtual void pos0(int x, int y) = 0;
    //virtual void pos1(int x, int y) = 0;
    //virtual void pos2(int x, int y) = 0;
    //virtual void pos3(int x, int y) = 0;
};

#endif