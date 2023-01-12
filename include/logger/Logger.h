#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    virtual const Logger & log(const std::string &log) const = 0;
    Logger() = default;
    Logger(Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
};

#endif //LOGGER_H
