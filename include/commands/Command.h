#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <memory>

class Command {
private:
    static std::vector<std::shared_ptr<Command>> commands;
protected:
    virtual bool check_command(const std::string &argument) = 0;

public:
    Command(Command &command) = delete;

    Command();

    static void register_command(const std::shared_ptr<Command> &command);

    bool dispatch(const std::string &input);

    virtual bool execute(const std::string &argument) = 0;

    Command &operator=(const Command &) = delete;
};


#endif //COMMAND_H
