/**
 * @file recursion.h
 * @brief Header file for recursion.
 */
#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <string>

namespace recursion {

/**
 * @brief Takes an integer and adds the digits recursively. ie. 123 -> 1 + 2 + 3.
 * 
 * @param int The integer to add the digits of.
 * 
 * @return The sum of the digits.
 */
int addDigits(int);

/**
 * @brief Reverse a string recursively. ie. Word -> droW.
 * 
 * @param std::string The string to reverse.
 * 
 * @return The reversed string.
 */
std::string reverseString(std::string);

/**
 * @brief Demonstrates the use of recursive functions.
 */
void demonstration();

} // namespace recursion

#endif
