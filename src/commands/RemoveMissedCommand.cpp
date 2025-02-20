//Lorenzo Croce 2034738

#include "commands/RemoveMissedCommand.h"

const std::string RemoveMissedCommand::commandFormat = "CC CC";

bool RemoveMissedCommand::execute(const std::string &argument) {
    board_->remove_state(BoardSlot::HIT_MISSED);
    return true;
}

bool RemoveMissedCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}

RemoveMissedCommand::RemoveMissedCommand(const std::shared_ptr<Board> &board) : Command{}, board_{board} {

}
