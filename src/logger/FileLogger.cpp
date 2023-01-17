//Alberto Bottari 2034728

#include "logger/FileLogger.h"

/**
 *
 * @param file_name il nome del file sul quale loggare
 */
FileLogger::FileLogger(const std::string &file_name) : file_name_{file_name}, file_stream_{} {
    file_stream_.open(file_name_,std::ios::trunc);
    if(!file_stream_.is_open()) {
        file_stream_.close();
        throw std::invalid_argument("Cannot open file");
    }
}

/**
 * Logga la stringa in input
 * @param log la stringa da loggare
 */
Logger & FileLogger::log(const std::string &log) {
    file_stream_ << log;
    return *this;
}

FileLogger::~FileLogger() {
    file_stream_.close();
}
