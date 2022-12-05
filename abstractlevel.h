#ifndef ABSLEVEL_H
#define ABSLEVEL_H
#include <vector>
#include "board.h"
#include "block.h"
//#include "../Blocks/iblock.h"
//#include "../Blocks/jblock.h"
//#include "../Blocks/lblock.h"
//#include "../Blocks/oblock.h"
//#include "../Blocks/sblock.h"
//#include "../Blocks/zblock.h"
#include "tblock.h"
//#include "../Blocks/cblock.h"

using namespace std;

class AbstractLevel {
  public:
    ~AbstractLevel();
    virtual Block* generateNextBlock() = 0;
};

#endif