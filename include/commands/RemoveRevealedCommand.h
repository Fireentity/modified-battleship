#ifndef REMOVEREVEALEDCOMMAND_H
#define REMOVEREVEALEDCOMMAND_H


#include "Command.h"

class RemoveRevealedCommand : public Command{
private:
    static const std::string commandFormat;
    bool check_command(const std::string &argument) override;
public:
    bool execute(const std::string &argument) override;
};


#endif //REMOVEREVEALEDCOMMAND_H
