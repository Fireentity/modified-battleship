//Lorenzo Croce 2034738

#ifndef REMOVEHITCOMMAND_H
#define REMOVEHITCOMMAND_H

#include "Command.h"
#include "board/Board.h"

class RemoveHitCommand : public Command {
private:
    const std::shared_ptr<Board> board_;
    bool check_command(const std::string &argument) override;

public:
    static const std::string commandFormat;
    explicit RemoveHitCommand(const std::shared_ptr<Board> &board);

    bool execute(const std::string &argument) override;

};

#endif //REMOVEHITCOMMAND_H
