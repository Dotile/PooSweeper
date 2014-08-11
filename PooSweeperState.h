// Copyright 2014 Dominik Leclerc

#ifndef POOSWEEPERSTATE_H_
#define POOSWEEPERSTATE_H_

#include <vector>
#include "./PooSweeperMove.h"
#include "./PooSweeperStateBase.h"

class PooSweeperStateBase;
extern PooSweeperStateBase* POO;

// Class representing a state of the Minesweeper game.
class PooSweeperState : public PooSweeperStateBase {
 public:
  CellInfo getCellInfo(size_t rowIndex, size_t colIndex) const;

  // Initialize (randomly).
  void initialize(size_t numRows, size_t numCols, size_t numPoos);

  // Apply move.
  void applyMove(const PooSweeperMove& move);

  // Status of the game:
  GameStatus status() const;

  // Getters.
  size_t numRows() const;
  size_t numCols() const;
  size_t numPoos() const;
  size_t numRevealed() const;
  size_t numMarked() const;

  enum poo {
    NO_POO = 0, POO = 1
  };

 private:
  size_t _numRows;
  size_t _numCols;
  size_t _numPoos;
  size_t _numRevealed;
  size_t _numMarked;


  std::vector<std::vector<poo>> _pooField;
  std::vector<std::vector<CellInfo>> _board;
};

#endif  // POOSWEEPERSTATE_H_
