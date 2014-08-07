// Copyright 2014 Dominik Leclerc

#include "./PooSweeperState.h"

// _____________________________________________________________________________
void PooSweeperState::initialize(size_t numRows, size_t numCols, size_t numPoos) {
  // Create an arraz the Size of numRows and numCols.
  new _poofield[numRows][numCols];
  // Fill the array with zeros (no Poos).
  for (int i; i <= numRows; i++) {
    for (int j; j <= numCols; j++) {
      _poofield[i][j] = 0;
    }
  }
  // Fill the array randomly with Poos.
  for (int k; k <= numPoos; k++) {
    int _minex = random () % numRows;
    int _miney = random () % numCols;
    // If there is space put in the mine (1)
    if (_poofield[_minex][_miney] == 0) {
      _poofield[_minex][_miney] = 1;
    }
    k++;
  }
}

// ____________________________________________________________________________
PooSweeperState::~PooSweeperStateBase() { 
  delete _poofield;
}

