// Challenge 3 - Temperature Converter (C to F/F to C)
// I will be practicing functions and passing variables in this Challenge
// by Jake R.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>

// Initializing the functions, with user input validation, for Cels -> Fahr, Fahr -> Cels and User Selection
double CelstoFahr(double celsius_amount, double fahrenheit_amount)
{
	std::cout << "\nPlease enter the amount to be converted to Fahrenheit: ";
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
	std::cout << "\nPlease enter the amount to be converted to Celsius: ";
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
	std::cout << "\nPlease enter your selection: ";
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

// Function to enable a pause at the end to avoid the use of system("pause")
void pauseAtEnd() {
	std::cout << "\n\nPlease press Enter to exit . . .";
	std::cin.sync();
	std::cin.get();
}

// Restart function to avoid having to re-write it all each time
void UserRestart()
{
	bool BOOL_RETURNTOMENU = true;
	std::string user_returntomenu;

	// Check if the player wishes to make another conversion or exit the program
	while (BOOL_RETURNTOMENU == true)
	{
		std::cout << "\nDo you wish to make another conversion? Y/N: ";
		std::cin >> user_returntomenu;
		std::cin.ignore();

		if (user_returntomenu == "Y" || user_returntomenu == "y" || user_returntomenu == "N" || user_returntomenu == "n")
		{
			if (user_returntomenu == "Y" || user_returntomenu == "y")
			{
				std::cin.clear();
				std::cin.ignore();
				main();
			}

			else
			{
				std::cout << "\nGoodbye";
				BOOL_RETURNTOMENU = false;
			}
		}

		else
		{
			std::cout << "\nBad Entry! Numbers not allowed! Please enter Y or N\n";
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

int main()
{
	int user_selection;
	double celsius_amount;
	double fahrenheit_amount;
	bool CONVERTER_RUNNING = true;

	while (CONVERTER_RUNNING == true)
	{
		std::cout << "Welcome to the Temperature Converter!\n\n";
		std::cout << "1. Convert Celsius to Fahrenheit\n";
		std::cout << "2. Convert Fahrenheit to Celsius\n";
		std::cout << "3. Exit program\n";

		UserSelectionValidate(user_selection);

		if (user_selection == 1)
		{
			// Run Celsius to Fahrenheit function and retrieve the values to cout here
			CelstoFahr(celsius_amount, fahrenheit_amount);

			// cout the amounts received from the function
			std::cout << "\n" << celsius_amount << " degrees Celsius is equal to " << fahrenheit_amount << " degrees Fahrenheit";

			UserRestart();
		}

		else if (user_selection == 2)
		{
			// Run Fahrenheit to Celsius function and retrieve the values to cout here
			FahrtoCels(celsius_amount, fahrenheit_amount);

			// cout the amounts received from the function
			std::cout << "\n" << fahrenheit_amount << " degrees Fahrenheit is equal to " << celsius_amount << " degrees Celsius";

			UserRestart();
		}

		else if (user_selection == 3)
		{
			std::cout << "\nGoodbye";
		}

		else
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nPlease enter a number between 1 and 3 for your selection!\n\n";
			UserSelectionValidate(user_selection);
		}

		CONVERTER_RUNNING = false;
	}

	pauseAtEnd();

    return 0;
}

