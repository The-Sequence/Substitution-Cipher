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

