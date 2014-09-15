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

// ____________________________________________________________________________
TEST(PooSweeperStateTest, initialize2) {
  PooSweeperState pssb;
  pssb.initialize(5, 5, 5);
  ASSERT_EQ(10, pssb.numRows());
}

