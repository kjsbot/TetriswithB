#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
#include "blockpart.h"

using namespace std;

class Block {
  private:
    char symbol;
    int x;
    int y;
    int r;
    vector<BlockPart> parts;
  public:
    Block();
    ~Block();
    void addPart();
    int xPos(int part);
    int yPos(int part);
    virtual void pos0();
    virtual void pos1();
    virtual void pos2();
    virtual void pos3();
};

#endif