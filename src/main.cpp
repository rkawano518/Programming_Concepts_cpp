/**
 * @file main.cpp
 * @brief Main file to demonstrate various programming concepts.
 */
#include <thread>
#include "logger/log.h"
#include "binary_search.h"
#include "quick_sort.h"
#include "recursion.h"

LOG_SETUP

int main() {
    std::thread logThread = rk::log::startLogThread();
    LOG_VERIFY
    
    binary_search::demonstration();
    quick_sort::demonstration();
    recursion::demonstration();
    
    rk::log::endLogThread(logThread);

    return 0;
}
