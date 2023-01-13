#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>
#include <memory>

class Command {
public:
    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Command(Command &command) = delete;

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Command &operator=(const Command &) = delete;

    Command();
    /**
     * Controlla se l'input viene accettato dal comando.
     * In questo gioco l'input del comando identifica il comando stesso in quando non sono presenti labels.
     * @param argument l'argomento del comando
     * @return ritorna true se il comando è eseguito con successo false altrimenti
     */
    virtual bool check_command(const std::string &argument) = 0;

    /**
     * Ritorna true se il comando viene correttamente eseguito altrimenti false.
     * @return ritorna true se il comando è eseguito con successo false altrimenti
     */
    virtual bool execute(const std::string &argument) = 0;
};


#endif //COMMAND_H
