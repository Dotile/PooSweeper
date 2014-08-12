// Copyright 2014 ; Dominik Leclerc

#include "./PooSweeper.h"
#include <iostream>

using namespace std;

// _____________________________________________________________________________
void PooSweeper::play() {
  int _numRows;
  int _numCols;
  int _numPoos;


  // Get boardgame simensions (in x and y) from user
  cout << "Enter Boardsize value x:";
  cin >> _numRows;
  cout << "Enter Boardsize value y:";
  cin >> _numCols;
  // Get quantity of mines from user
  cout << "Enter number of Mines:";
  cin >> _numPoos;
  
  POO->initialize(_numRows, _numCols, _numPoos);
  PooSweeperDisplay screen;
  screen.show;
  
  while (true) {
  }
}

// _____________________________________________________________________________
// move PooSweeperState::createMove() {
//   MEVENT me;  // Variable for info on mouse event.
//   mousemask(ALL_MOUSE_EVENTS, NULL);  // React to all events.
//   keypad(stdscr, TRUE);  // Single keycode, not sequence of keycodes.
//   int ch = getch();  // Get keycode
//   if (getmouse(&me) == OK) {  // Some mouse event happened.
//     // Left button clicked
//     if (me.bstate & BUTTON1_CLICKED) {
//       printf("Rechtsklick Position:" %d, %d\n, me.x, me.y);  // show position
//     } else if (me.bstate & BUTTON3_CLICKED) {  // Right button clicked
//       printf("Linksklick Position:" %d, %d\n, me.x, me.y);  // show position
//     }
// }
