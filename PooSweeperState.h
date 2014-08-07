// Copyright 2014, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef PROJEKT_POOSWEEPERSTATE_H_
#define PROJEKT_POOSWEEPERSTATE_H_

#include <vector>
#include "./PooSweeperMove.h"

class PooSweeperStateBase;
extern PooSweeperStateBase* POO;

// Class representing a state of the Minesweeper game.
class PooSweeperState : public PooSweeperStateBase {
 public:
  // Destructor.
  ~PooSweeperState() { }

  // Get cell information (for playing):
  enum CellInfo {
    REVEALED_POO = -3, MARKED = -2, UNREVEALED = -1,
    REVEALED_ZERO = 0, REVEALED_ONE = 1, REVEALED_TWO =2,
    REVEALED_THREE = 3, REVEALED_FOUR = 4, REVEALED_FIVE = 5,
    REVEALED_SIX = 6, REVEALED_SEVEN = 7, REVEALED_EIGHT = 8
  };
  CellInfo getCellInfo(size_t rowIndex, size_t colIndex) const;

  // Initialize (randomly).
  void initialize(size_t numRows, size_t numCols, size_t numPoos);

  // Apply move.
  void applyMove(const PooSweeperMove& move);

  // Status of the game:
  enum GameStatus { ONGOING, LOST, WON };
  GameStatus status() const;

  // Getters.
  size_t numRows() const;
  size_t numCols() const;
  size_t numPoos() const;
  size_t numRevealed() const;
  size_t numMarked() const;

 private:
  int _minex;
  int _miney;
};

#endif  // PROJEKT_POOSWEEPERSTATE_H_
