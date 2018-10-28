#include "Ant.hpp"

Ant::Ant()
{
    rows = -1;
    columns = -1;
    age = 0;
    isEaten = false;
}

Ant::Ant(int r, int c)
{
    row = r;
    column = c;
    age = 0;
    isEaten = false;
}

Ant::~Ant()
{
    // Destructor
}

/* For every step, the ants randomly move up, down, left, or right. If the neighboring 
cell in the selected direction is occupied or would move the ant off the grid, then the ant stays 
in the current cell. */


void Ant::move(Board &board, int rows, int columns)
{
    int direction = rand()% 4 + 1;
    
}

void Ant::breed(//add params)
{
    
}
void Ant::printType()
{
    std::cout << "O" << std::endl;   
}

/* The ants behave according to the following model:
Move: For every time step, the ants randomly move up, down, left, or right. If the neighboring 
cell in the selected direction is occupied or would move the ant off the grid, then the ant stays 
in the current cell.
Breed: If an ant survives for three time steps (not been eaten by doodlebugs), at the end of the 
time step (i.e., after moving) the ant will breed. This is simulated by creating a new ant in an 
adjacent (up, down, left, or right) cell that is empty randomly. If the cell that is picked is not empty,
randomly attempt to pick another one.  If there is no empty cell available, no breeding occurs.  
Once an offspring is produced, an ant cannot produce an offspring again until it has 
survived three more time steps. */
