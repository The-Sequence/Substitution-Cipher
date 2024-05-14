#include "InputValidation.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>


//Global for now until I find a better way for their values to be changed at any time...

static const std::string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string default_key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";
std::string current_key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";


static std::string date_time() {
	time_t now = time(0);
	char* date_time = ctime(&now);
	return date_time;
}

//Generates a text file and stores the following...
static void saveChatHistory(std::string current_key, std::string encryptedString, std::string unencryptedString) {
	std::ofstream("Chat History.txt", std::ios::app) 
				<< "\nCurrent time: " << std::string_view (date_time())
				<< "\nEncryption key: " << std::string_view (current_key) 
				<< "\nPlaintext: " << std::string_view(unencryptedString)
				<< "\n\nEncrypted message: " << std::string_view(encryptedString)
				<< "\n- - - - - - - - - -" << std::endl;
}

std::string encrypt(std::string userString) { // Menu option 1

	std::string encryptedString{};

	if (userString.length() >= 1) {
		for (char current_letter : userString) {
			size_t letter_position{ abc.find(current_letter) };

			if (letter_position != std::string::npos) {
				char new_char{ current_key.at(letter_position) };
				encryptedString += new_char;
			}
			else {
				encryptedString += current_letter;
			}
		}
	}
	saveChatHistory(current_key, encryptedString, userString);
	std::cout << "Encrypted text: " << std::endl;
	return encryptedString;
}

std::string decrypt(std::string userString) { //Menu option 2

	std::string decryptedString{};

	if (userString.length() >= 1) {
		for (char current_letter : userString) {
			size_t letter_position{ current_key.find(current_letter) };

			if (letter_position != std::string::npos) {
				char new_char{ abc.at(letter_position) };
				decryptedString += new_char;
			}
			else {
				decryptedString += current_letter;
			}

		}
	}
	saveChatHistory(current_key, userString, decryptedString);
	std::cout << "Decrypted text: " << std::endl;
	return decryptedString;
}

void displayKey() { //Menu option 3
	std::cout << "\nThe current key is: " << std::string_view(current_key) << std::endl;
}



void generateNewKey() { // Menu option 4
	std::string shuffledKey{ default_key };
	char confirmChange{};

	system("cls");
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "New key: " << std::endl;

	// IDEA: Make an independent generateNewKey function that handles the actual generation of a new key
	// then use changeKey function (taking output from generateNewKey) to replace the current_key.

	for (int i = current_key.length() - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		std::swap(shuffledKey[i], shuffledKey[j]);

		current_key = shuffledKey;
	}

	std::cout << current_key;

	std::cout << "\n\nDon't forget to copy this key.";
	std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

	//while (true) can be "exited" by using return.
	while (true) {
		std::cout << "\n\nSet this as the default key for this current session?\n"
			<< "\n(Y / N): ";
		std::cin >> confirmChange;

		if (confirmChange == 'y') {
			clearInput();
			std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -\n";
			std::cout << "\n - Key has been set. - \n";
			current_key.clear();
			current_key = shuffledKey;
			return;
		}
		else if (confirmChange == 'n' || confirmChange == 'N') {
			clearInput();
			shuffledKey.clear();
			std::cout << "Encryption key unchanged.\n";
			return;
		}
		else {
			//NO NEED TO DO RETURN HERE! DOING SO WILL TERMINATE THE WHILE LOOP!!!
			clearInput();
			std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -\n";
			std::cout << "\nInvalid char received. Please try again.\n";
			std::cout << "\nNew key: \n";
			std::cout << current_key;
		}
	}
}

