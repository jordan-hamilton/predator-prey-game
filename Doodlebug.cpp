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

//takes the board, calls the eat function if an ant exists, otherwise changes row and col location of the doodlebug.
//Board function should call row and col to copy bug (ex. Board[Board[old location]->getRow][Board[old location]->getCol] = Board[old location]
void Doodlebug::move(&Board b) {
  bool adjacentAnt = false;
  int openSpots = 0; //number of open spots around bug
  int chosenSpot = 0; //random spot chosen out of those open spots (could be 1 to openSpots)
  int eligibleSpot = 0; //counter of eligible spots. Once this = the chosenSpot, I will update row and col values of the bug.
  bool spotFound = false; //sets to true when the eligible spot is chosen. This prevents false matches.
  
  //Check to see if there is an adjacent ant
  if (row != 0) {
    if (b[row - 1][col] != NULL) {
      if (b[row - 1][col].returnType == 1) {
        adjacentAnt = true;
      }
    }
  }
  if (row != (b.getNumRows() - 1) { // -1 because board is 0 to numRows - 1
    else if (b[row + 1][col] != NULL) {
      if (b[row + 1][col].returnType == 1) {
        adjacentAnt = true;
      }
    }
  }
  if (col != 0) {
    else if (b[row][col - 1] != NULL) {
      if (b[row][col - 1].returnType == 1) {
        adjacentAnt = true;
      }
    }
  }
  if (col != b.getNumCols() - 1) {
    else if (b[row][col + 1] != NULL) {
      if (b[row][col + 1].returnType == 1) {
        adjacentAnt = true;
      }
    }
  }
  
  //if there is an adjacent ant, call the eat function and eat it
  if (adjacentAnt == true) {
    this->eat(&Board b);
  }
  
  //otherwise, look for open spots and take one at random
  else {
    //Check to see the number of open spots
  if (row != 0) {
    if (b[row - 1][col] != NULL) {
      if (b[row - 1][col].returnType == 1) {
        openSpots += 1;
      }
    }
  }
  if (row != (b.getNumRows() - 1) { // -1 because board is 0 to numRows - 1
    else if (b[row + 1][col] != NULL) {
      if (b[row + 1][col].returnType == 1) {
        openSpots += 1;
      }
    }
  }
  if (col != 0) {
    else if (b[row][col - 1] != NULL) {
      if (b[row][col - 1].returnType == 1) {
        openSpots += 1;
      }
    }
  }
  if (col != b.getNumCols() - 1) {
    else if (b[row][col + 1] != NULL) {
      if (b[row][col + 1].returnType == 1) {
        openSpots += 1;
      }
    }
  }
  
  //if the number of open spots > 0, pick one at random.
  if (openSpots > 1) {
    chosenSpot = rand() % openSpots + 1;
  }
  else if (openSpots == 1) {
    chosenSpot = 1;
  }
  
  //if the chosenSpot is greater than 0, there is a spot to move into, move into it.
  if (chosenSpot > 0) {
    if (row != 0) {
      if (b[row - 1][col] != NULL) {
        if (b[row - 1][col].returnType == 1) {
          eligibleSpot += 1;
          if (eligibleSpot == chosenSpot) {
            row = row - 1;
            col = col;
          }
        }
      }
    }
    if (row != (b.getNumRows() - 1) { // -1 because board is 0 to numRows - 1
      else if (b[row + 1][col] != NULL) {
        if (b[row + 1][col].returnType == 1) {
          eligibleSpot += 1;
          if (eligibleSpot == chosenSpot) {
            row = row - 1;
            col = col;
          }
        }
      }
    }
    if (col != 0) {
      else if (b[row][col - 1] != NULL) {
        if (b[row][col - 1].returnType == 1) {
          openSpots += 1;
        }
      }
    }
    if (col != b.getNumCols() - 1) {
      else if (b[row][col + 1] != NULL) {
        if (b[row][col + 1].returnType == 1) {
          openSpots += 1;
        }
      }
    }
    //Lots of work left to do. I should be searching for NULL spaces as eligible spots so I need to fix that first.
      
  //Just here so I can copy paste
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
