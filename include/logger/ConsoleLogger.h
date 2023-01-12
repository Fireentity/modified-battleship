#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"
#include <iostream>


class ConsoleLogger : public Logger {
public:
    ConsoleLogger();
    const Logger & log(const std::string &log) const override;
};

#endif //CONSOLELOGGER_H
