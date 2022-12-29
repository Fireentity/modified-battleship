//
// Created by albyb on 28/12/2022.
//

#include "commands/RemoveRevealedCommand.h"

const std::string RemoveRevealedCommand::commandFormat = "AA AA";

bool RemoveRevealedCommand::execute(const std::string &argument) {

    return false;
}

bool RemoveRevealedCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}
