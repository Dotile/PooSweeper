// Copyright 2014 ; Dominik Leclerc

#include "./PooSweeper.h"

#include <stdlib.h>
#include <ncurses.h>
#include <iostream>

// _____________________________________________________________________________
PooSweeper::PooSweeper() {
  // Get boardgame simensions (in x and y) from user
  printf("\x1b[%d;%dH", 1, 0);
  std::cout << "Enter game field x-size:"<< std::endl;
  std::cin >> _numRows;
  std::cout << std::endl;
  printf("\x1b[%d;%dH", 2, 0);
  std::cout << "Enter game field y-size:"<< std::endl;
  std::cin >> _numCols;
  std::cout << std::endl;

  // Get quantity of mines from user
  printf("\x1b[%d;%dH", 3, 0);
  std::cout << "Enter number of Poos:"<< std::endl;
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
      } else if (inputMouse.bstate & BUTTON_SHIFT) {  // CTRL Left Click
        
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
    // reveal all bombs on the gameboard
    DISPLAY->show(POO);

    // if a key is pressed end the game after a win or loss.
    while (true) {
      int end = getch();
      if (end != -1) break;
    }
  }
}

// _____________________________________________________________________________
PooSweeper::~PooSweeper() {
}
