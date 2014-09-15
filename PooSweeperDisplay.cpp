// Copyright 2014, Dominik Leclerc

#include "./PooSweeperDisplay.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include "./PooSweeperDisplayBase.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"

PooSweeperDisplay display;
PooSweeperDisplayBase* DISPLAY = &display;

// _____________________________________________________________________________
PooSweeperDisplay::PooSweeperDisplay() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
}

// _____________________________________________________________________________
void PooSweeperDisplay::show(const PooSweeperStateBase* state) const {
  for (int i = 0; i < state->numRows(); ++i) {
    for (int j = 0; j < state->numCols(); ++j) {
      // Printf position Command
      printf("\x1b[%d;%dH", i + 1, j + 1);
      switch (state->getCellInfo(i, j)) {
        case PooSweeperStateBase::UNREVEALED:
          // show unrevealed cell (inverse cell)
          printf("\x1b[0m");
          printf("\u25AF");
          break;
        case PooSweeperStateBase::REVEALED_ZERO:
          // show revealed cell (idea:inverted unrevealed?)
          // printf("\x1b[0m");
          // printf(" ");
          printf("0");
          break;
        case PooSweeperStateBase::REVEALED_POO:
          // show poo (find funny character)
          printf("*");
        case PooSweeperStateBase::MARKED:
          // show a mark (inverted X)
          printf("\x1b[7m");
          printf("X");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_ONE:
          // show a 1
          printf("\x1b[34m");
          printf("1");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_TWO:
          // show a 2 (green)
          printf("\x1b[1;32m");
          printf("2");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_THREE:
          // show a 3 (red)
          printf("\x1b[1;31m");
          printf("3");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_FOUR:
          // show a 4 (darkblue/ purple)
          printf("\x1b[34m");
          printf("4");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_FIVE:
          // show a 5 (maroon / red)
          printf("\x1b[1;35m");
          printf("5");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_SIX:
          // show a 6 (cyan/blue)
          printf("\x1b[1;36m");
          printf("6");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_SEVEN:
          // show a 7 (black / yellow)
          printf("\x1b[1;33m");
          printf("7");
          printf("\x1b[0m");
          break;
        case PooSweeperStateBase::REVEALED_EIGHT:
          // show a 8 (grey)
          printf("\x1b[1;37m");
          printf("8");
          printf("\x1b[0m");
          break;
      }
    }
  }
  // Check if the game is lost or won and display that info under gameboard.
  switch (POO->status()) {
    // Case if the Game is ONGOING
    case PooSweeperStateBase::ONGOING:
      // Print left mines and flags and such here.
      printf("\x1b[%zu;%dH", state->numRows() + 1, 0);  // lu bc. size_t numRows
      std::cout << "#Poos:" << state->numPoos();
      std::cout << "   ";
      std::cout << "#Flags:" << state->numMarked();
      std::cout << "   ";
      std::cout << "#Revealed:" << state->numRevealed();
      break;

    // Case if the Game is LOST
    case PooSweeperStateBase::LOST:
      printf("\x1b[%zu;%dH", state->numRows() + 2, 0);  // zu bc. size_t numRows
      std::cout << "You lost the game. Press any key to quit." << std::endl;
      break;

    // Case if the Game is WON.
    case PooSweeperStateBase::WON:
      printf("\x1b[%zu;%dH", state->numRows() + 2, 0);  // zu bc. size_t numRows
      std::cout << "You won the game!" << std::endl;
      break;
  }
  fflush(stdout);
}

// _____________________________________________________________________________
PooSweeperDisplay::~PooSweeperDisplay() {
  endwin();
}
