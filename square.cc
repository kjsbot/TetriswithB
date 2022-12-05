#include "square.h"
#include <string>

Square::Square(int r, int c) : row{r}, col{c}, isOccupied{false}, show{false} {}

void Square::setSquare(char newChar) {
  setChar = newChar;
  isOccupied = true;
}

string Square::print() {
  return symbol;
}