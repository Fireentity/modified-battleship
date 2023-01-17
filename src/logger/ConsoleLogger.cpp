//Alberto Bottari 2034728

#include "logger/ConsoleLogger.h"

Logger &ConsoleLogger::log(const std::string &log) {
    std::cout << log;
    return *this;
}
