/*********************************************************************
** Program name: inputValidation.cpp
** Author: Jacob Anderson
** Date: 10/8/18
** Description: Implementation file for input validation functions
*********************************************************************/

#include <iostream>
#include "inputValidation.hpp"

using std::endl;
using std::cin;
using std::cout;

/*********************************************************************
** Takes a reference to an int as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid int is entered.
*********************************************************************/
void getValidInt(int &input) {
	bool whileBool = false;
	while (whileBool == false) {
		cin >> input;
		if (cin.fail()) {
			cout << "Invalid input - do not spell out the number or verify it is less than overflow.\n";
			cout << "Please re-enter the desired integer:\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else if (cin.rdbuf()->in_avail() > 1) {
			cout << "Invalid input - please do not enter any characters (including '.') or spaces after the desired integer.\n";
			cout << "Please re-enter the desired integer:\n";
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else {
			whileBool = true;
		}
	}
}

/*********************************************************************
** Takes a reference to a double as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid double is entered.
*********************************************************************/
void getValidDouble(double &input) {
	bool whileBool = false;
	while (whileBool == false) {
		cin >> input;
		if (cin.fail()) {
			cout << "Invalid input - please do not spell out the number or verify it less than overflow.\n";
			cout << "Please re-enter the desired double:\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else if (cin.rdbuf()->in_avail() > 1) {
			cout << "Invalid input - please do not enter any characters or spaces after the desired double.\n";
			cout << "Please re-enter the desired double:\n";
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else {
			whileBool = true;
		}
	}
}

/*********************************************************************
** Takes a reference to a char as a parameter. The function then gets
** input from the user and attempts to validate it. The function will
** continue to get input until a valid char is entered.
*********************************************************************/
void getValidChar(char &input) {
	bool whileBool = false;
	while (whileBool == false) {
		cin >> input;
		if (cin.fail()) {
			cout << "Invalid input - please enter a valid int.";
			cout << "Please re-enter the desired character:\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else if (cin.rdbuf()->in_avail() > 1) {
			cout << "Invalid input - please do not enter any characters or spaces after the desired character.\n";
			cout << "Please re-enter the desired character:\n";
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else {
			whileBool = true;
		}
	}
}