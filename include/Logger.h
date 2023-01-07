#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <iostream>
class Logger { //TODO il logger se scrivo a7 a9 mette a6 a8
private:
    std::string file_;
    std::fstream file_stream_;
public:
    explicit Logger(const std::string &file_name);
    void log_action(const std::string &log);
};

#endif //LOGGER_H
