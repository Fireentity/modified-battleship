//Alberto Bottari 2034728

#ifndef SHIPACTIONCOMMAND_H
#define SHIPACTIONCOMMAND_H

#include "ShipCommand.h"

class ShipActionCommand : public ShipCommand {
private:
    std::function<void()> execute_then_;
public:
    /**
     * Viene passata una function come parametro per permettere di eseguire codice senza dependency injection di Game.
     * Un uso in questo caso potrebbe essere il cambio al turno successivo una volta che il comando è eseguito con
     * successo. Sarebbe difficile passare un'istanza della classe Game in quanto bisognerebbe usare una reference o un
     * puntatore con conseguente rischio di accedere a memoria già liberata. Passare uno shared_ptr diventa impossibile
     * perché non si può ottenere uno shared_ptr di un'istanza dall'interno della stessa.
     * In questo modo si evita anche l'esposizione di metodi setter che possono modificare lo stato interno Game
     * @param board la board sulla quale eseguire il comando
     * @param logger il logger del comando
     * @param execute_then la funzione che viene eseguita quando il comando è eseguito con successp
     */
    ShipActionCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Logger> &logger,
                      const std::function<void()> &execute_then);

    bool execute_action(const Point &ship_center, const Point &target) override;
};

#endif //SHIPACTIONCOMMAND_H
