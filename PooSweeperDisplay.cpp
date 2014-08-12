// Copyright 2014, Dominik Leclerc

#include <ncurses.h>
#include <stdio.h>
#include "./PooSweeperDisplayBase.h"
#include "./PooSweeperDisplay.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"

void PooSweeperDisplay::show(const PooSweeperStateBase* state) {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);

  for (int i = 0; i < state->numRows(); ++i) {
    for (int j = 0; j < state->numCols(); ++j) {
      printf("\x1b[%d;%dH", i, j);
      switch (state->getCellInfo(i, j)) {
        case PooSweeperStateBase::UNREVEALED:
          printf("X");
          // show unrevealed cell (inverse cell)
          break;
        case PooSweeperStateBase::REVEALED_ZERO:
          // show revealed cell (idea:inverted unrevealed?)
          break;
        case PooSweeperStateBase::REVEALED_POO:
          // show poo (find funny character)
        case PooSweeperStateBase::MARKED:
          // show a mark (inverted X)
          break;
        case PooSweeperStateBase::REVEALED_ONE:
          // show a 1 (blue)
          break;
        case PooSweeperStateBase::REVEALED_TWO:
          // show a 2 (green)
          break;
        case PooSweeperStateBase::REVEALED_THREE:
          // show a 3 (red)
          break;
        case PooSweeperStateBase::REVEALED_FOUR:
          // show a 4 (darkblue/ purple)
          break;
        case PooSweeperStateBase::REVEALED_FIVE:
          // show a 5 (maroon / red)
          break;
        case PooSweeperStateBase::REVEALED_SIX:
          // show a 6 (cyan/blue)
          break;
        case PooSweeperStateBase::REVEALED_SEVEN:
          // show a 7 (black)
          break;
        case PooSweeperStateBase::REVEALED_EIGHT:
          // show a 8 (grey)
          break;
      }
    }
  }
  fflush(stdout);
}
