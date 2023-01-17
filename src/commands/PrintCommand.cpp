//Lorenzo Croce 2034738

#include "commands/PrintCommand.h"

const std::string PrintCommand::commandFormat = "XX XX";

PrintCommand::PrintCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &info_logger)
        : board_{board}, logger_{info_logger} {

}

bool PrintCommand::execute(const std::string &argument) {
    if (check_command(argument)) {
        logger_->log(board_->to_string()).log("\n");
        return true;
    } else {
        return false;
    }
}

bool PrintCommand::check_command(const std::string &argument) {
    return argument == commandFormat;
}

