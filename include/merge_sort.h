/**
 * @file merge_sort.h
 * @brief Header file for Merge Sort.
 */
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include "logger/log.h"

namespace merge_sort {

/**
 * @brief Recursive implementation of Merge Sort.
 * 
 * @param std::vector<int> The vector to sort.
 * @param int The first index of the left side.
 * @param int The last index of the right side.
 */
void mergeSortRecursive(std::vector<int>&, int, int);

/**
 * @brief This is the funcion that does the actual sorting and merging. It executes this on the
 * portion of the vector passed in (defined by the indicies passed in).
 * 
 * @param std::vector<int> The vector to sort.
 * @param int The first index of the left side.
 * @param int The index of the middle.
 * @param int The last index of the right side.
 */
void merge(std::vector<int>&, int, int, int);

/**
 * @brief Demonstrates the use of Merge Sort.
 */
void demonstration();

} // namespace merge_sort

#endif
