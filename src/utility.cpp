/**
 * @file utility.cpp
 * @brief Source file for various utility functions.
 */
#include "utility.h"

namespace utility {

    void printSectionTitle(const std::string sectionName) {
        LOG("\n");
        LOG("\n");
        LOG("****************************************************************\n");
        LOG("****************************************************************\n");
        LOG("STARTING SECTION: \"", sectionName, "\"\n");
        LOG("****************************************************************\n");
        LOG("****************************************************************\n");
        LOG("\n");
        LOG("\n");
    }

} // namespace utility
