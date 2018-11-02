#include "Critter.hpp"

void Critter::incrementAge() {
  age += 1;
}

int Critter::getAge() {
  return age;
}

void Critter::setAge(int a) {
  age = a;
}

void Critter::setHasMoved(int i) {
  if (i == 0) {
    hasMoved = false;
  } else if (i == 1) {
    hasMoved = true;
  }
}

bool getHasMoved() {
  return hasMoved;
}
  
int getRow() {
  return row;
}
  
int getCol() {
  return col;
}

//always returns false because only a doodlebug can starve
bool starve() {
  return false;
}

/*
 * doesFreeAdjacentExist takes a board as a parameter and checks the spaces adjacent to the critter's coordinates.
 * If any of the spaces are free, it'll immediately return true regardless of the number of spaces. It will only return false
 * if all four have been checked and shown to not be empty.
 */
bool Critter::doesFreeAdjacentExist(Board &b)
{
	//Checking up
	if (b.getContents(this->row -1, this->col) == NULL)
	{
		return true;
	}

	//Checking Right
	else if (b.getContents(row, col + 1) == NULL)
	{
		return true;
	}

	//Down
	else if (b.getContents(row + 1, col) == NULL)
	{
		return true;
	}

	//Left
	else if (b.getContents(row, col - 1) == NULL)
	{
		return true;
	}

	else return false;
}
