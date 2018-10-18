#include <iostream>
#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
private:
  int col;
  int row;
  int age;
  
public:
  virtual void move() = 0;
  virtual void breed() = 0;
  virtual void starve() = 0;
  virtual void printType() = 0;
  void incrementAge();
  void setAge(int a);
  
};
#endif

/*Create a class named Critter that contains data and functions common to ants and doodlebugs. 
This class should have a virtual function named move that is defined in the derived classes of 
Ant and Doodlebug.  Each class will be in its own source file. */
