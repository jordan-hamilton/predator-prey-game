/*The doodlebugs behave according to the following model:
Move: For every time step, the doodlebug will firstly try to move to an adjacent cell
containing an ant and eat the ant (you can decide if there are several ants in the adjacent cells,
how the doodlebug will choose to move). If there are no ants in adjacent cells, the doodlebug moves
according to the same rules as the ant.  Note that a doodlebug cannot eat other doodlebugs.
Breed: If a doodlebug survives for eight time steps, at the end of the time step, it will spawn off
a new doodlebug in the same manner as the ant (the Doodlebug will only breed into an empty cell).
Starve: If a doodlebug has not eaten an ant within three time steps, at the end of the third time
step it will starve and die. The doodlebug should then be removed from the grid of cells. */

#include <cstdlib>
#include <iostream>

#include "Doodlebug.hpp"

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
void Doodlebug::move(Critter*** board, int row, int col) {
  bool adjacentAnt = false;
  int direction;
  bool validMove = true;
	
  //set hasMoved to true (it will be reset in breed)
  hasMoved = true;

  //Check to see if there is an adjacent ant
  if (row != 0) {
    if (board[row - 1][col] != NULL) {
      if (board[row - 1][col]->returnType() == 1) {
        adjacentAnt = true;
      }
    }
  }
  if (row != (board.getNumRows() - 1)) { // -1 because board is 0 to numRows - 1
    if (board[row + 1][col] != NULL) {
      if ( board[row + 1][col]->returnType() == 1 ) {
        adjacentAnt = true;
      }
    }
  }
  if (col != 0) {
    if ( board[row][col - 1] != NULL ) {
      if ( board[row][col - 1]->returnType() == 1 ) {
        adjacentAnt = true;
      }
    }
  }
  if (col != board.getNumCols() - 1) {
    if ( board[row][col + 1] != NULL ) {
      if ( board[row][col + 1]->returnType() == 1 ) {
        adjacentAnt = true;
      }
    }
  }

  //if there is an adjacent ant, call the eat function and eat it
  if (adjacentAnt == true) {
    this->eat(board);
  }

  //otherwise, look for open spots and take one at random, add 1 to lastMeal
  else {
    //increment last meal
    lastMeal += 1;
	  
    //Pick a direction at random, move if it is valid
    direction = rand() % 4 + 1; //1 for north, 2 for east, 3 for south, 4 for west
    
    //top row condition
    if (row == 0 && direction == 1) {
    validMove = false;
    }
    //left edge condition
    else if (col == 0 && direction == 4) {
    validMove = false;  
    }
    //bottom row condition
    else if ( row == getNumRows() - 1 && direction == 3) {
    validMove = false;  
    }
    //left edge condition
    else if (col == getNumCols() - 1 && direction == 2) {
    validMove = false;  
    }
    //if not an edge case, check for contents already
    else if (direction == 1) {
      if (board[row - 1][col] != NULL) {
        validMove = false;
      }
    }
    else if (direction == 2) {
      if (board[row][col + 1] != NULL) {
        validMove = false;
      }
    }
    else if (direction == 3) {
      if (board[row + 1][col] != NULL) {
        validMove = false;
      }
    }
    else if (direction == 4) {
      if (board[row][col + 1] != NULL) {
        validMove = false;
      }
    }
	 
    if (validMove == true) {
      if (direction == 1) {
        row = row - 1;
	col = col;
      }
      else if (direction == 2) {
        row = row;
	col = col + 1;
      }
      else if (direction == 3) {
        row = row - 1;
	col = col;
      }
      else if (direction == 4) {
        row = row;
	col = col - 1;
      }
    }
  }
}

void Doodlebug::eat(Critter*** board) {
  int eligibleSpots = 0;
  int chosenSpot;
  
  //Check to see where adjacent ants are, add to eligible spots
  if (row != 0) {
    if (board[row - 1][col] != NULL) {
      if (board[row - 1][col]->returnType() == 1) {
        eligibleSpots += 1;
      }
    }
  }
  if (row != (board.getNumRows() - 1)) { // -1 because board is 0 to numRows - 1
    if (board[row + 1][col] != NULL) {
      if ( board[row + 1][col]->returnType() == 1 ) {
        eligibleSpots += 1;
      }
    }
  }
  if (col != 0) {
    if ( board[row][col - 1] != NULL ) {
      if ( board[row][col - 1]->returnType() == 1 ) {
        eligibleSpots += 1;
      }
    }
  }
  if (col != board.getNumCols() - 1) {
    if ( board[row][col + 1] != NULL ) {
      if ( board[row][col + 1]->returnType() == 1 ) {
        eligibleSpots += 1;
      }
    }
  }

  chosenSpot = rand() % eligibleSpots + 1;
  
  //Find chosen spot, move row and col to it, (the ant will be deleted and this will be moved in board function), reset lastMeal
  if (row != 0) {
    if (board[row - 1][col] != NULL) {
      if (board[row - 1][col]->returnType() == 1) {
        eligibleSpots += 1;
        if (eligibleSpot == chosenSpot) {
	  row = row - 1;
	  col = col;
	  lastMeal = 0;
	}
      }
    }
  }
  if (row != (board.getNumRows() - 1)) { // -1 because board is 0 to numRows - 1
    if (board[row + 1][col] != NULL) {
      if ( board[row + 1][col]->returnType() == 1 ) {
        eligibleSpots += 1;
	if (eligibleSpot == chosenSpot) {
	  row = row + 1;
	  col = col;
	  lastMeal = 0;
	}
      }
    }
  }
  if (col != 0) {
    if ( board[row][col - 1] != NULL ) {
      if ( board[row][col - 1]->returnType() == 1 ) {
        eligibleSpots += 1;
	if (eligibleSpot == chosenSpot) {
	  row = row;
	  col = col - 1;
	  lastMeal = 0;
	}
      }
    }
  }
  if (col != board.getNumCols() - 1) {
    if ( board[row][col + 1] != NULL ) {
      if ( board[row][col + 1]->returnType() == 1 ) {
        eligibleSpots += 1;
	if (eligibleSpot == chosenSpot) {
	  row = row;
	  col = col + 1;
	  lastMeal = 0;
	}
      }
    }
  }
}


void Doodlebug::breed(Critter*** board) {
  //TODO
}


/*bool Doodlebug::starve() {
  return false;
  //TODO
}*/


void Doodlebug::incrementLastMeal() { //probably don't need this anymore, built it into move instead
  lastMeal += 1;
}


int Doodlebug::getLastMeal() {
  return lastMeal;
}


void Doodlebug::setLastMeal(int meal) {
  lastMeal = meal;
}
//print the type of bug (for use in print board function)
void Doodlebug::printType() {
  cout << "doodlebug";
}

  //return a 0 for doodlebug and 1 for ant (for use in movement and eating functions? We may just get rid of this one)
int Doodlebug::returnType() {
  return 0;
}

/*Just here so I can copy paste
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
*/
