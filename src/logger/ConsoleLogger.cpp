#include "logger/ConsoleLogger.h"

/**
 * Logga la stringa in input
 * @param log la stringa da loggare
 */
const Logger & ConsoleLogger::log(const std::string &log) const {
    std::cout<<log;
    return *this;
}
