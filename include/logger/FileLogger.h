#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger {
private:
    const std::string file_name_;
public:
    explicit FileLogger(const std::string &file_name);
    void log(const std::string &log) const override;
};

#endif //FILELOGGER_H
