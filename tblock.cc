#include "tblock.h"

TBlock::TBlock(int x, int y, int r) : x{x}, y{x}, rotation{r} {/*
  if (r == 0) {
    pos0(x, y);
  } else if (r == 1) {
    pos1(x, y);
  } else if (r == 2) {
    pos2(x, y);
  } else if (r == 3) {
    pos3(x, y);
  }*/
}

string TBlock::printBlock() {
    if (rotation == 1) { // UP
        return tBlockRotationUP;
    } else if (rotation == 2) { // LEFT
        return tBlockRotationLEFT;
    } else if (rotation == 3) { // RIGHT
        return tBlockRotationRIGHT;
    }

    return tBlockRotationDOWN;
}
/*
void TBlock::pos0(int x, int y) {
  addPart(x, y + 1);
  addPart(x + 1, y);
  addPart(x + 1, y + 1);
  addPart(x + 2, y + 1);
}

void TBlock::pos1(int x, int y) {
  addPart(x, y + 1);
  addPart(x + 1, y);
  addPart(x + 1, y + 1);
  addPart(x + 1, y + 2);
}

void TBlock::pos2(int x, int y) {
  addPart(x, y);
  addPart(x + 1, y);
  addPart(x + 1, y + 1);
  addPart(x + 2, y);
}

void TBlock::pos3(int x, int y) {
  addPart(x, y);
  addPart(x, y + 1);
  addPart(x, y + 2);
  addPart(x + 1, y + 1);
}*/
/*
TTT
.T.
...

..T
TTT
..T

...
.T.
TTT
  */