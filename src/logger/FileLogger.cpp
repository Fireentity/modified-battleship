#include "logger/FileLogger.h"

FileLogger::FileLogger(const std::string &file_name) : file_name_{file_name} {
    std::ofstream file_stream_{file_name_,std::ios::trunc};
    file_stream_.open(file_name_,std::ios::trunc);
    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }
    file_stream_.close();
}

const Logger & FileLogger::log(const std::string &log) const {
    std::ofstream file_stream_{file_name_,std::ios::app};
    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }

    file_stream_ << log;
    file_stream_.close();
    return *this;
}
