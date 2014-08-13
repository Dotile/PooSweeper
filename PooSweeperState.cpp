// Copyright 2014 Dominik Leclerc

#include "./PooSweeperState.h"

#include <ncurses.h>
#include <vector>

PooSweeperState poo;
PooSweeperStateBase* POO = &poo;


// _____________________________________________________________________________
void PooSweeperState::initialize
(size_t numRows, size_t numCols, size_t numPoos) {
  // Membervariables
  _numRows = numRows;
  _numCols = numCols;
  _numPoos = numPoos;
  _numMarked = 0;

  // Create an vector the Size of numRows and numCols to store poos
  // Fill Gameboard vector with UNREVEALED Cells.
  _pooField.resize(_numRows);
  _board.resize(_numRows);
  for (int i = 0; i < _numRows; ++i) {
    for (int j = 0; j < _numCols; ++j) {
      _pooField[i].push_back(NO_POO);
      _board[i].push_back(UNREVEALED);
    }
  }

  // Fill the vector randomly with Poos.
  for (int i; i <= _numPoos;) {
    int _minex = random() % numRows;
    int _miney = random() % numCols;
    // If there is space put in the poo
    if (_pooField[_minex][_miney] == NO_POO) {
      _pooField[_minex][_miney] = POO;
      i++;
    }
  }
}

// _____________________________________________________________________________
PooSweeperStateBase::CellInfo PooSweeperState::getCellInfo
(size_t rowIndex, size_t colIndex) const {
  return _board[rowIndex][colIndex];
}

// _____________________________________________________________________________
void PooSweeperState::applyMove(const PooSweeperMove& move) {
  switch (move.type) {
    // Case if the cell is Clicked and not Marked
    case PooSweeperMove::REVEAL:
      // check if a poo is in the clicked cell.
      if (_pooField[move.row][move.col] == POO) {
        _board[move.row][move.col] = REVEALED_POO;
        // set game status to lost GameStatus = LOST;
        return;
      }
      // If there is no bomb look for sourrounding mines and change CellInfo.
      if (_pooField[move.row][move.col] == NO_POO) {
        size_t cellInfo = 0;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            if (_pooField[move.row + i - 1][move.col + i -1] == POO) {
              cellInfo++;
            }
          }
        }
        _board[move.row][move.col] = CellInfo(cellInfo);
      }
      break;
    // Case if the cell is Marked and not Clicked
    case PooSweeperMove::TOGGLE_MARK:
      // if the cell is Marked then remove the mark and set another cell info.
      if (_board[move.row][move.col] == PooSweeperStateBase::MARKED) {
        _board[move.row][move.col] = UNREVEALED;
        _numMarked--;
      } else if (_board[move.row][move.col] == PooSweeperStateBase::UNREVEALED){
        _board[move.row][move.col] = MARKED;
        _numMarked++;
      }
      break;
    // TODO(Dotile): Case if both Keys are pressed.
  }
}

// _____________________________________________________________________________
PooSweeperState::GameStatus PooSweeperState::status() const {
}

// _____________________________________________________________________________
size_t PooSweeperState::numRows() const {
  return _numRows;
}

// _____________________________________________________________________________
size_t PooSweeperState::numCols() const {
  return _numCols;
}

// _____________________________________________________________________________
size_t PooSweeperState::numPoos() const {
  return _numPoos;
}

// _____________________________________________________________________________
size_t PooSweeperState::numRevealed() const {
  return _numRevealed;
}

// _____________________________________________________________________________
size_t PooSweeperState::numMarked() const {
  return _numMarked;
}
