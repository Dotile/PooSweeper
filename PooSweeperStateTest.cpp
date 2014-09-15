// Copyright 2014
// Dominik Leclerc

#include <gtest/gtest.h>
#include "./PooSweeperState.h"

// _________________________________________________________________________
TEST(PooSweeperStateTest, initialize) {
  PooSweeperState pssa;
  pssa.initialize(10, 10, 10);
  // Is the quantity of bombs correct?
  size_t count = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (pssa._pooField[i][j] == PooSweeperState::POO) {
        ++count;
      }
    }
  }
  ASSERT_EQ(10, count);
  ASSERT_EQ(10, pssa.numRows());
  ASSERT_EQ(10, pssa.numCols());
}


// ________________________________________________________________________
TEST(PooSweeperStateTest, applyMove) {
  {
    // No poos
    PooSweeperState pss;
    pss._numRows = 5;
    pss._numCols = 5;
    pss._numPoos = 0;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._status = PooSweeperStateBase::ONGOING;
    pss.CellInfoStorage.clear();
    pss.CellInfoPoo.clear();
    pss.CellInfoStorage.resize(5);
    pss.CellInfoPoo.resize(5);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        pss.CellInfoStorage[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss.CellInfoPoo[i].push_back(PooSweeperState::NO_POO);
      }
    }
    PooSweeperMove move;
    move.col = 0;
    move.row = 0;
    move.type = PooSweeperMove::REVEAL;
    pss.applyMove(move);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        ASSERT_EQ(0, pss.CellInfoStorage[i][j]);
      }
    }
  }
  {
    // Only poos
    PooSweeperState pss;
    pss._numRows = 5;
    pss._numCols = 5;
    pss._numPoos = 25;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._status = PooSweeperStateBase::ONGOING;
    pss.CellInfoStorage.clear();
    pss.CellInfoPoo.clear();
    pss.CellInfoStorage.resize(5);
    pss.CellInfoPoo.resize(5);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        pss.CellInfoStorage[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss.CellInfoPoo[i].push_back(PooSweeperState::POO);
      }
    }
    PooSweeperMove move;
    move.col = 0;
    move.row = 0;
    move.type = PooSweeperMove::REVEAL;
    pss.applyMove(move);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j) {
        ASSERT_EQ(-3, pss.CellInfoStorage[i][j]);
      }
    }
  }
}

