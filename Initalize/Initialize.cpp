// Implementation of Initialize.h
// Sets up the gameboard.

#include "./Initialize.h"
#include <iostream>

using namespace std;

// ____________________________________________________________________________
Initialize() {
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
initBoard(_dimx, _dimy, _nummine) {
  // Set up an Array of the Boardsize
  int _gameboard[_dimx][_dimy]
  // Copy zeros in the array (empty)
  for (int i; i <= _dimx; i++) {
    for (int y; y <= _dimy; y++) {
    _gameboard[i][j] = 0;
    }
  }
  // Randomly overwrite zeros with mines (1)
  for (int b; b <= _nummine; b++) {
  
  }

// ____________________________________________________________________________  
~Initialize(){

}


 
