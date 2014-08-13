// Copyright 2014 ; Dominik Leclerc

#include "./PooSweeper.h"

#include <stdlib.h>
#include <ncurses.h>
#include <iostream>

#include "./PooSweeperMove.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperDisplayBase.h"

// _____________________________________________________________________________
PooSweeper::PooSweeper() {
  // Get boardgame simensions (in x and y) from user
  std::cout << "Enter game field x-size:"<< std::endl;
  std::cin >> _numRows;
  std::cout << std::endl;
  std::cout << "Enter game field y-size:"<< std::endl;
  std::cin >> _numCols;
  std::cout << std::endl;
  // Get quantity of mines from user
  std::cout << "Enter number of shits:"<< std::endl;
  std::cin >> _numPoos;
  std::cout << std::endl;
}

// _____________________________________________________________________________
void PooSweeper::play() {
  POO->initialize(_numRows, _numCols, _numPoos);
  while (true) {
    DISPLAY->show(POO);
    // Mouse Events
    MEVENT inputMouse;  // Variable for info on mouse event.
    mousemask(ALL_MOUSE_EVENTS, NULL);  // React to all events.
    keypad(stdscr, TRUE);  // Single keycode, not sequence of keycodes.
    int ch = getch();  // Get keycode.
    if (getmouse(&inputMouse) == OK) {  // Some mouse event happend.
      // Left Click
      if (inputMouse.bstate & BUTTON1_CLICKED) {
        PooSweeperMove move;

        move.col = inputMouse.x + 1;
        move.row = inputMouse.y + 1;
        move.type = PooSweeperMove::REVEAL;

        POO->applyMove(move);
      }
      // Left  CTRL-Click
      if (inputMouse.bstate & BUTTON_CTRL) {
        PooSweeperMove move;

        move.col = inputMouse.x + 1;
        move.row = inputMouse.y + 1;
        move.type = PooSweeperMove::TOGGLE_MARK;

        POO->applyMove(move);
      }
    }
  }
}

// _____________________________________________________________________________
PooSweeper::~PooSweeper() {
}
