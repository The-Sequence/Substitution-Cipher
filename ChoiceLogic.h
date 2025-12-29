/**
 * @file ChoiceLogic.h
 * @brief Header file for encryption/decryption logic and menu options
 *
 * Contains declarations for the core cipher functions used in the
 * Substitution Cipher application.
 */

#pragma once
#include <string>

/**
 * @brief Encrypts a string using the current substitution key
 * @param userString The plaintext string to encrypt
 * @return The encrypted string
 */
std::string encrypt(const std::string& userString);

/**
 * @brief Decrypts a string using the current substitution key
 * @param userString The encrypted string to decrypt
 * @return The decrypted plaintext string
 */
std::string decrypt(const std::string& userString);

/**
 * @brief Displays the current encryption key to the console
 */
void displayKey();

/**
 * @brief Generates a new encryption key and optionally sets it as current
 */
void generateNewKey();

/**
 * @brief Allows user to input and set a custom encryption key
 */
void changeCurrentKey();
