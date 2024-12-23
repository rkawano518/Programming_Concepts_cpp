/**
 * @file binary_search.h
 * @brief Header file for Binary Search.
 */
#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

namespace binary_search {

/**
 * @brief Executes binary search iteratively on an std::vector.
 * 
 * @param std::vector<int> The vector to search.
 * @param int The value to search for.
 * 
 * @return The index in the vector where the value was found. If the value wasn't found,
 * it returns -1.
 */
int binarySearch(const std::vector<int>&, int);

/**
 * @brief Executes binary search recursively on an std::vector.
 * 
 * @param std::vector<int> The vector to search.
 * @param int The value to search for.
 * @param int The lowest index of the vector.
 * @param int The highest index of the vector.
 * 
 * @return Ultimately returns the index in the vector where the value was found. If
 * the value wasn't found, it returns -1.
 */
int binarySearchRecursive(const std::vector<int>&, int, int, int);

/**
 * @brief Demonstrates the use of Binary Search.
 */
void demonstration();

} // namespace binary_search

#endif
