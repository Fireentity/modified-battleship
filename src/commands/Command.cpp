#include "commands/Command.h"

std::vector<std::shared_ptr<Command>> Command::commands = std::vector<std::shared_ptr<Command>>{};

bool Command::dispatch(const std::string &input) {
    if(check_command(input)) {
        return execute(input);
    }

    return false;
}

void Command::register_command(const std::shared_ptr<Command> &command) {
    Command::commands.push_back(command);
}

Command::Command() = default;
