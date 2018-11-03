/*********************************************************************
** Program name: Menu.cpp
** Author: Sarah Flower
** Date: October 2, 2018
** Description: This is the class implementation file for Menu. This
** allows for inputting menu choices and checks that user input
** is valid (integers).
*********************************************************************/
#include "Menu.hpp"
#include "Board.hpp"
#include <algorithm>
#include <climits>

/*********************************************************************
** Default constructor for Menu takes no arguments.
*********************************************************************/
Menu::Menu()
{

}

/*********************************************************************
** displayMenu() prints the Menu to the console.
*********************************************************************/
void Menu::displayMenu()
{
    for (unsigned int i = 0; i < menuVector.size(); i++)
    {
        std::cout << menuVector[i] << std::endl;
    }
    std::cout << "\n";
}

/*********************************************************************
** addOption(string) allows the user to add options to the Menu
** vector, which holds all menu options.
*********************************************************************/
void Menu::addOption(std::string option)
{
    menuVector.push_back(option);
}

/*********************************************************************
** getChoice() takes the user input and verifies it is valid using
** std::stoi, which ignores whitespace and takes the first valid
** integer input as its value.
*********************************************************************/
int Menu::getChoice()
{
    while(1)
    {
        std::getline(std::cin,input);

        // Checks all of input string to identify whether it is an integer
        if ((std::all_of(input.begin(), input.end(), ::isdigit)) && !input.empty())
        {
            return std::stoi(input);
        }
        // If something other than integer is entered, give user an error
        else
        {
            std::cout << "Invalid entry. Re-enter your choice." << std::endl;
        }
    }
}

void Menu::run()
{
    Menu menu;
    menu.addOption("Enter the number of steps to run the Doodlebug/Ant simulation.");
    menu.
    int numSteps = menu.getChoice();
    menu.displayMenu();
    for (int i = 0; i < numSteps; i++)
    {
        Board board;
        board.printBoard();
        board.moveAnts();
        board.moveDoodlebugs();
        board.starve();
        board.breedAnts();
        board.breedDoodlebugs(); 
    }
}
