#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <memory>

class Command {
public:

    Command(Command &command) = delete;
    Command();

    //Controlla se l'input viene accettato dal comando.
    //In questo gioco l'input del comando identifica il comando stesso in quando non sono presenti labels.
    virtual bool check_command(const std::string &argument) = 0;

    //Ritorna true se il comando viene correttamente eseguito altrimenti false.
    virtual bool execute(const std::string &argument) = 0;

    Command &operator=(const Command &) = delete;
};


#endif //COMMAND_H
