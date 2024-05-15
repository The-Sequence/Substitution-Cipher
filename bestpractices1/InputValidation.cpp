#include "InputValidation.h"

void clearInput() {
	std::cin.clear();
	std::cin.ignore();
}

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

std::string validateKey() {
	clearInput();
	std::cout << "\nPlease enter your encryption key: ";
	std::string userKey{};
	std::getline(std::cin, userKey);

	
	while (userKey.length() > 52 || userKey.length() < 52) {
		std::cout << "\nInvalid encryption key, please try again. \n";
		std::getline(std::cin, userKey);

		//REMEMBER TO DO GETLINE AFTER AN INVALID INPUT!
		//No need to clear input stream!
	}

	return userKey;
}

