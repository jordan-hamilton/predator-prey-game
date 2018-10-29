#include "Ant.hpp"

Ant::Ant()
{
    row = -1;
    column = -1;
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


void Ant::move(Board ***board, int row, int column)
{
    // 1 = RIGHT, 2 = LEFT, 3 = UP, 4 = DOWN
    int direction = rand()% 4 + 1;

    // PICK RANDOM DIRECTION
    // CHECK IF CELL AT DIRECTION IS OCCUPIED OR GOES OFF GRID
        // IF YES, ANT STAYS IN CURRENT LOCATION

    switch (direction)
    {
        case 1:     // Ant moving right
            if (board[row][column + 1]) == NULL
            {

            }
            else
            {

            }
            break;

        case 2:     // Ant moving left
            if (board[row][column - 1]) == NULL
            {

            }
            else
            {

            }
            break;

        case 3:     // Ant moving up
            if (board[row - 1][column]) == NULL
            {

            }
            else
            {

            }
            break;
        case 4:     // Ant moving down
            if(board[row + 1][column]) == NULL
            {

            }
            else
            {

            }
            break;
    }
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
