// Implementation of Initialize.h
// Sets up the gameboard.

#include "./Initialize.h"
#include <iostream>

using namespace std;

// ____________________________________________________________________________
Initialize::Initialize() {
  int _dimx;
  int _dimy;
  int _nummine;
  // Get boardgame simensions (in x and y) from user
  cout << "Enter Boardsize value x:";
  cin >> _dimx;

  cout << "Enter Boardsize value y:";
  cin >> _dimy;

  // Get quantity of mines from user
  cout << "Enter number of Mines:";
  cin >> _nummine;
}

// ____________________________________________________________________________
// Creates the array as an gameboard
void Initialize::initBoard(int , int, int) {
  // Set up an Array of the Boardsize
  int _gameboard[_dimx][_dimy];
  // Copy zeros in the array (empty)
  for (int i; i <= _dimx; i++) {
    for (int j; j <= _dimy; j++) {
      _gameboard[i][j] = 0;
    }
  }
  // Randomly overwrite zeros with mines (1)
  for (int k = 0; k < _nummine;) {
    _minex = random() % _dimx;
    _miney = random() % _dimy;
    // If there is space put in a mine
    if (_gameboard[_minex][_miney] == 0) {
      _gameboard[_minex][_miney] = 1;
      k++;
    }
  }
}
// _____________________________________________________________________________
Initialize::~Initialize() {
}

