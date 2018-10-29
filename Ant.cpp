#include "Ant.hpp"

// Default constructor for Ant(), set variables to default values
Ant::Ant()
{
    row = -1;
    col = -1;
    age = 0;
    isEaten = false;
}

// Ant constructor
Ant::Ant(int r, int c)
{
    row = r;
    col = c;
    age = 0;
    isEaten = false;
}

// Ant Destructor
Ant::~Ant()
{
    // Destructor
}

/*********************************************************************
** Ant::move() moves the ants randomly move up, down, left, or right. 
** If the neighboring cell in the selected direction is occupied or 
** would move the ant off the grid, then the ant stays in the current cell.
*********************************************************************/
void Ant::move(Board &board, int row, int col)
{
    // 1 = RIGHT, 2 = LEFT, 3 = UP, 4 = DOWN
    int direction = rand()% 4 + 1;

    switch (direction)
    {
        case 1:     // Ant moving right
            if((col + 1 >= 0) && (col + 1 < 20))
            {
                if (board[row][col + 1]) == NULL
                {
                    col += 1;
                }
            }
            break;

        case 2:     // Ant moving left
            if((col - 1 >= 0) && (col - 1 < 20))
            {
                if (board[row][col - 1]) == NULL
                {
                    col -= 1;
                }
            }
            break;

        case 3:     // Ant moving up
            if((row - 1 >= 0) && (row - 1 < 20))
            {
                if (board[row - 1][col]) == NULL
                {
                    row -= 1;
                }
            }
            break;
                
        case 4:     // Ant moving down
            if((row + 1 >= 0) && (row + 1 < 20))
            {
                if(board[row + 1][col]) == NULL
                {
                    row += 1;
                }
            }
            break;
    }
}

void Ant::breed(//add params)
{
    
}
    
//print the type of bug (for use in print board function)
void Ant::printType() {
  cout << "ant";
  
  //return a 0 for doodlebug and 1 for ant (for use in movement and eating functions? We may just get rid of this one)
void Ant::returnType() {
  return 1;
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
