// Copyright 2014 Dominik Leclerc

#include <vector>
#include <ncurses.h>
#include "./PooSweeperState.h"

// _____________________________________________________________________________
void PooSweeperState::initialize(size_t numRows, size_t numCols, size_t numPoos)
{
  // Create an vector the Size of numRows and numCols to store poos
  // Fill Gameboard vector with UNREVEALED Cells.
  _pooField.resize(numRows);
  _board.resize(numRows);
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      _pooField[i].push_back(NO_POO);
      _board[i].push_back(UNREVEALED);
    }
  }

  // Fill the vector randomly with Poos.
  for (int i; i <= numPoos;) {
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
CellInfo PooSweeperState::getCellInfo(size_t rowIndex, size_t colIndex) {
  CellInfo CellInfo;
  CellInfo = _board[rowIndex][colIndex];
  return CellInfo;
}

// _____________________________________________________________________________
void PooSweeperState::applyMove(const PooSweeperMove& move) {
  // check if a poo is in the clicked cell.
  if(_pooField[move.row][move.col] == POO) {
    _board[move.row][move.col] = REVEALED_POO;
    GameStatus = LOST;
    return;
  }
  // If there is no bomb look for sourrounding mines and change CellInfo.
  if(_pooField[move.row][move.col] == NO_POO) {
  CellInfo = O;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (_pooField[move.row + i - 1][move.col + i -1] == POO) {
          CellInfo++;
        }
      }
    }
  }
}

// _____________________________________________________________________________
move PooSweeperState::createMove() {
  MEVENT me;  // Variable for info on mouse event.
  mousemask(ALL_MOUSE_EVENTS, NULL);  // React to all events.
  keypad(stdscr, TRUE);  // Single keycode, not sequence of keycodes.
  int ch = getch();  // Get keycode
  if (getmouse(&me) == OK) {  // Some mouse event happened.
    // Left button clicked
    if (me.bstate & BUTTON1_CLICKED) {
      printf("Rechtsklick Position:" %d, %d\n, me.x, me.y);  // show position
    } else if (me.bstate & BUTTON3_CLICKED) {  // Right button clicked
      printf("Linksklick Position:" %d, %d\n, me.x, me.y);  // show position
    }
}
