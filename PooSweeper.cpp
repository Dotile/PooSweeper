// Copyright 2014 ; Dominik Leclerc

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#include "./PooSweeper.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperDisplayBase.h"

// _____________________________________________________________________________
PooSweeper::PooSweeper() {
  // Get boardgame simensions (in x and y) from user
  std::cout << "Enter game field x-size:";
  std::cin >> _numRows;
  std::cout << "Enter game field y-size:";
  std::cin >> _numCols;
  // Get quantity of mines from user
  std::cout << "Enter number of shits:";
  std::cin >> _numPoos;
}

// _____________________________________________________________________________
void PooSweeper::play() {
  POO->initialize(_numRows, _numCols, _numPoos);

  while (true) {
    DISPLAY->show(POO);

    // Mouse Events
    MEVENT me;  // Variable for info on mouse event.
    mousemask(ALL_MOUSE_EVENTS, NULL);  // React to all events.
    keypad(stdscr, TRUE);  //Single keycode, not sequence of keycodes.
    int ch = getch();  // Get keycode.
    if (getmouse(&me) == OK) {  // Some mouse event happend.
      // button clicked
      if (me.bstate & BUTTON1_CLICKED) {
        printf("Rechtsklick Position:" %d, %d\n, me.x, me.y);  // position
      }
    }
    // Mouse Events
    POO->applyMove(me.x, me.y);
  }
}

// _____________________________________________________________________________
PooSweeper::~PooSweeper() {
}
