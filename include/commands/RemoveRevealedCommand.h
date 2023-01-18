//Lorenzo Croce 2034738

#ifndef REMOVEREVEALEDCOMMAND_H
#define REMOVEREVEALEDCOMMAND_H

#include "Command.h"
#include "board/Board.h"

class RemoveRevealedCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    bool check_command(const std::string &argument) override;

public:
    static const std::string commandFormat;

    explicit RemoveRevealedCommand(const std::shared_ptr<Board> &board);

    bool execute(const std::string &argument) override;
};

#endif //REMOVEREVEALEDCOMMAND_H
