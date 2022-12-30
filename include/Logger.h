#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <ostream>

class Logger {
private:
    std::string file_;
    std::fstream file_stream_;
public:
    Logger(const std::string &file_name);
    void log(const std::string &log);
};

#endif //LOGGER_H
