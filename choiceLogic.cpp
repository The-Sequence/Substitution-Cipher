/**
 * @file choiceLogic.cpp
 * @brief Implements encryption/decryption logic and menu options for the Substitution Cipher
 *
 * This file contains the core cipher logic including key generation, encryption,
 * decryption, and key management functions.
 */

#include "InputValidation.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <cstdlib>


//Global for now until I find a better way for their values to be changed at any time...

	static const std::string abc			{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	static const std::string default_key	{ "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ"};
	std::string current_key					{ default_key };

/**
 * @brief Cross-platform function to clear the console screen
 *
 * Uses system("cls") on Windows and system("clear") on macOS/Linux.
 */
static void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/**
 * @brief Gets the current date and time as a string
 * @return String representation of current date/time
 */
static std::string date_time() {
	time_t now								{ time(nullptr) };
	char* date_time_str						{ ctime(&now) };
	return date_time_str;
}

/**
 * @brief Generates a shuffled key using Fisher-Yates algorithm
 * @param key_to_shuffle The key to use as basis for shuffling
 * @return A new shuffled key
 */
std::string keyGenerator(const std::string& key_to_shuffle) {
	std::string shuffledKey{ key_to_shuffle };

	// Use C++11 random library for better randomness
	std::random_device rd;
	std::mt19937 gen(rd());

	for (size_t i = shuffledKey.length() - 1; i > 0; i--) {
		std::uniform_int_distribution<size_t> dis(0, i);
		size_t j = dis(gen);
		std::swap(shuffledKey[i], shuffledKey[j]);
	}
	return shuffledKey;
}

/**
 * @brief Saves chat history to a text file
 * @param key The encryption key used
 * @param encryptedString The encrypted message
 * @param unencryptedString The original plaintext message
 */
static void saveChatHistory(const std::string& key, const std::string& encryptedString, const std::string& unencryptedString) {
	std::ofstream("Chat History.txt", std::ios::app)
				<< "\nCurrent time: " << std::string_view (date_time())
				<< "\nEncryption key: " << std::string_view (key)
				<< "\nPlaintext: " << std::string_view(unencryptedString)
				<< "\n\nEncrypted message: " << std::string_view(encryptedString)
				<< "\n- - - - - - - - - -" << std::endl;
}

/**
 * @brief Encrypts a string using the current substitution key (Menu option 1)
 * @param userString The plaintext string to encrypt
 * @return The encrypted string
 */
std::string encrypt(const std::string& userString) {

	std::string encryptedString{};

	if (!userString.empty()) {
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

/**
 * @brief Decrypts a string using the current substitution key (Menu option 2)
 * @param userString The encrypted string to decrypt
 * @return The decrypted plaintext string
 */
std::string decrypt(const std::string& userString) {

	std::string decryptedString{};

	if (!userString.empty()) {
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

/**
 * @brief Displays the current encryption key (Menu option 3)
 */
void displayKey() {
	std::cout << "\nThe current key is: " << std::string_view(current_key) << std::endl;
}

/**
 * @brief Generates a new encryption key and optionally sets it (Menu option 4)
 */
void generateNewKey() {

	clearScreen();

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

		if (confirmChange == 'y' || confirmChange == 'Y') {
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

/**
 * @brief Allows user to change the current encryption key (Menu option 5)
 */
void changeCurrentKey() {
	current_key =  validateKey();
	std::cout << "New encryption key from user now in use.\n";
}
