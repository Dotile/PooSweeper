// Copyright 2014
// Dominik Leclerc


#include <gtest/gtest.h>
#include "./PooSweeperState.h"

// ____________________________________________________________________________
TEST(PooSweeperStateTest, initialize) {
  PooSweeperState pss;
  pss.initialize(5, 5, 5);
  // Check if the nuber of bombs is correct
  size_t count = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if (pss._pooField[i][j] == PooSweeperState::POO) {
        ++count; 
      }
    }
  }
  ASSERT_EQ(5, count);
  ASSERT_EQ(5, pss.numRows());
  ASSERT_EQ(5, pss.numCols());
}
