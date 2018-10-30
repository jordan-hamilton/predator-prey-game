#ifndef BOARD_HPP
#define BOARD_HPP
#include "Critter.hpp"
#include "Doodlebug.hpp"
#include "Ant.hpp"

using std::rand;

/* private member variables of the class
  int numRows;
  int numCols;
  int numAnts;
  int numDoodlebugs;
  Critter*** bugBoard;
*/

//default constructor, sets private members to standard values and creates board
Board::Board() {
  numRows = 20;
  numCols = 20;
  numAnts = 100;
  numDoodlebugs = 5;

  //dynamically allocate the bugBoard
  bugBoard = new Critter**[numRows];
  for (int i = 0; i < numRows; i++) {
    bugBoard[i] = new Critter*[numCols];
  }
  
  //Set the pointers to null
  for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        bugBoard[i][j] = NULL;
      }
  }
  
  //place the ants
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(1); //1 indicates ant
  }
  
  //place the doodlebugs
  for (int i = 0; i < numDoodlebugs; i++) {
    this->placeBug(0); //0 indicates doodlebug
  }
}

//creates the initial board with input rows, columns, ants, and doodlebugs
Board::Board(int row, int col, int ant, int doodlebug) {
  numRows = row;
  numCols = col;
  numAnts = ant;
  numDoodlebugs = doodlebug;

  //dynamically allocate the bugBoard
  bugBoard = new Critter**[numRows];
  for (int i = 0; i < numRows; i++) {
    bugBoard[i] = new Critter*[numCols];
  }
  
  //Set the pointers to null
  for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        bugBoard[i][j] = NULL;
      }
  }
  
  //place the ants
  for (int i = 0; i < numAnts; i++) {
    this->placeBug(1);
  }
  
  //place the doodlebugs
  for (int i = 0; i < numDoodlebugs; i++) {
    this->placeBug(0);
  }
}

//places a bug (0 for input for doodlebug, 1 for ant)
void Board::placeBug(int species) {
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
              bugBoard[i][j] == new Doodlebug(i, j);
            }
            else if (species == 1) {
              bugBoard[i][j] == new Ant(i, j);
            }
            else {
              cout << "Invalid species call to placeBug. Expected '0' or '1'. Got" << species << ".\n";
            }
          }
        }
     }
  }
}
  //need some sort of a returnSpecies function to ID doodlebugs/ants before we can add these...
void Board::moveDoodlebugs() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (bugBoard[i][j]->returnType == 0) {
        //call move function here
      }
    }
  }
}
  
void Board::breedDoodlebugs() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (bugBoard[i][j]->returnType == 0) {
        //call breed function here
      }
    }
  }
}
  
void Board::moveAnts() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (bugBoard[i][j]->returnType == 1) {
        //call move function here
      }
    }
  }
}

void Board::breedAnts() {
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      if (bugBoard[i][j]->returnType == 1) {
        //call breed function here
      }
    }
  }
}
  
void Board::printBoard() {
    //print top border
    for (int i = 0; i < numRows + 2; i++) {
      cout << "-";
    }
    
    cout << endl;
    
    for (int i = 0; i < numRows; i++) {
      
      //print side border
      cout << "|";
      
      //loop through columns
      for (int j = 0; j < numCols; j++) {
        if (bugBoard[i][j] == NULL) {
          cout << " ";
        }
        else if (bugBoard[i][j]->returnType == 0) {
          cout << "X";
        }
        else if (bugBoard[i][j]->returnType == 1) {
          cout << "O";
        }
        else {
          cout << "Z" //debug character
        }
      }
      
      //print side border, move to new line
      cout << "|" << endl;
    }
}

Critter* Board::getContents(int row, int col) {
  return bugBoard[row][col];
}

int Board::getNumCols() {
  return numCols;
}

int Board::getNumRows() {
  return numRows;
}
