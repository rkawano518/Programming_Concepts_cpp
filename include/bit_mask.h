/**
 * @file bit_mask.h
 * @brief Header file for Bit Mask concept.
 */
#ifndef BIT_MASK_H
#define BIT_MASK_H

namespace bit_mask {

    constexpr int BIT_SIZE = 4; /**< The amount of bits in the numbers that are processed */

    /**
     * @brief Sets the bits in the number based on the bits in the mask that are set to 1. Ignores 0s.
     * 
     * @param int The number to apply the mask to.
     * @param int The mask.
     * 
     * @return The result of the operation.
     */
    int setBits(const int, const int);

    /**
     * @brief Clears the bits in the number based on the specified bits in the mask that are set to 1. Ignores 0s.
     * 
     * @param int The number to apply the mask to.
     * @param int The mask.
     * 
     * @return The result of the operation.
     */
    int clearBits(const int, const int);

    /**
     * @brief Toggles the bits in the number based on the specified bits in the mask that are set to 1. Ignores 0s.
     * 
     * @param int The number to apply the mask to.
     * @param int The mask.
     * 
     * @return The result of the operation.
     */
    int toggleBits(const int, const int);

    /**
     * @brief Checks whether certain bits in the number are set based on the bits in the mask that are set to 1. Ignores 0s.
     * 
     * @param int The number to apply the mask to.
     * @param int The mask.
     * 
     * @return The result of the operation.
     */
    int checkBits(const int, const int);

    /**
     * @brief Utility function to print both the decimal and binary representation of a number.
     * 
     * @param int The number to print.
     * 
     * @return The string containing both representations in easy-to-read formatting.
     */
    std::string printDecimalAndBinaryRepresentation(const int);

    /**
     * @brief Demonstrates the Bit Mask concept.
     */
    void demonstration();

} // namespace bit_mask

#endif
