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
    // 5x5 field with no poos
    PooSweeperState pss;
    pss._numRows = 5;
    pss._numCols = 5;
    pss._numPoos = 0;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._gameStatus = PooSweeperStateBase::ONGOING;
    pss._board.clear();
    pss._pooField.clear();
    pss._board.resize(5);
    pss._pooField.resize(5);
    // Fill the vectors (no poo and unrevealed)
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        pss._board[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss._pooField[i].push_back(PooSweeperState::NO_POO);
      }
    }
    // a reveal move at position 0,0
    PooSweeperMove move;
    move.col = 0;
    move.row = 0;
    move.type = PooSweeperMove::REVEAL;
    // apply created move
    pss.applyMove(move);
    // All cells should be (auto)revealed (=0).
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        ASSERT_EQ(0, pss._board[i][j]);
      }
    }
  }
  {
    // 5x5 field just poos
    PooSweeperState pss;
    pss._numRows = 5;
    pss._numCols = 5;
    pss._numPoos = 25;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._gameStatus = PooSweeperStateBase::ONGOING;
    pss._board.clear();
    pss._pooField.clear();
    pss._board.resize(5);
    pss._pooField.resize(5);
    // fill the vectors (poo and unrevealed)
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        pss._board[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss._pooField[i].push_back(PooSweeperState::POO);
      }
    }
    // create a reveal move
    PooSweeperMove move;
    move.col = 0;
    move.row = 0;
    move.type = PooSweeperMove::REVEAL;
    // apply create move
    pss.applyMove(move);
    // All Cells should be revealed poos (= -3)
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        ASSERT_EQ(-3, pss._board[i][j]);
      }
    }
  }
}
// ____________________________________________________________________________
