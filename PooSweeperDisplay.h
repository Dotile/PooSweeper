// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include "./PooSweeperStateBase.h"

#ifndef POOSWEEPERDISPLAY_H_
#define POOSWEEPERDISPLAY_H_

class PooSweeperDisplayBase;
extern PooSweeperDisplayBase* DISPLAY;

// Class for showing a state of the game on the screen.
class PooSweeperDisplay : public PooSweeperStateBase {
 public:
  void show(const PooSweeperStateBase* state);
};

#endif  // POOSWEEPERDISPLAY_H_
