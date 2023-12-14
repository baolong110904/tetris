#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Tetromino {
private:
  pair <float, float> origin; // Center point
  vector <pair <float, float>> coordVectors; // Vector from origin to 4 blocks 
  int direction; // 0: top, 1: right, 2: bottom, 3: left
  string color;
public:
  Tetromino(int type = 0, pair <float, float> origin = {0, 0}) : origin(origin), direction(0) {
    if (type == 0 || type == 'I') {
      coordVectors = {{-1.5, 0.5}, {-0.5, 0.5}, {0.5, 0.5}, {1.5, 0.5}};
      color = "lightaqua";
    } else if (type == 1 || type == 'O') {
      coordVectors = {{-0.5, -0.5}, {0.5, -0.5}, {-0.5, 0.5}, {0.5, 0.5}};
      color = "lightyellow";
    } else if (type == 2 || type == 'J') {
      coordVectors = {{0, -1}, {0, 0}, {0, 1}, {-1, 1}};
      color = "yellow";
    } else if (type == 3 || type == 'L') {
      coordVectors = {{0, -1}, {0, 0}, {0, 1}, {1, 1}};
      color = "green";
    } else if (type == 4 || type == 'T') {
      coordVectors = {{0, -1}, {-1, 0}, {0, 0}, {0, 1}};
      color = "purple";
    } else if (type == 5 || type == 'S') {
      coordVectors = {{0, -1}, {-1, 0}, {0, 0}, {-1, 1}};
      color = "red";
    } else if (type == 6 || type == 'Z') {
      coordVectors = {{-1, -1}, {-1, 0}, {0, 0}, {0, 1}};
      color = "blue";
    } else {
      throw invalid_argument("No type match");
    }
  }
  void setOrigin(pair <float, float> origin) {
    this->origin = origin;
  }
  vector <pair <int, int>> getCoords() {
    vector <pair <int, int>> coords;
    for (auto coordVector : coordVectors) {
      pair <float, float> renderCoord = {coordVector.first, coordVector.second};
      // Rotate vectors:
      // dir:   0    1    2    3
      //   x:  x0  -y0  -x0   y0
      //   y:  y0   x0  -y0  -x0
      if (direction % 2) swap(renderCoord.first, renderCoord.second);
      if (direction == 1 || direction == 2) renderCoord.first *= -1;
      if (direction >= 2) renderCoord.second *= -1;
      // Add origin to get actual coord
      renderCoord.first += origin.first;
      renderCoord.second += origin.second;
      // Floor to get integer
      renderCoord.first = floor(renderCoord.first);
      renderCoord.second = floor(renderCoord.second);
      coords.push_back(renderCoord);
    }
    return coords;
  }
  string getColor() {
    return color;
  }
  void rotateCCW() {
    direction = (direction - 1) % 4;
  }
  void rotateCW() {
    direction = (direction + 1) % 4;
  }
  void moveLeft() {
    origin.first --;
  }
  void moveRight() {
    origin.first ++;
  }
  void moveUp() {
    origin.second --;
  }
  void moveDown() {
    origin.second ++;
  }
};