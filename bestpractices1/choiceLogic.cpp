#include "InputValidation.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>


//Global for now until I find a better way for their values to be changed at any time...

	static const std::string abc			{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	static const std::string default_key	{ "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ"};
	std::string current_key					{ default_key };


	static std::string date_time() {
	time_t now								{ time(0) };
	char* date_time							{ ctime(&now) };
	return date_time;
}

//Key generator logic
std::string keyGenerator(std::string current_key) {
	std::string shuffledKey{ current_key };

	for (int i = current_key.length() - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		std::swap(shuffledKey[i], shuffledKey[j]);

		current_key = shuffledKey;
	}
	return shuffledKey;
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

// Menu option 1
std::string encrypt(std::string userString) { 

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

//Menu option 2
std::string decrypt(std::string userString) { 

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

//Menu option 3
void displayKey() { 
	std::cout << "\nThe current key is: " << std::string_view(current_key) << std::endl;
}

// Menu option 4
void generateNewKey() { 

	system("cls");
	
	//Generates a new key via keyGenerator (takes the current_key and generates a new key out of it)
	std::string newKey{ keyGenerator(current_key) };

	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "New key: " << std::endl;
	current_key = newKey;
	std::cout << current_key;
	std::cout << "\n\nDon't forget to copy this key.";
	std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

	char confirmChange{};

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
			current_key = newKey;
			return;
		}
		else if (confirmChange == 'n' || confirmChange == 'N') {
			clearInput();
			newKey.clear();
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

//Menu option 5
void changeCurrentKey() {
	current_key =  validateKey();
	std::cout << "New encryption key from user now in use.\n";
}
