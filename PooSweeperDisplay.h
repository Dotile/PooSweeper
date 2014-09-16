// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#include "./PooSweeperDisplayBase.h"

#ifndef PROJEKT_POOSWEEPERDISPLAY_H_
#define PROJEKT_POOSWEEPERDISPLAY_H_

class PooSweeperDisplayBase;
extern PooSweeperDisplayBase* DISPLAY;

// Class for showing a state of the game on the screen.
class PooSweeperDisplay : public PooSweeperDisplayBase {
 public:
  // Constructor
  PooSweeperDisplay();

  // Show methode
  void show(const PooSweeperStateBase* state) const;

  // Destructor
  ~PooSweeperDisplay();
};

#endif  // PROJEKT_POOSWEEPERDISPLAY_H_
