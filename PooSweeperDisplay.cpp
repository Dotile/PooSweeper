// Copyright 2014, Dominik Leclerc

#include "./PooSweeperDisplay.h"
#include <ncurses.h>
#include <stdio.h>
#include <vector>

void PooSweeperDisplay::show(const PooSweeperStateBase* state) {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);

  for (int i = 0; i < _poofield.size; ++i) {
    for (int j = 0; j < _poofield[i].size; ++j) {
      switch (_poofield[i][j]) {
        case UNREVEALED:
          printf("\x1b[%d;%dH", i, j);
          printf("X");
          fflush(stdout);
          // show unrevealed cell
          break;
        case REVEALED:
          // printf command goes here
          // show revealed cell (idea:inverted unrevealed?)
          break;
        case REVEALED_POO:
          // printf command goes here
          // show poo
        case MARKED:
          // printf command goes here
          // show a mark
          break;
        case REVEALED_ONE:
          // printf command goes here
          // show a 1
          break;
        case REVEALED_TWO:
          // printf command goes here
          // show a 2
          break;
        case REVEALED_THREE:
          // printf command goes here
          // show a 3
          break;
        case REVEALED_FOUR:
          // printf command goes here
          // show a 4
          break;
        case REVEALED_FIVE:
          // printf command goes here
          // show a 5
          break;
        case REVEALED_SIX:
          // printf command goes here
          // show a 6
          break;
        case REVEALED_SEVEN:
          // printf command goes here
          // show a 7
          break;
        case REVEALED_EIGHT:
          // printf command goes here
          // show a 8
          break;
      }
    }
  }
}
