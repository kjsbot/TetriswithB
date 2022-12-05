#include "board.h"
#include "levelzero.h"
//#include "levelone.h"
//#include "leveltwo.h"

using namespace std;

Board::Board(int player, int level) : rows{18}, cols{11}, player{player}, levelNum{level}, newGame{true} {
  for (int i = 0; i <= rows; i++) {
    vector<Square> row;
    for (int j = 0; j <= cols; j++) {
      row.push_back(Square(i, j));
    }
    board.push_back(row);
  }
}

void Board::setLevel(string fileName) {
  delete level;
  if (levelNum == 0) {
    level = new LevelZero{-1, fileName};
  } /*else if (levelNum == 1) {

  } else if (levelNum == 2) {

  } else if (levelNum == 3) {

  } else {

  }*/
}

Board::~Board() {
  delete currBlock;
  delete nextBlock;
  delete level;
}

int Board::getPlayer() {
  return player;
}

bool Board::isLost() {
  return lost;
}

void Board::printRow(int row) {
  for (int c = 0; c <= cols; c++) {
    if (board[row][c].show && board[row][c].isOccupied) { board[row][c].print(); }
      else { cout << " "; }
  }
}

bool Board::isRowFilled(int row) {
  for (int i = 0; i <= cols; i++) {
    if (!board[row][i].isOccupied) return false;
  }

  return true;
}

int Board::deleteRows() {
  int rowsDeleted = 0;

  for (int i = 0; i < 15; i++) {
    if (blockspartsPerRow[i] == 11) {
      deleteRow(i);
      rowsDeleted++;
    }
  }
  
  return rowsDeleted;
}

void Board::deleteRow(int row) {
  /*for (int i = 0; i <= cols; i++) {
    Block *toCoorRemoveFrom = board[row][i]->Square->Block;
    vector<BlockPart> newCoordinates;

    for (auto coor : toCoorRemoveFrom->parts) {
      if (coor != {row, i}) { newCoordinates.push_back({row, i}); } // {row, i} is used to represent a coor
    }

    toCoorRemoveFrom->parts = newCoordinates;
  }
  
  for (auto block : blocks) {
    drop(block);
  }*/
}

bool Board::isHeavy() {
  if (heavy) { return true; }
  return false;
}

bool Board::validMove() {
  for (int i = 0; i < blockSize; ++i) {
    int x = 0;//nextBlock->xPos(i);
    int y = 0;//nextBlock->yPos(i);
    if (board[y][x].isOccupied) {
      return false;
    }
  }
  return true;
}

/*

void Board::down() {
  if (heavy) {
    downHeavy();
  } else {
    downNorm();
  }
}

void Board::downHeavy() {
  generateNextBlock(xPos, yPos - 2, r);
  if (validMove()) {
    currBlock = move(nextBlock);
    yPos -= 2;
  } else {
    drop();
  }
}

bool Board::downNorm() {
  generateNextBlock(xPos, yPos - 1, r);
  if (validMove()) {
    currBlock = move(nextBlock);
    yPos -= 1;
    return true;
  } else {
    return false;
  }
}*/
/*
void Board::drop() {
  bool canDrop = true;
  while (canDrop) {
    canDrop = downNorm();
  }
  setBlock();
  makeNewBlock();
}

void Board::setBlock() {
  for (int i = 0; i < blockSize; ++i) {
    int x = nextBlock->xPos(i);
    int y = nextBlock->yPos(i);
    board[y][x].setBlock(blockType);
    if (y < 3) {
      isLost == true;
    }
    blocksPartsPerRow[y] += 1;
    if (blockPartsPerRow[y] == 11) {
      deleteRow(y);
    }
  }
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
  rotPos = (r + rotation) % 4;
  generateNextBlock(xPos, yPos, rotPos);
  if (validMove()) {
    currBlock = move(nextBlock);
    r = rotPos;
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
Block* Board::getNextBlock() { return level->generateNextBlock(); }


///////////////////////////////////////////////////



int Board::updateRow(int row) {
  blocksPartsPerRow[y] += 1;
  if (blockPartsPerRow[y] == 11) {
    deleteRow(y);
    return 1;
  }
  return 0;
}

// added recently

void Board::addTurns() {
  ++turns;
}

int Board::getTurns() {
  return turns;
}

int Board::getx() {
  return x;
}

int Board::gety() {
  return y;
}

int Board::getr() {
  return r;
}

void Board::makeNewBlock() {
  if (newGame) {
    nextBlockType = level->generateNextBlock();
    newGame = false;
  }
  blockType = nextBlockType;
  currBlockMove = generateNextBlock(0, 14, 0);
  if (validMove()) {
    updateCurrBlock(0, 14, 0);
  } else {
    playerLost();
  }
  nextBlockType = level->generateNextBlock();
}

void Board::playerLost() {
  lost = true;
  lost;
}

void Board::updateCurrBlock(int xNew, int yNew, int rNew) {
  currBlock = move(nextBlock);
  xPos = xNew;
  yPos += yNew;
  r = rNew;
}

void Board::setBlockType(char type, char replacedBlock) {
  if (replacedBlock = 'C') {
    blockType = type;
  } else if (replacedBlock = 'N') {
    nextBlockType = type;
  }
}

Block* Board::generateNextBlock(char type, int x, int y, int r) {
  Block* newBlock;
  switch (blockType) {
    /*case 'I': 
      makeBlock = make_unique<Block>(IBlock(x, y, r));
      break;
    case 'J': 
      makeBlock = make_unique<Block>(JBlock(x, y, r));
      break;
    case 'L': 
      makeBlock = make_unique<Block>(LBlock(x, y, r));
      break;
    case 'O': 
      makeBlock = make_unique<Block>(OBlock(x, y, r));
      break;
    case 'S': 
      makeBlock = make_unique<Block>(SBlock(x, y, r));
      break;
    case 'Z': 
      makeBlock = make_unique<Block>(ZBlock(x, y, r));
      break;*/
    case 'T': 
      newBlock = new TBlock(x, y, r);
      break;
    }
  return newBlock;
}