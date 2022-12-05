#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "board.h"
//#include "Levels/abstractlevel.h"

using namespace std;

void displayGame(Board *b1, Board *b2) {
  // Print Header
  cout << "Level:    " << b1->levelNum; // correct num of spaces???
  cout << "          "; // correct num of spaces???
  cout << "Level:    " << b2->levelNum << endl;
  cout << "Score:    " << b1->score; // double digit score
  cout << "          "; // correct num of spaces???
  cout << "Score:    " << b2->score << endl;
  cout << "-----------";
  cout << "          "; // correct num of spaces???
  cout << "-----------" << endl;

  for (int r = 0; r <= 18; r++) {
    b1->printRow(r);
    b2->printRow(r);
    cout << endl;
  }

  cout << "-----------          -----------" << endl; // HOW MANY SPACES!!???
  cout << "Next:";
  cout << "                ";
  cout << "Next:" << endl;
  cout << b1->nextBlock->printBlock() << endl;
  //cout << "                ";
  //cout << b2->nextBlock->printBlock() << endl;
}


int main(int argc, char* argv[]) {
  string player1File = "sequence1.txt";
  string player2File = "sequence2.txt";
  bool hasGraphics = true;
  bool keystrokes = false;
  int gameLevel = 0;

  for (int i = 1; i < argc; i++) {
    string cmd = argv[i];
    if (cmd == "-text") {
		  hasGraphics = false;
		} else if (cmd == "-seed") {
      int seedNum;
      cin >> seedNum;

    } else if (cmd == "-scriptfile1") {
      string fileName1;
      cin >> fileName1;
      ifstream f(fileName1);
      if (!f.good()) {
					cerr << "Bad file" << endl;
					return 1;
			}
      player1File = fileName1;

    } else if (cmd == "-scriptfile2") {
      string fileName2;
      cin >> fileName2;
      ifstream f(fileName2);
      if (!f.good()) {
					cerr << "Bad file" << endl;
					return 1;
			}
      player2File = fileName2;

    } else if (cmd == "-startlevel") {
      int startLvl;
      cin >> startLvl;
      if (startLvl <= 4 && startLvl >= 0) {
        gameLevel = startLvl;
      } else {
        cerr << "Not valid level" << endl;
      }
    }
  }

  // Setup
  /*shared_ptr<Board> board1 = make_shared<Board>(Board(1, 0));
  shared_ptr<Board> board2 = make_shared<Board>(Board(1, 0));
  shared_ptr<Board> currentPlayer = board1;*/

  Board *board1 = new Board(1, gameLevel);
  Board *board2 = new Board(2, gameLevel);

  board1->setLevel(player1File);
  board2->setLevel(player2File);

  Board *currentPlayer = board1;

  int numWins1 = 0;
  int numWins2 = 0;

  /*std::map<string, string> commands = {
        { "ri" , "right" },
        { "dr" , "drop" }, { "dro" , "right" }
  };*/

  // Game loop
  while (true) {
    bool restart = false;

    // Generate blocks based on level
    board1->currBlock = board1->getNextBlock();
    board2->currBlock = board2->getNextBlock();
    board1->nextBlock = board1->getNextBlock();
    board2->nextBlock = board2->getNextBlock();

    //board1->getNextBlock();
    //board2->getNextBlock();

    // User input loop
    while (true) {
      string cmd;
      cin >> cmd;
      
      int multiplier = 1;

      displayGame(board1, board2);

      if (cmd == "restart") {
        restart = true;
        //board1->reset();
        //board2->reset();
        break;
      }
      else if (cmd == "left") {
        //currentPlayer->sideways(-1);
      }
      else if (cmd == "right") {
        //currentPlayer->sideways(1);
      }
      else if (cmd == "down") {
        //currentPlayer->down();
      }
      else if (cmd == "clockwise") {
        //currentPlayer->rotate(1);
      }
      else if (cmd == "counterclockwise") {
        //currentPlayer->rotate(3);
      }
      else if (cmd == "drop") {
        //currentPlayer->drop();
      }
      else if (cmd == "levelup" && currentPlayer->levelNum != 4) {
        //currentPlayer.updateLevel(currentPlayer->levelNum++);
      }
      else if (cmd == "leveldown" && currentPlayer->levelNum != 0) {
        //currentPlayer.updateLevel(currentPlayer->levelNum--);
      }
    }

    if (restart) { continue; }

    if (currentPlayer->isLost()) {
      cout << "Game over!" << endl;
      if (currentPlayer->getPlayer() == 1) {
        cout << "Player 2 wins!" << endl;
        ++numWins2;
      } else {
        cout << "Player 1 wins!" << endl;
        ++numWins1;
      }
      //return? Reset board? Make new boards?
    }

    bool isWin = false;
    if (currentPlayer->getPlayer() == 1) {
      //isWin = checkWin(board1);
    } else {
      //isWin = checkWin(board2);
    }

    if (isWin) {
      cout << "Game over!" << endl;
      cout << (currentPlayer->getPlayer() == 1 ? "Player 1 wins" : "Player 2 wins!") << endl;
      return 0;
    }
    
    bool needEffect = false;

    if (needEffect) {
      string effect;
      cout << "Choose an effect: Blind - heavy - force" << endl;
      cin >> effect;

      if (effect == "force") {
        if (currentPlayer->getPlayer() == 1) {
          // apply on board2
        } else {
          // apply on board1
        }
      } else if (effect == "blind") {
        if (currentPlayer->getPlayer() == 1) {
          // apply on board2
        } else {
          // apply on board1
        }
      } else if (effect == "heavy") {
        if (currentPlayer->getPlayer() == 1) {
          // apply on board2
        } else {
          // apply on board1
        }
      }
    }

    if (currentPlayer->getPlayer() == 1) {
      currentPlayer = board2;
    } else {
      currentPlayer = board1;
    }
  }

  currentPlayer = nullptr;
}