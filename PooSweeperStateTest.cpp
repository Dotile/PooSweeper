// Copyright 2014
// Dominik Leclerc

#include <gtest/gtest.h>
#include "./PooSweeperState.h"

// ____________________________________________________________________________
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
