/**
 * @file quick_sort.h
 * @brief Header file for Quick Sort algorithm.
 */
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <random>

namespace quick_sort {

/**
 * @brief Picks a random pivot index and partitions the array around the pivot.
 * 
 * @param arr The array to partition.
 * @param int The lower index of the array.
 * @param int The higher index of the array.
 * @param std::mt19937 The Mersenne Twister random generator object.
 * 
 * @return The index of the pivot.
 */
int partition(int arr[], const int, const int, std::mt19937&);

/**
 * @brief Executes Quick Sort recursively.
 * 
 * @param arr The array to sort.
 * @param int The lower index of the array.
 * @param int The higher index of the array.
 * @param std::mt19937 The Mersenne Twister random generator object.
 */
void quickSort(int arr[], const int, const int, std::mt19937&);

/**
 * @brief Demonstrates the Quick Sort algorithm.
 */
void demonstration();

} // namespace quick_sort

#endif
