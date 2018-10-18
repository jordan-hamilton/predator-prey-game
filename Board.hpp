#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

class Board {
private:
  int numRows;
  int numCols;
  int numAnts;
  int numDoodlebugs;
  Critter** bugBoard;
  
public:
  Board();
  
  Board(int row, int col, int ant, int doodlebug);
  
  void placeDoodlebug();
  
  void placeAnts();
  
  void moveDoodlebugs();
  
  void breedDoodlebugs();
  
  void moveAnts();
  
  void breedAnts();
  
  void printBoard();

#endif
