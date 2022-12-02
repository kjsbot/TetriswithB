#include "board.h"

using namespace std;

Board::Board(int player, int level) : rows{18}, cols{11}, player{player}, levelNum{level} {}

/*Board::~Board() {
//  delete currBlock;
//  delete nextBlock;
  //delete level;
}*/


void Board::print() {
  cout << "Level:     " << levelNum << endl; // correct num of spaces???
  cout << "Score:" << score << endl; // double digit score
  cout << "-----------" << endl;

  for (int r = 0; r <= rows; r++) {
    for (int c = 0; c <= cols; c++) {
      if (board[r][c].show && board[r][c].isOccupied) { board[r][c].print(); }
      else { cout << " "; }
    }
  }
  
  cout << "-----------" << endl;
  cout << "Next:" << endl;
  //..nextBlock...; // what rotation will the next block be in?
}

bool Board::isRowFilled(int row) {
  for (int i = 0; i <= cols; i++) {
    if (!board[row][i].isOccupied) return false;
  }

  return true;
}

void Board::deleteRow(int row) {/*
  for (int i = 0; i <= cols; i++) {
    Block *toCoorRemoveFrom = board[row][i]->Square->Block;
    <vector<coordinate>> newCoordinates;

    for (auto coor : toCoorRemoveFrom->parts) {
      if (coor != {row, i}) { newCoordinates.push_back({row, i}); } // {row, i} is used to represent a coor
    }

    toCoorRemoveFrom->parts = parts;
  }

  for (auto block : blocks) {
    while (validMove(0, -1, 0)) { // keep on moving the block down until you can't
      down(block);
    }
  }*/
}

bool Board::isHeavy() {
  if (heavy) { return true; }
  return false;
}

////////////////////// MOVEMENT //////////////////////
/*
bool Board::validMove(int x, int y, int rotation) {
  for (coordinate in currBlock->coordinates) {
    int newPosX = coordinate.X + X; // row
    int newPosY = coordinate.Y + Y; // col
    
    // apply rotation + update newPosX, newPosY //

    if (newPosX < 0 || newPosY < 0 || newPosX > 18 || newPosY > 11) { return false; }
    if (board[newPosX][newPosY] is occupied) { return false; }
  }

  return true;
}

void Board::down() {
  for (coordinate in currBlock->coordinates) {
    currBlock->coordinate.Y += 1;
  }
}

void Board::sideways(int direction) { // direction = -1 or 1
  for (coordinate in currBlock->coordinates) {
    currBlock->coordinate.X += direction;
  }
}

void Board::rotate(int direction) {
  currBlock->();
}
*/
////////////////////// MOVEMENT V2 //////////////////////
/*
void Board::generateNextBlock(int x, int y, int r) {
    switch (blockType) {
      case 'I': 
        nextBlock = make_unique<Block>(IBlock(x, y, r));
        break;
      case 'J': 
        nextBlock = make_unique<Block>(JBlock(x, y, r));
        break;
      case 'L': 
        nextBlock = make_unique<Block>(LBlock(x, y, r));
        break;
      case 'O': 
        nextBlock = make_unique<Block>(OBlock(x, y, r));
        break;
      case 'S': 
        nextBlock = make_unique<Block>(SBlock(x, y, r));
        break;
      case 'Z': 
        nextBlock = make_unique<Block>(ZBlock(x, y, r));
        break;
      case 'T': 
        nextBlock = make_unique<Block>(TBlock(x, y, r));
        break;
    }
}

bool Board::validMove() {
  for (int i = 0; i < blockSize; ++i) {
    int x = nextBlock->xPos(i);
    int y = nextBlock->yPos(i);
    if (board[y][x].isOccupied) {
      return false;
    }
  }
  return true;
}

bool Board::down() {
  int distance = 1;
  if (isHeavy()) {
    distance += 1;
  }
  generateNextBlock(xPos, yPos - distance, r);
  if (validMove()) {
    currBlock = move(nextBlock);
    yPos -= distance;
    return true;
  } else {
    distance -= 1;
    generateNextBlock(xPos, yPos - distance, r);
    if (validMove()) {
      currBlock = move(nextBlock);
      yPos -= distance;
    }
    setBlock();
    return false;
  }
}
void Board::setBlock() {
  
}


void Board::sideways(int direction) { // direction = -1 or 1
  generateNextBlock(xPos + direction, yPos, r);
  if (validMove()) {
    currBlock = move(nextBlock);
    xPos += direction;
  }
}

void Board::rotate(int rotation) {
  if (sameRotation) return;
  generateNextBlock(xPos, yPos, rotation % 4);
  if (validMove()) {
    currBlock = move(nextBlock);
    r = rotation % 4;
  }
}

bool sameRotation(int rotation) { // for some blocks rotating it 180 degrees ends up the same, oblocks always are the same, etc.
  switch (blockType) {
    case 'O':
      return true;
    case 'S':
    case 'Z':
    case 'I':
      if (rotation % 2 == 0) {
        return true;
      }
  }
  return false;
}
*/


//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

void Board::getNextBlock() { /*nextBlock = level.generateNextBlock();*/ }

void Board::updateLevel(int direction) {
  levelNum += direction;

  //if (levelNum == 0) { level = new LevelZero; }
  //else if (levelNum == 1) { level = new LevelOne; }
  //else if (levelNum == 2) { level = new LevelTwo; }
  //else if (levelNum == 3) { level = new LevelThree; }
  //else if (levelNum == 4) { level = new LevelFour; }
}