/**
 * @file InputValidation.cpp
 * @brief Implements input validation and stream management utilities
 *
 * This file contains functions for validating user input, clearing input streams,
 * and ensuring proper data entry for the Substitution Cipher application.
 */

#include "InputValidation.h"

/**
 * @brief Clears the input stream of any errors and remaining characters
 *
 * Should be called after detecting invalid input to reset the stream state.
 */
void clearInput() {
	std::cin.clear();
	std::cin.ignore();
}

/**
 * @brief Gets a validated numeric input from the user for menu selection
 * @return The menu choice as an integer
 *
 * Validates that input is a number between 1-6. Displays error message
 * for invalid inputs.
 */
int getNumInput() {
	std::cout << "\nEnter your selection: ";
	int input{};
	std::cin >> input;

	if ((std::cin.fail()) || (!std::cin.fail() && input >= 7)) {
		clearInput();
		std::cout << "\nInvalid choice, please try again." << std::endl;
	}
	return input;
}

/**
 * @brief Gets a validated string input from the user
 * @return The user-entered text string (minimum 2 characters)
 *
 * Continues prompting until user enters at least 2 characters.
 */
std::string getStringInput() {

		clearInput();
		std::string userText{};
		std::cout << "Enter text: ";
		std::getline(std::cin, userText);

		while (userText.length() <= 1) {
			std::cout << "1 char entered, please verify your input. " << std::endl;
			std::getline(std::cin, userText);
		}
		return userText;

}

/**
 * @brief Validates and returns a 52-character encryption key from user input
 * @return A valid 52-character encryption key
 *
 * The key must be exactly 52 characters (26 lowercase + 26 uppercase).
 * Continues prompting until a valid key is entered.
 */
std::string validateKey() {
	clearInput();
	std::cout << "\nPlease enter your encryption key: ";
	std::string userKey{};
	std::getline(std::cin, userKey);


	while (userKey.length() != 52) {
		std::cout << "\nInvalid encryption key, please try again. \n";
		std::getline(std::cin, userKey);

		//REMEMBER TO DO GETLINE AFTER AN INVALID INPUT!
		//No need to clear input stream!
	}

	return userKey;
}

