// Copyright 2014 Dominik Leclerc

#ifndef POOSWEEPERSTATE_H_
#define POOSWEEPERSTATE_H_

#include <gtest/gtest.h>
#include <vector>

#include "./PooSweeperMove.h"
#include "./PooSweeperStateBase.h"

class PooSweeperStateBase;
extern PooSweeperStateBase* POO;

// Class representing a state of the Minesweeper game.
class PooSweeperState : public PooSweeperStateBase {
 public:
  // create the gameboard and a field of Poos with user input from PooSweeper.h
  void initialize(size_t numRows, size_t numCols, size_t numPoos);
  FRIEND_TEST(PooSweeperStateTest, initialize);

  // return the CellInfo of a cell on the gameboard
  CellInfo getCellInfo(size_t rowIndex, size_t colIndex) const;
  FRIEND_TEST(PooSweeperStateTest, getCellInfo);

  // Apply move from play function in PooSweeper.h
  void applyMove(const PooSweeperMove& move);
  FRIEND_TEST(PooSweeperStateTest, applyMove);

  // Returns status of the game:
  GameStatus status() const;
  FRIEND_TEST(PooSweeperStateTest, status);

  // Getters.
  size_t numRows() const;
  size_t numCols() const;
  size_t numPoos() const;
  size_t numRevealed() const;
  size_t numMarked() const;

  enum Poo {
    NO_POO = 0, POO = 1
  };

 private:
  // autoreveal cells around clicked cells if there is nothing in them.
  void autoreveal(size_t rowIndex, size_t colIndex);
  FRIEND_TEST(PooSweeperStateTest, autoreveal);

  // sets the game status
  void setGameStatus();
  FRIEND_TEST(PooSweeperStateTest, setGameStatus);

  // reveals all mines once game is lost/won.
  void endreveal();
  FRIEND_TEST(PooSweeperStateTest, endreveal);

  // Membervariables
  size_t _numRows;
  size_t _numCols;
  size_t _numPoos;
  size_t _numRevealed;
  size_t _numMarked;
  int cellInfo;
  GameStatus _gameStatus;

  std::vector<std::vector<Poo>> _pooField;
  std::vector<std::vector<CellInfo>> _board;
};

#endif  // POOSWEEPERSTATE_H_
