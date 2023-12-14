#include <iostream>

using namespace std;

class Interface {
public:
  static void renderFrame(pair <int, int> startCoord, pair <int, int> size) {
    // Border top
    Windows::goTo({0, 0}, startCoord);
    cout << "╔";
    for (int i = 1; i <= size.first * 2; i++) {
      cout << "═";
    }
    cout << "╗";
    // Border left and right
    for (int i = 0; i <= size.second; i++) {
      Windows::goTo({0, i + 1}, startCoord);
      cout << "║";
      Windows::goTo({size.first * 2 + 1, i + 1}, startCoord);
      cout << "║";
    }
    // Border bottom
    Windows::goTo({0, size.second + 1}, startCoord);
    cout << "╚";
    for (int i = 1; i <= size.first * 2; i++) {
      cout << "═";
    }
    cout << "╝";
  }
  static void renderBoard(Board &board, pair <int, int> startCoord) {
    for (int y = 0; y < board.getSize().second; y++) {
      for (int x = 0; x < board.getSize().first; x ++) {
        Windows::goTo({x * 2, y}, startCoord);
        if (board.getCells().at(y).at(x) != "") {
          Windows::setColor(board.getCells().at(y).at(x), board.getCells().at(y).at(x));
          cout << "██";
        } else {
          Windows::setColor("black", "black");
          cout << "  ";
        }
      }
    }
  }
  static void renderTetromino(Tetromino &tetromino, pair <int, int> startCoord, bool clear = false) {
    for (auto coord : tetromino.getCoords()) {
      Windows::goTo({coord.first * 2, coord.second}, startCoord);
      if (clear) {
        Windows::setColor("black", "black");
        cout << "  ";
      } else {
        Windows::setColor(tetromino.getColor(), tetromino.getColor());
        cout << "██";
      }
    }
  }
};