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
  int numDoodleBugs;
  Critter** bugBoard;
  
public:
  Board();
  Board(int row, int col, int ant, int doodleBug);
  void placeDoodleBug();
  void placeAnt();
  void moveDoodleBugs
