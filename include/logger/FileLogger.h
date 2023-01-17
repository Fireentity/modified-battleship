#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger {
private:
    const std::string file_name_;
    std::ofstream file_stream_;
public:
    /**
     *
     * @param file_name il nome del file sul quale loggare
     */
    explicit FileLogger(const std::string &file_name);

    virtual ~FileLogger();

    Logger & log(const std::string &log) override;
};

#endif //FILELOGGER_H
