// Challenge 3 - Temperature Converter (C to F/F to C)
// I will be practicing functions and passing variables in this Challenge
// by Jake R. & Will C.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>

// Forward declaring the functions
void CelstoFahr();
void FahrtoCels();
double UserReadDoubleInput();
int UserReadIntInput();
void menu();

void CelstoFahr()
{
	// Declaring cin_fail_check to enable me to have the cin.fail() as a function
	double celsius_amount = -1;
	double fahrenheit_amount = -1;

	std::cout << "\nPlease enter your celsius temperature\n";
	celsius_amount = UserReadDoubleInput();

	// Make conversion using the formula for C to F
	fahrenheit_amount = (celsius_amount * 1.8) + 32.0;

	std::cout << "\n" << celsius_amount << " degrees Celsius is equal to " << fahrenheit_amount << " degrees Fahrenheit\n\n";
}

void FahrtoCels()
{
	// Declaring cin_fail_check to enable me to have the cin.fail() as a function
	double celsius_amount = -1;
	double fahrenheit_amount = -1;

	std::cout << "\nPlease enter your fahrenheit temperature\n";
	fahrenheit_amount = UserReadDoubleInput();

	// Make conversion using the formula for F to C
	celsius_amount = (fahrenheit_amount - 32.0) * (5.0 / 9.0);

	std::cout << "\n" << fahrenheit_amount << " degrees Fahrenheit is equal to " << celsius_amount << " degrees Celsius\n\n";
}

// Read and check user integer inputs
double UserReadDoubleInput()
{
	double input = -1;
	bool valid = false;
	do
	{
		std::cout << "Enter a number: " << std::flush;
		std::cin >> input;
		if (std::cin.good())
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			std::cin.clear();
			//and empty it
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter." << std::endl;
		}
	} while (!valid);

	return (input);

}

//Read and check user integer inputs
int UserReadIntInput()
{
	int input = -1;
	bool valid = false;
	do
	{
		std::cout << "Enter a number: " << std::flush;
		std::cin >> input;
		if (std::cin.good())
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			// Something went wrong, we reset the buffer's state to good
			std::cin.clear();
			// and empty it
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please re-enter.\n";
		}
	} while (!valid);

	return (input);

}

// Writing the menu() function to enable loopback from the restart function
void menu()
{
	int user_selection = 0;
	std::cout << "1. Convert Celsius to Fahrenheit\n";
	std::cout << "2. Convert Fahrenheit to Celsius\n";
	std::cout << "3. Exit program\n";

	user_selection = UserReadIntInput();

	switch (user_selection)
	{
		case 1:
			// Run Celsius to Fahrenheit function and retrieve the values to cout here
			CelstoFahr();
			menu();
			break;
		case 2:
			// Run Fahrenheit to Celsius function and retrieve the values to cout here
			FahrtoCels();
			menu();
			break;
		case 3:
			std::cout << "\nGoodbye";
			break;
		default:
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nPlease enter a number between 1 and 3 for your selection!\n\n";
			menu();
			break;
	}
}

int main()
{

	// Declare variables to be used and passed between functions as needed
	std::cout << "Welcome to the Temperature Converter!\n\n";
	menu();

	//clear buffer, wait for input to close program
	std::cin.clear(); std::cin.ignore(INT_MAX, '\n');
	std::cin.get();

	return 0;
}