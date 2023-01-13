#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger {
private:
    const std::string file_name_;
public:
    /**
     *
     * @param file_name il nome del file sul quale loggare
     */
    explicit FileLogger(const std::string &file_name);

    const Logger & log(const std::string &log) const override;
};

#endif //FILELOGGER_H
