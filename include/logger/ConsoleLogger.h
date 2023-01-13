#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"
#include <iostream>


class ConsoleLogger : public Logger {
public:
    void log(const std::string &log) const override;
};

#endif //CONSOLELOGGER_H
