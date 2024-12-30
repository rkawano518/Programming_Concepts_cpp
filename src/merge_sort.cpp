/**
 * @file merge_sort.cpp
 * @brief Source file for the Merge Sort algorithm.
 */
#include "merge_sort.h"

namespace merge_sort {

    /** 
     * Splits the vector around a middle index and keeps splitting until it can't split anymore i.e. there is only
     * one element (this is the base case). Once that is reached, it will start by sorting the single-element sub-vectors
     * and "merge" them together. Then, it'll do the same process with the resulting sub-vector. It'll keep doing this with
     * increasingly larger sub-vectors, as a result of the merging, until the vector is fully sorted.
     */
    void mergeSortRecursive(std::vector<int>& data, const int left, const int right) {
        LOG("Entered mergeSortRecursive\n");
        // Recursive case.
        if (left < right) {
            LOG("Recursive case\n");
            // Calculate middle index
            const int mid = left + (right - left) / 2; // Calculation is done this way to prevent overflows with large values.
            LOG("mid is ", mid, "\n");

            mergeSortRecursive(data, left, mid); // Left half
            mergeSortRecursive(data, mid + 1, right); // Right half

            merge(data, left, mid, right);
        }
        // Implicit base case. This "else" block is left here for demonstration purposes. Remove it during normal use.
        else {
            LOG("Base case reached\n");
        }
    }

    /**
     * Creates temporary vectors to hold the two sides. This operation makes it NOT an in-place sorthing algorithm, since it creates copies.
     * Iterates through each side and compares elements with a simple "less than or equal to" condition. If this condition is true, it inserts
     * the element in its correct position in the main vector. It does this until one or both sides are exhausted. At the end, if there are any
     * elements remaining, it simply copies them back into the main vector. The result is that the portion of the vector defined by the indices
     * passed in, is sorted.
     */
    void merge(std::vector<int>& data, const int left, const int mid, const int right) {
        // Calculate sizes of left and right side
        const size_t left_size = mid - left + 1;
        const size_t right_size = right - mid;

        // Copy the data from each side into temporary containers
        std::vector<int> leftData(left_size);
        std::vector<int> rightData(right_size);
        for (size_t i = 0; i < left_size; i++) {
            leftData[i] = data[left + i];
        }
        for (size_t j = 0; j < right_size; j++) {
            rightData[j] = data[mid + j + 1];
        }

        size_t i = 0; /**< Index for the temporary left-side vector */
        size_t j = 0; /**< Index for the temporary right-side vector */
        size_t k = left; /**< Index for inserting sorted elements back into the main vector */

        // Compare elements from each side and if one is less than or equal to the other, insert them back into the main vector.
        // Keep going until either side is exhausted.
        while (i < left_size && j < right_size) {
            if (leftData[i] <= rightData[j]) {
                data[k] = leftData[i];
                i++;
            }
            else {
                data[k] = rightData[j];
                j++;
            }
            k++;
        }

        // We can simply copy the rest of the remaining elements, if any, into the main vector. The two halves were already sorted relative to itself to
        // begin with, and after the elements were processed in the previous step, we are left with two sides that can simply be copied back into the main
        // vector.

        // If elements still exist in the left side, copy them into the main vector.
        while (i < left_size) {
            data[k] = leftData[i];
            i++;
            k++;
        }

        // If elements still exist in the right side, copy them into the main vector.
        while (j < right_size) {
            data[k] = rightData[j];
            j++;
            k++;
        }
    }

    void demonstration() {
        LOG("Starting Merge Sort demonstration\n");

        std::vector<int> data = { 42, 17, 89, 56, 23, 74, 31, 98, 15, 67, 8, 29, 60, 77, 91, 34, 3, 50, 12, 85 };
        std::string unsortedData;
        for (auto i : data) {
            unsortedData += std::to_string(i) + ", ";
        }
        unsortedData = unsortedData.substr(0, unsortedData.size() - 2);
        LOG("Unsorted vector size: ", data.size(), ".\nUnsorted vector contents:", unsortedData, "\n");

        LOG("Sorting the data using Merge Sort\n");
        mergeSortRecursive(data, 0, data.size() - 1);

        std::string sortedData;
        for (auto i : data) {
            sortedData += std::to_string(i) + ", ";
        }
        sortedData = sortedData.substr(0, sortedData.size() - 2);
        LOG("Sorted vector size: ", data.size(), ".\nSorted vector contents:", sortedData, "\n");
    }

} // namespace merge_sort