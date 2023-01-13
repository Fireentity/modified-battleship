#include "logger/ConsoleLogger.h"

void ConsoleLogger::log(const std::string &log) const {
    std::cout<<log;
}
