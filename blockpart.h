#ifndef BLOCKPART_H
#define BLOCKPART_H

class BlockPart {
  private:
    int x;
    int y;
  public:
    BlockPart(int x, int y);
    int getXPos();
    int getYPos();
};
#endif