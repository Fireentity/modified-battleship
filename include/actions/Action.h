//Lorenzo Croce 2034738

#ifndef ACTION_H
#define ACTION_H

#include <memory>
#include "board/BoardSlot.h"
#include "board/Board.h"

/**
 * La classe Action rappresenta un'azione eseguibile da una nave sulla Board. Spostare il codice nella classe Action
 * invece che tenerlo in Board causa una dipendenza circolare che però rende il codice più estendibile. Per implementare
 * un'azione non devo modificare la classe board ma basta implementare Action
 */
class Action {
protected:
    /**
     * Vengono utilizzati dei weak_ptr per evitare memory leak. Se due oggetti contengono uno lo shared_ptr dell'altro
     * si crea un memory leak che può essere risolto solo tramite l'uso di weak_ptr.
     */
    std::weak_ptr<Board> board_;
    std::weak_ptr<Board> enemy_board_;

public:
    /**
     *
     * @param board la board sulla quale eseguire l'azione
     * @param enemy_board la board del nemico
     */
    Action(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    /**
     * Viene cancellato il costruttore di copia per evitare lo slicing
     */
    Action(Action &) = delete;

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Action &operator=(const Action &) = delete;

    /**
     * Esegue un'azione generica su una delle due board o su entrambe
     * @param ship_center il centro della nave che deve eseguire l'azione
     * @param target il destinatario dell'azione
     * @return true se l'azione è andata a buon file false altrimenti
     */
    virtual bool do_action(const Point &ship_center, const Point &target) = 0;
};


#endif //ACTION_H
