#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

using std::rand();

/* private member variables of the class
  int numRows;
  int numCols;
  int numAnts;
  int numDoodlebugs;
  Critter*** bugBoard;
*/
  
public:

//default constructor, sets private members to standard values and creates board
Board() {
  numRows = 20;
  numCols = 20;
  numAnts = 100;
  numDoodlebugs = 5;

  //dynamically allocate the bugBoard
  bugBoard = new Critter**[numRows];
  for (int i = 0; i < numRows; i++) {
    Critter[i] = new Critter*[numCols];
  }
  
  //Set the pointers to null
  for (int i = 0; i < numRows; i++)
      for (int j = 0; j < numCols; j++) {
        bugBoard[i][j] = NULL;
      }
  }
  
  //place the ants
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(1); //1 indicates ant
  }
  
  //place the doodlebugs
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(0); //0 indicates doodlebug
  }
}

//creates the initial board with input rows, columns, ants, and doodlebugs
Board(int row, int col, int ant, int doodlebug) {
  numRows = row;
  numCols = col;
  numAnts = ant;
  numDoodlebugs = doodlebug;

  //dynamically allocate the bugBoard
  bugBoard = new Critter**[numRows];
  for (int i = 0; i < numRows; i++) {
    Critter[i] = new Critter*[numCols];
  }
  
  //Set the pointers to null
  for (int i = 0; i < numRows; i++)
      for (int j = 0; j < numCols; j++) {
        bugBoard[i][j] = NULL;
      }
  }
  
  //place the ants
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(1);
  }
  
  //place the doodlebugs
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(0);
  }
}

//places a bug (0 for input for doodlebug, 1 for ant)
void placeBug(int species) {
  int eligibleSpaces = 0;
  int bugSpace;
  
  //Determine how many eligible spaces are left on board
  for (int i = 0; i < numRows; i++)
      for (int j = 0; j < numCols; j++) {
        if (bugBoard[i][j] == NULL) {
          eligibleSpaces += 1;
      }
  }
  
  //Determine which eligible space to place doodlebug
  bugSpace = rand() % eligibleSpaces + 1;
  
  //reset eligibleSpace counter
  eligibleSpaces = 0;
  
  //Find eligible space, create doodlebug
  for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        if (bugBoard[i][j] == NULL) {
          eligibleSpaces += 1;
          if (eligibleSpaces == bugSpace) {
            if (species == 0) {
              bugBoard[i][j] == new Doodlebug;
            }
            else if (species == 1) {
              bugBoard[i][j] == new Ant;
            }
            else {
              cout << "Invalid species call to placeBug. Expected '0' or '1'. Got" << species << ".\n";
            }
          }
        }
     }
  }
}
  
  void moveDoodlebugs();
  
  void breedDoodlebugs();
  
  void moveAnts();
  
  void breedAnts();
  
  void printBoard();
