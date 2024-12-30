/**
 * @file utility.cpp
 * @brief Source file for various utility functions.
 */
#include "utility.h"

namespace utility {

    void printSectionTitle(const std::string sectionName) {
        std::string output;
        output += "\n";
        output += "\n";
        output += "****************************************************************\n";
        output += "****************************************************************\n";
        output += "STARTING SECTION: \"" + sectionName + "\"\n";
        output += "****************************************************************\n";
        output += "****************************************************************\n";
        output += "\n";
        LOG(output);
    }

} // namespace utility
