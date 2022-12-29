//
// Created by albyb on 29/12/2022.
//

#include "commands/RemoveHitCommand.h"
#include "actions/RemoveHitAction.h"

const std::string RemoveHitCommand::commandFormat = "BB BB";

bool RemoveHitCommand::execute(const std::string &argument) {
    if(check_command(argument)){
        RemoveHitAction a();
    }
}

bool RemoveHitCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}