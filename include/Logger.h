#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>
class Logger {
private:
    std::string file_;
    std::fstream file_stream_;
public:
    explicit Logger(const std::string &file_name);
    void log_action(const std::string &log);
};

#endif //LOGGER_H
