#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"
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
  
  //place the ants
  for (int i = 0; i < numAnts; i++) {
    this->placeAnts();
  }
  
  //place the doodlebugs
  for (int i = 0; i < numAnts; i++) {
    this->placeDoodlebugs();
  }
}
  
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
    this->placeAnts();
  }
  
  //place the doodlebugs
  for (int i = 0; i < numAnts; i++) {
    this->placeDoodlebugs();
  }
}
  
void placeDoodlebug() {
  
}
  
  
  void placeAnts();
  
  void moveDoodlebugs();
  
  void breedDoodlebugs();
  
  void moveAnts();
  
  void breedAnts();
  
  void printBoard();
