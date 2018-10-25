/*The doodlebugs behave according to the following model:
Move: For every time step, the doodlebug will firstly try to move to an adjacent cell 
containing an ant and eat the ant (you can decide if there are several ants in the adjacent cells, 
how the doodlebug will choose to move). If there are no ants in adjacent cells, the doodlebug moves 
according to the same rules as the ant.  Note that a doodlebug cannot eat other doodlebugs.
Breed: If a doodlebug survives for eight time steps, at the end of the time step, it will spawn off 
a new doodlebug in the same manner as the ant (the Doodlebug will only breed into an empty cell).
Starve: If a doodlebug has not eaten an ant within three time steps, at the end of the third time
step it will starve and die. The doodlebug should then be removed from the grid of cells. */

#include <iostream>
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "cstdlib"

using std::cout;
using std::endl;
using std::rand;

//Default constructor. Shouldn't be called.
Doodlebug::Doodlebug() {
  row = -1;
  col = -1;
  age = 0;
  lastMeal = 0;
  cout << "Error = default doodlebug constructor called. Only overloaded constructor should be called.\n";
}

//Overloaded contstructor
 Doodlebug::Doodlebug(int r, int c) {
   row = r;
   col = c;
   age = 0;
   lastMeal = 0;
   isStarved = false;
 }

//Destructor. Not doing anything special at the moment.
Doodlebug::~Doodlebug() {}

void Doodlebug::move(&Board b) {
  bool adjacentAnt = false;
  
  //Check to see if there is an adjacent ant
  if (b[row - 1][col] != NULL) {
    if (b[row - 1][col].returnType == 1) {
      adjacentAnt = true;
    }
  }
  else if (b[row + 1][col] != NULL) {
    if (b[row + 1][col].returnType == 1) {
      adjacentAnt = true;
    }
  }
  else if (b[row][col - 1] != NULL) {
    if (b[row][col - 1].returnType == 1) {
      adjacentAnt = true;
    }
  }
  else if (b[row][col + 1] != NULL) {
    if (b[row][col + 1].returnType == 1) {
      adjacentAnt = true;
    }
  }

class Doodlebug : public Critter
{
private:
  int lastMeal;
  bool isStarved;
  
public:
  Doodlebug::Doodlebug();
  Doodlebug(int, int); // ints - row and column location of Doodlebug
  ~Doodlebug();
  void move(&Board b) {
  
  virtual void eat(//add params);
  virtual void breed(//add params);
  void starve();
  void incrementLastMeal();   // lastMeal++
  int getLastMeal();
  void setLastMeal(int);
};
#endif
