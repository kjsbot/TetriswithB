#include "levelone.h"

LevelOne::LevelOne() {}

LevelOne::~LevelOne() {}

Block* LevelOne::generateNextBlock() {
  int i = rand() % (11 - 0 + 1) + 0; // between 0-6

  /*if (blocks[i] == 'I') { return IBlock; }
  else if (blocks[i] == 'J') { return new JBlock; }
  else if (blocks[i] == 'L') { return new LBlock; }
  else if (blocks[i] == 'O') { return new OBlock; }
  else if (blocks[i] == 'S') { return new SBlock; }
  else if (blocks[i] == 'Z') { return new ZBlock; }*/
  
  return new TBlock(0, 0, 0);
}