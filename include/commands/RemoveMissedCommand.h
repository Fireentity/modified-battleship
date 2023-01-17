//Lorenzo Croce 2034738

#ifndef REMOVEHITMISSCOMMAND_H
#define REMOVEHITMISSCOMMAND_H

#include "Command.h"
#include "board/Board.h"

class RemoveMissedCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    static const std::string commandFormat;

    bool check_command(const std::string &argument) override;

public:
    explicit RemoveMissedCommand(const std::shared_ptr<Board> &board);

    bool execute(const std::string &argument) override;
};

#endif //REMOVEHITMISSCOMMAND_H
