#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"
#include <iostream>


class ConsoleLogger : public Logger {
public:
    Logger & log(const std::string &log) override;
};

#endif //CONSOLELOGGER_H
