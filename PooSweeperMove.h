// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef POOSWEEPERMOVE_H_
#define POOSWEEPERMOVE_H_

#include <stdlib.h>

// A move.
class PooSweeperMove {
 public:
  // Grab mouse events and return a move
  void getMove();

  // The position of the cell to be uncovered next.
  size_t row;
  size_t col;

  // Type of move (reveal or toggle mine mark).
  enum { REVEAL, TOGGLE_MARK } type;
  // enum { REVEAL = 0, TOGGLE_MARK = 1 } type2;
};

#endif  // POOSWEEPERMOVE_H_
