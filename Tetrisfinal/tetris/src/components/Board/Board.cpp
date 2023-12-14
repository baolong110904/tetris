#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
  vector <vector <string>> cells; // Store color string
public:
  Board(pair <int, int> size = {1, 1}) {
    for (int y = 0; y < size.second; y++) {
      vector <string> row;
      for (int x = 0; x < size.first; x ++) {
        row.push_back("");
      };
      cells.push_back(row);
    }
  }
  vector <vector <string>> getCells() {
    return cells;
  }
  pair <int, int> getSize() {
    return {cells.at(0).size(), cells.size()};
  }
  void fill(Tetromino &tetromino) {
    for (auto coord : tetromino.getCoords()) {
      cells.at(coord.second).at(coord.first) = tetromino.getColor();
    }
  }
  int clearFullRows() {
    vector <int> fullRows;
    // Find rows with full of blocks
    for (int i = 0; i< cells.size(); i ++) {
      bool check = true;
      for (auto cell : cells.at(i)) {
        if (cell == "") {
          check = false;
          break;
        };
      }
      if (check) {
        // Push the index to list
        fullRows.push_back(i);
      }
    }
    // Clear rows
    for (auto i : fullRows) {
      cells.erase(cells.begin() + i);
      cells.insert(cells.begin(), vector <string> (cells.at(0).size(), ""));
    }
    return fullRows.size();
  }
};