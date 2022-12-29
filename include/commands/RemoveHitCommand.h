//
// Created by albyb on 29/12/2022.
//

#ifndef REMOVEHITCOMMAND_H
#define REMOVEHITCOMMAND_H


#include "Command.h"

class RemoveHitCommand : public Command{
private:
    static const std::string commandFormat;
    bool check_command(const std::string &argument) override;
public:
    RemoveHitCommand()
    bool execute(const std::string &argument) override;
};


#endif //REMOVEHITCOMMAND_H
