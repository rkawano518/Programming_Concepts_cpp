/**
 * @file recursion.cpp
 * @brief Implementation file for demonstrating Recursion.
 */
#include <thread>
#include "recursion.h"
#include "logger/log.h"
#include "utility.h"

namespace recursion {

/**
 * Adds the digits of num in reverse order. Utilizes Modulo operator to get the number
 * in the 1s spot. Keeps reducing num by a factor of 10 until it cannot be reduced anymore.
 * Base case: num is less than 10, so it cannot be reduced anymore.
 * Recursive case: num is greater than or equal to 10, so extract the digit in the 1s spot,
 * reduce num by a factor of 10, and continue adding.
 */
int addDigits(int num) {
    // Base case
    if (num < 10) {
        return num;
    }

    // Recursive case
    return (num % 10) + addDigits(num / 10);
}

/**
 * Utilizes std::string::substr() method to get the last character of a string, then
 * recursively processes the remaining string.
 * Base case: The size of the string is less than or equal to one. That means we've
 * reached the last character of the string.
 * Recursive case: The size of the string is greater than 1. That means there are still
 * character in the string to process. Extract the last character and recursively
 * process the rest of the string.
 */
std::string reverseString(std::string s) {
    const size_t SIZE = s.size();
    // Base case
    if (SIZE <= 1) {
        return s;
    }

    // Recursive case
    return s.substr(SIZE - 1) + reverseString(s.substr(0, SIZE - 1));
}

/**
 * Demonstrates recursion by calling the recursive functions in this namespace. 
 */
void demonstration() {
    utility::printSectionTitle("Recursion");
    
    // Add digits of an integer
    const int digits = 15827;
    LOG("Adding the digits: ", digits, "\n");
    const int result = addDigits(digits);
    LOG("Result: ", result, "\n");

    // Reverse a string
    const std::string str = "Hello Friend";
    LOG("Reversing: \"", str, "\"\n");
    const std::string reversed = reverseString(str);
    LOG("Result: \"", reversed, "\"\n");
}

} // namespace recursion
