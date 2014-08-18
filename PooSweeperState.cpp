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
  _numRevealed = 0;
  _gameStatus = ONGOING;

  // Create an vector the Size of numRows and numCols to store poos
  // Fill Gameboard vector with UNREVEALED Cells.
  _pooField.resize(_numRows);
  _board.resize(_numRows);
  for (int i = 0; i < _numRows; ++i) {
    _pooField[i].resize(_numCols);
    _board[i].resize(_numCols);
    for (int j = 0; j < _numCols; ++j) {
      _pooField[i][j] = NO_POO;
      _board[i][j] = UNREVEALED;
    }
  }

  // Fill the vector randomly with Poos.
  for (int i = 0; i <= _numPoos;) {
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
  if (move.row >= _numRows || move.row < 0) return;
  if (move.col >= _numCols || move.col < 0) return;

  switch (move.type) {
    // Case if the cell is Clicked and not Marked
    case PooSweeperMove::REVEAL:
      // check if a poo is in the clicked cell.
      if (_pooField[move.row][move.col] == POO) {
        _board[move.row][move.col] = REVEALED_POO;
        // set Gamestatus to LOST;
        _gameStatus = LOST;
        return;
      }
      // If there is no bomb look for sourrounding mines and change CellInfo.
      if (_pooField[move.row][move.col] == NO_POO) {
        int cellInfo = 0;
        // Check these neighboring cells.
        // [][][]
        // []**[]
        // [][][]
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            int row = move.row + i - 1;
            int col = move.col + i - 1;

            if (row >= _pooField.size() || row < 0) continue;
            if (col >= _pooField[row].size() || col < 0) continue;

            if (_pooField[row][col] == Poo::POO) {
              cellInfo++;
            }
          }
        }
        _board[move.row][move.col] = CellInfo(cellInfo);
        _numRevealed++;
        _gameStatus = ONGOING;
//        // Autoreveal function
//        if (cellInfo == 0) {
//          for (int i = 0; i < 2; ++i) {
//            for (int j = 0; j < 2; ++j) {
//              PooSweeperMove reveal;
//
//              reveal.row = move.row + i - 1;
//              reveal.col = move.col + j - 1;;
//              reveal.type = PooSweeperMove::REVEAL;
//
//              applyMove(reveal);
//              }
//          }
//        }
      }
      break;
    // Case if the cell is Marked and not Clicked
    case PooSweeperMove::TOGGLE_MARK:
      // if the cell is Marked then remove the mark and set another cell info.
      if (_board[move.row][move.col] == PooSweeperStateBase::MARKED) {
        _board[move.row][move.col] = UNREVEALED;
        _numMarked--;
      } else {
        _board[move.row][move.col] = MARKED;
        _numMarked++;
      }
      _gameStatus = ONGOING;

      // Check if all bombs are marked and if so, win game.
      int markedPoos;
      for (int i = 0; i < _numRows; ++i) {
        for (int j = 0; j < _numCols; ++j) {
          if (_pooField[i][j] == POO) {
            if (_board[i][j] == PooSweeperStateBase::MARKED) {
              markedPoos++;
            }
          }
        }
      }
      if (markedPoos == _numPoos) {
        _gameStatus = WON;
      }
      break;
  }
}

// _____________________________________________________________________________
PooSweeperState::GameStatus PooSweeperState::status() const {
  return _gameStatus;
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
