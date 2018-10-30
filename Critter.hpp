#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>

#include "Board.hpp"

class Critter
{
protected:
  int col;
  int row;
  int age;

public:

  virtual ~Critter() {};

  //move critter according to rules
  virtual void move(Board &board, int row, int col) = 0;

  //breed critter according to rules
  virtual void breed(Board &b) = 0;

  //return true if creature has starved (only doodlebug function)
  //TODO virtual bool starve();

  //print the type of bug (for use in print board function)
  virtual void printType() = 0;

  //return a 0 for doodlebug and 1 for ant (for use in movement and eating functions? We may just get rid of this one)
  virtual int returnType() = 0;

  //adds 1 to the age
  void incrementAge();

  //sets the age = to int a
  void setAge(int a);
};
#endif

/*Create a class named Critter that contains data and functions common to ants and doodlebugs.
This class should have a virtual function named move that is defined in the derived classes of
Ant and Doodlebug.  Each class will be in its own source file. */
