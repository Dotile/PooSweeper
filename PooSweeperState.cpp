// Copyright 2014 Dominik Leclerc

#include <vector>
#include "./PooSweeperState.h"

// _____________________________________________________________________________
void PooSweeperState::initialize(size_t numRows, size_t numCols, size_t numPoos)
{
  // Create an vector the Size of numRows and numCols.
  _pooField.resize(numRows);
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      _pooField[i].push_back(NO_POO);
    }
  }

  // Fill the vector randomly with Poos.
  for (int k; k <= numPoos;) {
    int _minex = random() % numRows;
    int _miney = random() % numCols;
    // If there is space put in the poo
    if (_pooField[_minex][_miney] == NO_POO) {
      _pooField[_minex][_miney] = POO;
      k++;
    }
  }
}


// _____________________________________________________________________________
CellInfo PooSweeperState::getCellInfo(size_t rowIndex, size_t colIndex) {
 // Look for mines in sorrounding fields using if Statements
 int CellInfo = 0;
 // Center
 if(_pooField[rowIndex][colIndex] == POO) {
   CellInfo = REVEALED_POO;
 }
 // Upper left
 if(_pooField[rowIndex - 1][colIndex - 1 == POO) {
   CellInfo++;
 }
 // Upper middle
 if(_pooField[rowIndex - 1][colIndex] == POO) {
   CellInfo++;
 }
 // Upper right
 if(_pooField[rowIndex - 1][colIndex + 1] == POO) {
   CellInfo++;
 }
 // Center left
 if(_pooField[rowIndex][colIndex - 1] == POO) {
   CellInfo++;
 }
 // Center right
 if(_pooField[rowIndex][colIndex + 1] == POO) {
   CellInfo++;
 }
 // Lower left
 if(_pooField[rowIndex + 1][colIndex - 1] == POO) {
   CellInfo++;
 }
 // Lower middle 
 if(_pooField[rowIndex + 1][colIndex] == POO) {
   CellInfo++;
 }
 // Lower right 
 if(_pooField[rowIndex + 1][colIndex] == POO) {
   CellInfo++;
 }
 return CellInfo;
}
