// Copyright 2014 ; Dominik Leclerc

#include "./PooSweeperState.h"
#include "./PooSweeperStateBase.h"
#include "./PooSweeperDisplay.h"
#include "./PooSweeperDisplayBase.h"
#include "./PooSweeperMove.h"

#ifndef POOSWEEPER_H_
#define POOSWEEPER_H_


class PooSweeper {
 public:
  // Constructor, asks for user input at the start of the game.
  PooSweeper();

  // Manage the game and catch mouseevents for moves.
  void play();

  // Destructor
  ~PooSweeper();

 private:
  int _numRows;
  int _numCols;
  int _numPoos;
};

#endif  // POOSWEEPER_H_
