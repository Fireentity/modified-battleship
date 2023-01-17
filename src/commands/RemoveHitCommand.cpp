//Lorenzo Croce 2034738

#include "commands/RemoveHitCommand.h"

const std::string RemoveHitCommand::commandFormat = "BB BB";

bool RemoveHitCommand::execute(const std::string &argument) {
    board_->remove_state(BoardSlot::HIT);
    return true;
}

bool RemoveHitCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}

RemoveHitCommand::RemoveHitCommand(const std::shared_ptr<Board> &board): board_{board} {

}