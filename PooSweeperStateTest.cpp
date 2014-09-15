// Copyright 2014
// Dominik Leclerc

#include <gtest/gtest.h>
#include "./PooSweeperState.h"

// _________________________________________________________________________
TEST(PooSweeperStateTest, initialize) {
  PooSweeperState pss;
  pss.initialize(10, 10, 10);
  // Is the quantity of bombs correct?
  size_t count = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (pss._pooField[i][j] == PooSweeperState::POO) {
        ++count;
      }
    }
  }
  ASSERT_EQ(10, count);
  ASSERT_EQ(10, pss.numRows());
  ASSERT_EQ(10, pss.numCols());
}

// ________________________________________________________________________
TEST(PooSweeperStateTest, applyMove) {
  // Reveal
  {
    // 10x10 field with no poos
    PooSweeperState pss;
    pss._numRows = 10;
    pss._numCols = 10;
    pss._numPoos = 10;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._gameStatus = PooSweeperStateBase::ONGOING;
    pss._board.clear();
    pss._pooField.clear();
    pss._board.resize(10);
    pss._pooField.resize(10);
    // Fill the vectors
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        pss._board[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss._pooField[i].push_back(PooSweeperState::NO_POO);
      }
    }
    // a reveal move at position 0,0
    PooSweeperMove move;
    move.col = 2;
    move.row = 2;
    move.type = PooSweeperMove::REVEAL;
    // apply created move
    pss.applyMove(move);
    // The cell should be revealed (!= -1).
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        ASSERT_NE(-1 , pss._board[1][1]);
      }
    }
  }
  // Autoreveal
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
  // Toogle Mark
  {
    // 1x1 field with no poos
    PooSweeperState pss;
    pss._numRows = 1;
    pss._numCols = 1;
    pss._numPoos = 0;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._gameStatus = PooSweeperStateBase::ONGOING;
    pss._board.clear();
    pss._pooField.clear();
    pss._board.resize(1);
    pss._pooField.resize(1);
    // Fill the vectors (no poo and unrevealed)
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        pss._board[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss._pooField[i].push_back(PooSweeperState::NO_POO);
      }
    }
    // a toggle_mark move at position 0,0
    PooSweeperMove move;
    move.col = 0;
    move.row = 0;
    move.type = PooSweeperMove::TOGGLE_MARK;
    // apply created move
    pss.applyMove(move);
    // The cell should be marked (-2) now.
    ASSERT_EQ(-2, pss._board[0][0]);

    // a toggle_mark move at position 0,0
    PooSweeperMove move2;
    move2.col = 0;
    move2.row = 0;
    move2.type = PooSweeperMove::TOGGLE_MARK;
    // apply created move
    pss.applyMove(move2);
    // The cell should be unrevealed (-1) now.
    ASSERT_EQ(-1, pss._board[0][0]);
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

// ________________________________________________________________________
TEST(PooSweeperStateTest, getCellInfo) {
  {
    // 11x1 field with all CellInfo types
    PooSweeperState pss;
    pss._numRows = 11;
    pss._numCols = 11;
    pss._numPoos = 0;
    pss._numRevealed = 0;
    pss._numMarked = 0;
    pss._gameStatus = PooSweeperStateBase::ONGOING;
    pss._board.clear();
    pss._pooField.clear();
    pss._board.resize(11);
    pss._pooField.resize(11);
    // Fill the vectors (no poo and unrevealed)
    for (int i = 0; i < pss._numRows; ++i) {
      for (int j = 0; j < pss._numCols; ++j) {
        pss._board[i].push_back(PooSweeperStateBase::UNREVEALED);
        pss._pooField[i].push_back(PooSweeperState::NO_POO);
      }
    }
    pss._board[0][0] = PooSweeperStateBase::UNREVEALED;
    pss._board[1][0] = PooSweeperStateBase::REVEALED_POO;
    pss._board[2][0] = PooSweeperStateBase::MARKED;
    pss._board[3][0] = PooSweeperStateBase::REVEALED_ZERO;
    pss._board[4][0] = PooSweeperStateBase::REVEALED_ONE;
    pss._board[5][0] = PooSweeperStateBase::REVEALED_TWO;
    pss._board[6][0] = PooSweeperStateBase::REVEALED_THREE;
    pss._board[7][0] = PooSweeperStateBase::REVEALED_FOUR;
    pss._board[8][0] = PooSweeperStateBase::REVEALED_FIVE;
    pss._board[9][0] = PooSweeperStateBase::REVEALED_SIX;
    pss._board[10][0] = PooSweeperStateBase::REVEALED_SEVEN;
    pss._board[11][0] = PooSweeperStateBase::REVEALED_EIGHT;
    
    // The return of getCellInfo should be unevealed (-1).
    ASSERT_EQ(-1, pss.getCellInfo(0, 0));
    ASSERT_EQ(-3, pss.getCellInfo(1, 0));
    ASSERT_EQ(-2, pss.getCellInfo(2, 0));
    ASSERT_EQ(0, pss.getCellInfo(3, 0));
    ASSERT_EQ(1, pss.getCellInfo(4, 0));
    ASSERT_EQ(2, pss.getCellInfo(5, 0));
    ASSERT_EQ(3, pss.getCellInfo(6, 0));
    ASSERT_EQ(4, pss.getCellInfo(7, 0));
    ASSERT_EQ(5, pss.getCellInfo(8, 0));
    ASSERT_EQ(6, pss.getCellInfo(9, 0));
    ASSERT_EQ(7, pss.getCellInfo(10, 0));
    ASSERT_EQ(8, pss.getCellInfo(11, 0));
  }
}
