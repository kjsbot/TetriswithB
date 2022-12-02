#include <iostream>
#include "board.h"
//#include "Levels/abstractlevel.h"
//#include "Levels/levelzero.h"
//#include "Levels/levelone.h"
//#include "Levels/leveltwo.h"

using namespace std;

int main() {
  cout << "test";//
//  unique_ptr<Board> board1 = make_unique<Board>(Board(1, 2));
//  Board *board1 = new Board(1, 1);
  // Command-line args
  string input;

  // Setup
  //Board *Board1 = new Board{1, 0};
  //Board *Board2 = new Board{2, 0};
  //Board *currentPlayer = Board1;
/*
  // Game loop
  while (true) {
    bool restart = false;

    // User input loop
    while (true) {
      
      string cmd;
      int multiplier = 1;
      
      if (cmd == "restart") {
        restart = true;
        Board1->reset();
        Board2->reset();
        break;
      }
      else if (cmd == "left") {
        
        for (int i = 0; i < multiplier; i++) {
          if valid() {
            block->goLeft();
          }
        }
        
      }
      else if (cmd == "right") {}
      else if (cmd == "down") {}
      else if (cmd == "clockwise") {}
      else if (cmd == "counterclockwise") {}
      else if (cmd == "drop") {}
      else if (cmd == "levelup" && currentPlayer.level != 4) {
        currentPlayer.updateLevel(1);
      }
      else if (cmd == "leveldown" && currentPlayer.level != 0) {
        currentPlayer.updateLevel(-1);
      }
      else if (cmd == "norandom file") {}
      else if (cmd == "random") {}
      else if (cmd == "sequence file") {}
    }

    if (restart) { continue; }

    bool isWin = false;
    if (currentPlayer.player == 1) {
      isWin = checkWin(Board1);
    } else {
      isWin = checkWin(Board2);
    }

    if (isWin) {
      cout << "Game over!" << endl;
      cout << (currentPlayer.player == 1 ? "Player 1 wins" : "Player 2 wins!") << endl;
      return 0;
    }

    currentPlayer.player = currentPlayer.player == 1 ? Board2 : Board1;
  }*/
}