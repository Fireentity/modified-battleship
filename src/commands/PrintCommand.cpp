//
// Created by albyb on 07/01/2023.
//

#include "commands/PrintCommand.h"
const std::string PrintCommand::commandFormat = "XX XX";

PrintCommand::PrintCommand(const std::shared_ptr<Board> &board) : board_{board}{

}

bool PrintCommand::execute(const std::string &argument) {
    if(check_command(argument)){
        std::cout<<(*board_);
        return true;
    } else {
        return false;
    }
}

bool PrintCommand::check_command(const std::string &argument) {
    return argument==commandFormat;
}

