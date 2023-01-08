#include "Logger.h"

Logger::Logger(const std::string &file_name): file_{file_name} {
    std::ofstream file_stream_{file_,std::ios::trunc};
    file_stream_.open(file_,std::ios::trunc);
    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }
    file_stream_.close();
}

void Logger::log_action(const std::string &log) {

    std::ofstream file_stream_{file_,std::ios::app};
    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }

    file_stream_ << log << std::endl;
    //TODO remove this
    std::cout<<log<<std::endl;

    file_stream_.close();
}
