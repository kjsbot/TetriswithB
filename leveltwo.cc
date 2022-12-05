#include "leveltwo.h"

LevelTwo::LevelTwo() {}

LevelTwo::~LevelTwo() {}

Block* LevelTwo::generateNextBlock() {/*
  int value = rand() % (5 - 0 + 1) + 0; // between 0-6

  if (value == 0 ) { return IBlock; }
  else if (value == 1) { return new JBlock; }
  else if (value == 2) { return new LBlock; }
  else if (value == 3) { return new OBlock; }
  else if (value == 4) { return new SBlock; }
  else if (value == 5) { return new ZBlock; }*/
  
  return new TBlock(0, 0, 0);
}