#include "commands/RemoveHitMissCommand.h"

const std::string RemoveHitMissCommand::commandFormat = "CC CC";

bool RemoveHitMissCommand::execute(const std::string &argument) {
    return false;
}

bool RemoveHitMissCommand::check_command(const std::string &argument) {
    return commandFormat == argument;
}
