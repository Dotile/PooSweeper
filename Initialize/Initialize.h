// Initialize the Game by requesting boardsize and mine quantity

#include <iostream>

#ifndef INITIALIZE_INITIALIZE_H_
#define INITIALIZE_INITIALIZE_H_

using namespace std;

class Initialize {
 public:
  // Contructor
  Initialize();

  // Create gameboard
  void initBoard(int, int, int);

  // Destructor
  ~Initialize();

 private:
  int _dimx;
  int _dimy;
  int _nummine;
  int _gameboard;
  int _minex;
  int _miney;

 protected:
};

#endif  // INITIALIZE_INITIALIZE_H_
