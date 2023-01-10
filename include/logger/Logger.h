#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {

    virtual void log(const std::string &log) const = 0;
};

#endif //LOGGER_H
