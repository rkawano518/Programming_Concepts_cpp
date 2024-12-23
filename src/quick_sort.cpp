/**
 * @file quick_sort.cpp
 * @brief Implementation file for demonstrating Quick Sort.
 */
#include "quick_sort.h"
#include "logger/log.h"

namespace quick_sort {

/**
 * Chooses a random pivot by using the std::mt19937 that was passed in. Moves everything less
 * than or equal to the pivot, to the left of the pivot.
 */
int partition(int arr[], const int low, const int high, std::mt19937& gen) {
    std::uniform_int_distribution<> dist(low, high); // Random integer between low and high
    const int pivotIdx = dist(gen);
    std::swap(arr[pivotIdx], arr[high]); // Move pivot to the end temporarily
    const int pivot = arr[high];
    int i = low - 1; // For tracking the position of lower numbers

    // Go through array and move numbers less than or equal to the pivot, to the left of pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Move pivot to its correct position
    std::swap(arr[i + 1], arr[high]);

    // Return pivot index
    return i + 1;
}

 /**
  * Calls partition to split the array around a pivot. Recursively calls quickSort
  * again with the two halves of the partitioned array.
  * Base case: low is equal to high, which means there is only 1 element, which means
  * it cannot be sorted anymore.
  * Recursive case: low is less than high, meaning there is more than 1 element, which
  * means it can be sorted still. Partitions that section of the array and recursively
  * calls quickSort() again with the two halves.
  */
void quickSort(int arr[], const int low, const int high, std::mt19937& gen) {
    // Recursive case. If low is less than high, than there is more than 1 element,
    // which means it needs to be sorted
    if (low < high) {
        const int pivotIndex = partition(arr, low, high, gen);

        // Recursively sort the two halves
        quickSort(arr, low, pivotIndex - 1, gen); // Left of pivot
        quickSort(arr, pivotIndex + 1, high, gen); // Right of pivot
    }
    // Implicit base case. This "else" block is left here for demonstration purposes.
    // Remove it in actual use
    else { 
        LOG("Base case reached\n");
    }
}

/**
 * Prints an unsorted list of numbers, sorts it with Quick Sort, then prints the sorted result.
 */
void demonstration() {
    LOG("Starting quick sort demonstration\n");

    // Unsorted array of numbers
    int arr[] = {
        23, 87, 12, 45, 39, 94, 68, 33, 7, 56,
        78, 29, 11, 50, 67, 22, 99, 83, 16, 44,
        62, 30, 21, 73, 88, 14, 95, 41, 10, 38,
        57, 80, 61, 3, 71, 26, 90, 15, 47, 19,
        5, 34, 81, 8, 96, 53, 25, 66, 48, 6
    };
    constexpr size_t SIZE = sizeof(arr) / sizeof(arr[0]);
    
    LOG("Before sorting:\n");
    std::string beforeSort = "";
    for (size_t i = 0; i < SIZE; i++) {
        beforeSort += (std::to_string(arr[i]) + ", ");
    }
    beforeSort = beforeSort.substr(0, beforeSort.size() - 2);
    LOG(beforeSort, "\n");

    // Sort the array
    std::random_device rd;
    std::mt19937 gen(rd());
    quickSort(arr, 0, SIZE - 1, gen);

    LOG("After sorting:\n");
    std::string afterSort = "";
    for (size_t i = 0; i < SIZE; i++) {
        afterSort += (std::to_string(arr[i]) + ", ");
    }
    afterSort = afterSort.substr(0, afterSort.size() - 2);
    LOG(afterSort, "\n");
}

} // namespace quick_sort
