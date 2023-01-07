#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H


#include "Command.h"
#include "board/Board.h"

class PrintCommand : public Command {
protected:
    bool check_command(const std::string &argument) override;
    const std::shared_ptr<Board> board_;
    static const std::string commandFormat;
public:
    explicit PrintCommand(const std::shared_ptr<Board> &board);
    bool execute(const std::string &argument) override;
};


#endif //PRINTCOMMAND_H
