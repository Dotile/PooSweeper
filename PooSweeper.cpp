// Copyright 2014 ; Dominik Leclerc

#include "./PooSweeper.h"

#include <stdlib.h>
#include <ncurses.h>
#include <iostream>

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
  while (POO->status() == PooSweeperStateBase::ONGOING) {
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

        move.col = inputMouse.x;
        move.row = inputMouse.y;
        move.type = PooSweeperMove::REVEAL;

        POO->applyMove(move);
      }
      // Left  CTRL-Click
      if (inputMouse.bstate & BUTTON_CTRL) {
        PooSweeperMove move;

        move.col = inputMouse.x;
        move.row = inputMouse.y;
        move.type = PooSweeperMove::TOGGLE_MARK;

        POO->applyMove(move);
      }
    }
  }
  if (POO->status() == PooSweeperStateBase::LOST ||
      POO->status() == PooSweeperStateBase::WON) {
    for (int i = 1; i <= _numRows + 1; ++i) {  //  +1 bc. move starts with one
      for (int j = 1; j <= _numCols + 1; ++j) {
        PooSweeperMove move;

        move.row = i;
        move.col = j;
        move.type = PooSweeperMove::REVEAL;

        POO->applyMove(move);
        DISPLAY->show(POO);
        int end = getch();
        while(true) {  // if there is a key pressed end the game
          int end = getch();
          if (end != -1) break;
        }
      }
    }
  }
}

// _____________________________________________________________________________
PooSweeper::~PooSweeper() {
}
