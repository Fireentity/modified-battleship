#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    virtual void log(const std::string &log) const = 0;
    virtual std::ostream &operator<<(std::ostream &os) = 0;
};

#endif //LOGGER_H
