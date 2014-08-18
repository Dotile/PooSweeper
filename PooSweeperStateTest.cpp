// Copyright 2014
// Dominik Leclerc

#include <gtest/gtest.h>
#include "./PooSweeperStateBase.h"
#include "./PooSweeperState.h"

// ____________________________________________________________________________
TEST(StateTest, initialize) {
  {
  PooSweeperState state;
  POO->initialize(5,5,5);
  ASSERT_EQ(PooSweeperStateBase::UNREVEALED, state._pooField[0][0]);
  }
}
