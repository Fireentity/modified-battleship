//
// Created by albyb on 29/12/2022.
//

#ifndef REMOVEHITMISSCOMMAND_H
#define REMOVEHITMISSCOMMAND_H


#include "Command.h"

class RemoveHitMissCommand : public Command{
private:
    static const std::string commandFormat;
    bool check_command(const std::string &argument) override;
public:
    bool execute(const std::string &argument) override;
};


#endif //REMOVEHITMISSCOMMAND_H
