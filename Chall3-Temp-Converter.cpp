// Challenge 3 - Temperature Converter (C to F/F to C)
// I will be practicing functions and passing variables in this Challenge
// by Jake R.

#include "stdafx.h"
#include <iostream>
#include <string>	

// Initializing the functions, with user input validation, for Cels -> Fahr, Fahr -> Cels and User Selection
double CelstoFahr(double celsius_amount, double fahrenheit_amount)
{
	std::cout << "Please enter the amount to be converted to Fahrenheit: ";
	std::cin >> celsius_amount;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nBad entry, no text allowed! Enter a Number: ";
		std::cin >> celsius_amount;
	}

	// Make conversion using the formula for C to F
	fahrenheit_amount = (celsius_amount * 1.8) + 32;

	return fahrenheit_amount;
}

double FahrtoCels(double celsius_amount, double fahrenheit_amount)
{
	std::cout << "Please enter the amount to be converted to Celsius: ";
	std::cin >> fahrenheit_amount;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nBad entry, no text allowed! Enter a Number: ";
		std::cin >> fahrenheit_amount;
	}

	// Make conversion using the formula for F to C
	celsius_amount = (fahrenheit_amount - 32) * (5 / 9);

	return celsius_amount;
}
int UserSelectionValidate(int user_selection)
{
	std::cout << "Please enter your selection: ";
	std::cin >> user_selection;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nBad entry, no text allowed! Enter a Number: ";
		std::cin >> user_selection;
	}

	return user_selection;
}


// Initializing the function for restarting the program
std::string RestartFunction(std::string user_returntomenu)
{
	// WILL FILL OUT THIS CODE LAST ALSO WILL IS GAY AND LIKES PENIS
}

int main()
{
	int user_selection;
	double celsius_amount;
	double fahrenheit_amount;
	std::string user_returntomenu;

	std::cout << "Welcome to the Temperature Converter!\n\n";
	std::cout << "1. Convert Celsius to Fahrenheit\n";
	std::cout << "2. Convert Fahrenheit to Celsius\n";
	std::cout << "3. Exit program\n";

	UserSelectionValidate(user_selection);

	if (user_selection == 1)
	{
		CelstoFahr(celsius_amount, fahrenheit_amount);

		std::cout << "\n" << celsius_amount << " degrees Celsius is equal to " << fahrenheit_amount << " degrees Fahrenheit";

	}

    return 0;
}

