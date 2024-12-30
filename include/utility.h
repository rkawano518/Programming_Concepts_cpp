/**
 * @file utility.h
 * @brief Source file for utility functions.
 */
#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "logger/log.h"

namespace utility {
    
    /**
     * @brief Prints a large, formatted title for easy-finding in the logs.
     * 
     * Call this before every section.
     * 
     * @param std::string The name of the section.
     */
    void printSectionTitle(const std::string);

} // namespace utility

#endif