#include <iostream>
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

class Doodlebug : public Critter
{

};
#endif

/*The doodlebugs behave according to the following model:
Move: For every time step, the doodlebug will firstly try to move to an adjacent cell 
containing an ant and eat the ant (you can decide if there are several ants in the adjacent cells, 
how the doodlebug will choose to move). If there are no ants in adjacent cells, the doodlebug moves 
according to the same rules as the ant.  Note that a doodlebug cannot eat other doodlebugs.

Breed: If a doodlebug survives for eight time steps, at the end of the time step, it will spawn off 
a new doodlebug in the same manner as the ant (the Doodlebug will only breed into an empty cell).

Starve: If a doodlebug has not eaten an ant within three time steps, at the end of the third time
step it will starve and die. The doodlebug should then be removed from the grid of cells. */
