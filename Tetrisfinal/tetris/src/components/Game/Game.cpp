#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

// For testing, remove later
#include "../Windows/Windows.cpp"
#include "../Tetromino/Tetromino.cpp"
#include "../Board/Board.cpp"
#include "../Interface/Interface.cpp"
#include "../Menu/Menu.cpp"
// ==========

class Game {
private:
  Board board;
  Tetromino cur, next;
  int score;
public:
  Game(pair <int, int> boardSize = {1, 1}) : board(Board(boardSize)), next(rand() % 7), score(0) {}
  // Update info
  void updateScore() {
    Windows::setColor("white", "black");
    Windows::goTo({board.getSize().first * 2 + 10, 3});
    cout << score;
  }
  void updateTetrominos() {
    Interface::renderTetromino(next, {board.getSize().first * 2 + 15, 10}, true);
    cur = next;
    cur.setOrigin({5, 1});
    next = Tetromino(rand() % 7);
    Interface::renderTetromino(cur, {1, 1});
    Interface::renderTetromino(next, {board.getSize().first * 2 + 15, 10});
  }
  // Game logic
  bool checkCollision() {
    vector <pair <int, int>> coords = cur.getCoords();
    for (auto coord : coords) {
      if (coord.second >= board.getSize().second || coord.first < 0 || coord.first >= board.getSize().first || board.getCells().at(coord.second).at(coord.first) != "") {
        return true;
      }
    }
    return false;
  }
  void action() {
    char key = getch();
    if (key == 'a') {
      // Move left
      Interface::renderTetromino(cur, {1, 1}, true); // Clear prev state
      cur.moveLeft(); // Do action
      if (checkCollision()) cur.moveRight(); // If collide, go back
      Interface::renderTetromino(cur, {1, 1}); // Render new state
    } else if (key == 'd') {
      // Move right
      Interface::renderTetromino(cur, {1, 1}, true);
      cur.moveRight();
      if (checkCollision()) cur.moveLeft();
      Interface::renderTetromino(cur, {1, 1});
    } else if (key == 'w') {
      // Rotate
      Interface::renderTetromino(cur, {1, 1}, true);
      cur.rotateCW();
      if (checkCollision()) cur.rotateCCW();
      Interface::renderTetromino(cur, {1, 1});
    } else if (key == 's') {
      // Move down
      Interface::renderTetromino(cur, {1, 1}, true);
      cur.moveDown();
      if (checkCollision()) cur.moveUp();
      Interface::renderTetromino(cur, {1, 1});
    }
  }
  void fallDown() {
    Interface::renderTetromino(cur, {1, 1}, true);
    cur.moveDown();
    if (checkCollision()) {
      // Collide when falling
      cur.moveUp();
      board.fill(cur); // Fill the board and rerender
      int fullRows = board.clearFullRows();
      score += fullRows * 100;
      Interface::renderBoard(board, {1, 1});
      updateScore();
      updateTetrominos();
    } else {
      Interface::renderTetromino(cur, {1, 1});
    }
  }
  // Game run
  void run() {
    // Set up
    system("cls");
    // Render frame
    Interface::renderFrame({0, 0}, board.getSize());
    Interface::renderFrame({board.getSize().first * 2 + 4, 1}, {10, 3});
    Windows::goTo({board.getSize().first * 2 + 6, 1});
    cout << "[ Score ]";
    Interface::renderFrame({board.getSize().first * 2 + 4, 7}, {10, 5});
    Windows::goTo({board.getSize().first * 2 + 6, 7});
    cout << "[ Next ]";
    // Render initial board
    Interface::renderBoard(board, {1, 1});
    // Render score and tetrominos
    updateScore();
    updateTetrominos();

    // Game loop
    while (true) {
      action();
      fallDown();      
    }
  }
};

// For testing, remove later
int main() {
  srand(time(0));
  Windows::setWindowSize(300, 600);
  Windows::setUnicodeOutput();
  Windows::hideCursor();

  Menu::mainScreen();
  Game game({10, 28});
  game.run();

  Windows::goTo({0, 35});
}
// ==========