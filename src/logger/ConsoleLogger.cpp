#include "logger/ConsoleLogger.h"

const Logger & ConsoleLogger::log(const std::string &log) const {
    std::cout<<log;
    return *this;
}
