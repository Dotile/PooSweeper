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
    for (int j = 0; j < _poofield.size; ++j) {
      // printf command goes here
    }
  }

}
