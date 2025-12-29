/**
 * @file InputValidation.h
 * @brief Header file for input validation utilities
 *
 * Contains declarations for functions that handle user input validation
 * and input stream management.
 */

#pragma once
#include <iostream>
#include <string>

/**
 * @brief Clears the input stream of any errors and remaining characters
 */
void clearInput();

/**
 * @brief Gets a validated numeric input from the user for menu selection
 * @return The menu choice as an integer (1-6)
 */
int getNumInput();

/**
 * @brief Gets a validated string input from the user
 * @return The user-entered text string
 */
std::string getStringInput();

/**
 * @brief Validates and returns a 52-character encryption key from user input
 * @return A valid 52-character encryption key
 */
std::string validateKey();


