//Lorenzo Croce 2034738

#ifndef REMOVEHITCOMMAND_H
#define REMOVEHITCOMMAND_H

#include "Command.h"
#include "board/Board.h"

class RemoveHitCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    static const std::string commandFormat;

    bool check_command(const std::string &argument) override;

public:
    explicit RemoveHitCommand(const std::shared_ptr<Board> &board);

    bool execute(const std::string &argument) override;

};

#endif //REMOVEHITCOMMAND_H
