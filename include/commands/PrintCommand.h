//Lorenzo Croce 2034738

#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include "Command.h"
#include "board/Board.h"
#include "logger/Logger.h"


class PrintCommand : public Command {
protected:
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Logger> logger_;
    bool check_command(const std::string &argument) override;

public:
    static const std::string commandFormat;

    PrintCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &info_logger);

    bool execute(const std::string &argument) override;
};


#endif //PRINTCOMMAND_H
