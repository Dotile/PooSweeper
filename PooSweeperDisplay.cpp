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
          // show a 1 (blue)
          printf("1");
          break;
        case PooSweeperStateBase::REVEALED_TWO:
          // show a 2 (green)
          printf("2");
          break;
        case PooSweeperStateBase::REVEALED_THREE:
          // show a 3 (red)
          printf("3");
          break;
        case PooSweeperStateBase::REVEALED_FOUR:
          // show a 4 (darkblue/ purple)
          printf("4");
          break;
        case PooSweeperStateBase::REVEALED_FIVE:
          // show a 5 (maroon / red)
          printf("5");
          break;
        case PooSweeperStateBase::REVEALED_SIX:
          // show a 6 (cyan/blue)
          printf("6");
          break;
        case PooSweeperStateBase::REVEALED_SEVEN:
          // show a 7 (black)
          printf("7");
          break;
        case PooSweeperStateBase::REVEALED_EIGHT:
          // show a 8 (grey)
          printf("8");
          break;
      }
    }
  }
  // Check if the game is lost or won and display that info under gameboard.
  switch (POO->status()) {
    // Case if the Game is ONGOING
    case PooSweeperStateBase::ONGOING:
      // Print left mines and flags and such here.
      printf("\x1b[%lu;%dH", state->numRows() + 1, 0);  // lu bc. size_t numRows
      std::cout << "#Poos:" << state->numPoos();
      std::cout << "   ";
      std::cout << "#Flags:" << state->numMarked();
      std::cout << "   ";
      std::cout << "#Revealed:" << state->numRevealed();
      break;

    // Case if the Game is LOST
    case PooSweeperStateBase::LOST:
      printf("\x1b[%lu;%dH", state->numRows() + 2, 0);  // lu bc. size_t numRows
      std::cout << "You lost the game. Press any key to quit." << std::endl;
      break;

    // Case if the Game is WON.
    case PooSweeperStateBase::WON:
      printf("\x1b[%lu;%dH", state->numRows() + 2, 0);  // lu bc. size_t numRows
      std::cout << "You won the game!" << std::endl;
      break;
  }
  fflush(stdout);
}

// _____________________________________________________________________________
PooSweeperDisplay::~PooSweeperDisplay() {
  endwin();
}
