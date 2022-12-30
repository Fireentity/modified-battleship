#include <fstream>
#include "Logger.h"

Logger::Logger(const std::string &file_name): file_{file_name}, file_stream_{file_name} {

}

void Logger::log(const std::string &log) {
    file_stream_.open(file_,std::ios::app);

    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }

    file_stream_ << log << std::endl;
    file_stream_.close();
}
