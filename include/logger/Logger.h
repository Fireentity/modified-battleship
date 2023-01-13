#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    Logger() = default;

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Logger(Logger &) = delete;

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Logger &operator=(const Logger &) = delete;

    /**
     * Logga la stringa in input
     * @param log la stringa da loggare
     */
    virtual const Logger & log(const std::string &log) const = 0;
};

#endif //LOGGER_H
