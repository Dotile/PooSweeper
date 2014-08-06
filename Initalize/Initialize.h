// Initilize the Game by requesting boardsize and mine quantity

#include <iostream>

using namespace std;

class Initalize 
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

 protected:

