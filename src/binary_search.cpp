/**
 * @file binary_search.cpp
 * @brief Implementation file for demonstrating Binary Search.
 */
#include <vector>
#include <thread>
#include "binary_search.h"
#include "logger/log.h"
#include "utility.h"

namespace binary_search {

/**
 * Iterative version. Gets the middle index and compares the target value to it.
 * If they are the same value, then it will return the index.
 * If the mid is less than the target, it will search in the elements to the right of mid.
 * If the mid is greater than the target, it will search in the elements to the left of mid.
 * It will keep searching until it either finds the value or it cannot search anymore.
 */
int binarySearch(const std::vector<int>& list, int target) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Use this instead of high + low / 2 to prevent overflows with large numbers

        // Target was found
        if (list[mid] == target) {
            return mid;
        }
         // Search in the right half
        else if (list[mid] < target) {
            low = mid + 1; 
        }
        // Search in the left half
        else {
            high = mid - 1; 
        }
    }

    return -1; // Target not found
}

/**
 * Recursive version. 
 * Base case: When the target is found or it cannot divide the list anymore (low > high)
 * Recursive case: mid is less than the target. Search in the elements to the right of mid.
 * Recursive case: mid is greater than the target. Search in the elements to the left of mid.
 */
int binarySearchRecursive(const std::vector<int>& list, int target, int low, int high) {
    // Base case
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2; // Use this instead of high + low / 2 to prevent overflows with large numbers

    // Base case
    if (list[mid] == target) {
        return mid;
    }
    // Recursive case
    else if (list[mid] < target) {
        // Search in the right half
        return binarySearchRecursive(list, target, mid + 1, high);
    }
    // Recursive case
    else {
        // Search in the left half
        return binarySearchRecursive(list, target, low, mid - 1);
    }
}

/**
 * Starts with a sorted list and executes both the iterative and recursive versions of Binary Search
 * on the list.
 */
void demonstration() {
    utility::printSectionTitle("Binary Search");
    std::vector<int> sortedList = { 1, 4, 8, 23, 46, 400, 2364};

    LOG("Sorted array:\n");
    for (auto& i : sortedList) {
        LOG(i, "\n");
    }

    /*****************
    Iterative version
    *****************/
    LOG("Looking for 4 iteratively\n");
    int result = binarySearch(sortedList, 4);
    LOG("Result: ", ((result != -1) ? "found" : "not found"), "\n");
    
    LOG("Looking for 55 iteratively\n");
    result = binarySearch(sortedList, 55);
    LOG("Result: ", ((result != -1) ? "found" : "not found"), "\n");
    
    /*****************
    Recursive version
    *****************/
    LOG("Looking for 4 recursively\n");
    result = binarySearchRecursive(sortedList, 4, 0, sortedList.size() - 1);
    LOG("Result: ", ((result != -1) ? "found" : "not found"), "\n");
    
    LOG("Looking for 55 recursively\n");
    result = binarySearchRecursive(sortedList, 55, 0, sortedList.size() - 1);
    LOG("Result: ", ((result != -1) ? "found" : "not found"), "\n");
}

} // namespace binary_search
