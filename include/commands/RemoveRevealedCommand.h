#ifndef REMOVEREVEALEDCOMMAND_H
#define REMOVEREVEALEDCOMMAND_H

#include "Command.h"
#include "board/Board.h"

class RemoveRevealedCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    static const std::string commandFormat;

    bool check_command(const std::string &argument) override;

public:
    explicit RemoveRevealedCommand(const std::shared_ptr<Board> &board);

    bool execute(const std::string &argument) override;
};

#endif //REMOVEREVEALEDCOMMAND_H
