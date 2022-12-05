#ifndef TBLOCK_H
#define TBLOCK_H
#include "block.h"
#include <string>

class TBlock : public Block {
  private:
    string tBlockRotationUP = "        TTT  T  "; //{"    \n", "    \n", "TTT \n", " T  \n"};
    string tBlockRotationRIGHT = "     T  TT   T  "; //{"    \n", " T  \n", "TT  \n", " T  \n"};
    string tBlockRotationDOWN = "         T  TTT "; //{"    \n", "    \n", " T  \n", "TTT \n"};
    string tBlockRotationLEFT = "    T   TT  T   "; //{"    \n", "T   \n", "TT  \n", "T   \n"};
    
    int x;
    int y;
    int rotation; //don't need this
    vector<BlockPart> parts;
  public:
    TBlock(int x, int y, int r);
    string printBlock();
    //void addPart(int x, int y);
    //void pos0(int x, int y);
    //void pos1(int x, int y);
    //void pos2(int x, int y);
    //void pos3(int x, int y);
};

#endif