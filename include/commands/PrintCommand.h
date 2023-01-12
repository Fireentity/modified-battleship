#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include "Command.h"
#include "board/Board.h"
#include "logger/Logger.h"


class PrintCommand : public Command {
protected:
    bool check_command(const std::string &argument) override;
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Logger> logger_;
    static const std::string commandFormat;
public:
    PrintCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &logger);
    bool execute(const std::string &argument) override;
};


#endif //PRINTCOMMAND_H
