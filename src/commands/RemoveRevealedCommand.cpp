#include "commands/RemoveRevealedCommand.h"

const std::string RemoveRevealedCommand::commandFormat = "AA AA";

bool RemoveRevealedCommand::execute(const std::string &argument) {
    board_->remove_state(BoardSlot::REVEALED);
    return true;
}

bool RemoveRevealedCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}

RemoveRevealedCommand::RemoveRevealedCommand(const std::shared_ptr<Board> &board) : Command{}, board_{board}{

}
