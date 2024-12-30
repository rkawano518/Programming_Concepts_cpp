/**
 * @file bit_mask.cpp
 * @brief Source file for the Bit Mask concept.
 */
#include <bitset>
#include "bit_mask.h"
#include "logger/log.h"
#include "utility.h"

namespace bit_mask {

    /**
     * Applies the bit mask to binary_number using a bitwise OR operation. In C++, bitwise OR is "|".
     * 
     * Ex:
     * binary_number = 0001
     * mask = 0011
     * 
     * Everywhere that there is a 1 in the mask, it'll set the corresponding bit in binary_number to 1.
     * 
     * result = binary_number | mask = 0011
     */
    int setBits(const int binary_number, const int mask) {
        return binary_number | mask;
    }

    /**
     * Applies the bitwise NOT operation to the bit mask, then applies the mask to binary_number using a bitwise AND operation.
     * In C++, bitwise NOT is "~" and bitwise AND is "&".
     * The following example shows the process step-by-step, but the function actually does this all in one line.
     * 
     * Ex:
     * binary_number = 0001
     * mask = 0001
     * 
     * Everywhere that there is a 1 in the mask, it'll clear (or set to 0) the corresponding bit in binary_number.
     * It will first do a bitwise NOT on the mask.
     * 
     * ~mask = 1110
     * 
     * Then, it will do a bitwise AND.
     * 
     * result = binary_number & mask = 0001 & 1110 = 0000
     */
    int clearBits(const int binary_number, const int mask) {
        return binary_number & ~mask;
    }

    /**
     * Applies the bit mask to binary_number using a bitwise XOR operation. In C++, bitwise XOR is "^".
     * 
     * Ex:
     * binary_number = 0001
     * mask = 1011
     * 
     * Everywhere that there is a 1 in the mask, it'll toggle (or flip) the corresponding bit in binary_number.
     * 
     * result = binary_number ^ mask = 1010
     */
    int toggleBits(const int binary_number, const int mask) {
        return binary_number ^ mask;
    }

    /**
     * Applies the bit mask to binary_number using a bitwise AND operation. In C++, bitwise AND is "&".
     * 
     * Ex:
     * binary_number = 0001
     * mask = 0011
     * 
     * Everywhere that there is a 1 in the mask, it'll check whether the corresponding bit in binary_number is set.
     * 
     * result = binary_number & mask = 0001
     * If the result is not zero, then that means at least one of the bits in the mask was set in binary_number. If only
     * bit was set in the mask, then no further analysis is needed. But, if more than one bit was set in the mask, then in
     * order to check which actual bits are set in binary_number, the individual bits in the result need to be analyzed.
     */
    int checkBits(const int binary_number, const int mask) {
        return binary_number & mask;
    }

    /**
     * Any number that's passed in will be represented in decimal form due to C++'s standards. So, we convert the decimal number
     * to it's binary form with std::bitset.
     */
    std::string printDecimalAndBinaryRepresentation(const int number) {
        return "\tDecimal representation: " + std::to_string(number) + "\n\tBinary representation: " + std::bitset<BIT_SIZE>(number).to_string();
    }

    void demonstration() {
        utility::printSectionTitle("Bit Mask");

        int binaryNumber = 0b0100; // 4 in decimal
        LOG("Starting with an initial number:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\n");

        int mask = 0b0110;
        LOG("Setting bits on the num:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\nwith the mask:\n", printDecimalAndBinaryRepresentation(mask), "\n");
        binaryNumber = setBits(binaryNumber, mask);
        LOG("Result of setting bits:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\n");

        mask = 0b0100;
        LOG("Clearing bits on the num:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\nwith the mask:\n", printDecimalAndBinaryRepresentation(mask), "\n");
        binaryNumber = clearBits(binaryNumber, mask);
        LOG("Result of clearing bits:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\n");

        mask = 0b0110;
        LOG("Toggling bits on the num:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\nwith the mask:\n", printDecimalAndBinaryRepresentation(mask), "\n");
        binaryNumber = toggleBits(binaryNumber, mask);
        LOG("Result of toggling bits:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\n");

        mask = 0b0100;
        LOG("Checking bits on the num:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\nwith the mask:\n", printDecimalAndBinaryRepresentation(mask), "\n");
        int checkBitResult = checkBits(binaryNumber, mask);
        LOG("Result of checking bits:\n", printDecimalAndBinaryRepresentation(checkBitResult), "\n");
        if (checkBitResult) {
            LOG("The bit was set\n");
        }
        else {
            LOG("The bit wasn't set\n");
        }

        mask = 0b0010;
        LOG("Checking bits on the num:\n", printDecimalAndBinaryRepresentation(binaryNumber), "\nwith the mask:\n", printDecimalAndBinaryRepresentation(mask), "\n");
        checkBitResult = checkBits(binaryNumber, mask);
        LOG("Result of checking bits:\n", printDecimalAndBinaryRepresentation(checkBitResult), "\n");
        if (checkBitResult) {
            LOG("The bit was set\n");
        }
        else {
            LOG("The bit wasn't set\n");
        }
    }

} // namespace bit_mask
