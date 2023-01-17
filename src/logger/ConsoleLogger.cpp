#include "logger/ConsoleLogger.h"

/**
 * Logga la stringa in input
 * @param log la stringa da loggare
 */
Logger &ConsoleLogger::log(const std::string &log) {
    std::cout << log;
    return *this;
}
