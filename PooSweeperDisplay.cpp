// Copyright 2014, Dominik Leclerc 
#include "./PooSweeperDisplay.h"
#include "./PooSweeperDisplayBase.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"
#include <ncurses.h>
#include <stdio.h>
#include <vector>

void PooSweeperDisplay::show(const PooSweeperStateBase* state) {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);

  for (int i = 0; i < _pooField.size; ++i) {
    for (int j = 0; j < _pooField[i].size; ++j) {
      printf("\x1b[%d;%dH", i, j);
      switch (_pooField[i][j]) {
        case UNREVEALED:
          printf("X");
          // show unrevealed cell (inverse cell)
          break;
        case REVEALED_POO:
          // show revealed cell (idea:inverted unrevealed?)
          break;
        case REVEALED_POO:
          // show poo (find funny character) 
        case MARKED:
          // show a mark (inverted X)
          break;
        case REVEALED_ONE:
          // show a 1 (blue)
          break;
        case REVEALED_TWO:
          // show a 2 (green)
          break;
        case REVEALED_THREE:
          // show a 3 (red)
          break;
        case REVEALED_FOUR:
          // show a 4 (darkblue/ purple)
          break;
        case REVEALED_FIVE:
          // show a 5 (maroon / red)
          break;
        case REVEALED_SIX:
          // show a 6 (cyan/blue)
          break;
        case REVEALED_SEVEN:
          // show a 7 (black)
          break;
        case REVEALED_EIGHT:
          // show a 8 (grey)
          break;
      }
    }
  }
  fflush(stdout);
}
