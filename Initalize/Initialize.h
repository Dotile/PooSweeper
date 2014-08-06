// Initilize the Game by requesting boardsize and mine quantity

#include <iostream>

#ifndef INITALIZE_INITIALIZE_H_
#define INITALIZE_INITIALIZE_H_

using namespace std;

class Initalize {
 public:
  // Contructor
  Initialize();

  // Create gameboard
  initBoard(int, int, int);

  // Destructor
  ~Initalize();

 private:
  int _dimx;
  int _dimy;
  int _nummine;
  int _gameboard;
  int _minex;
  int _miney;

 protected:
};

#endif  // INITALIZE_INITIALIZE_H_
