#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>
#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "ship/Submarine.h"
#include "commands/Command.h"

/**
 * Astrae il giocatore umano, computer o il replay
 */
class Player {
protected:
    //vettore contenente tutte le istanze dei comandi eseguibili da un giocatore
    std::vector<std::shared_ptr<Command>> commands_;
    const std::shared_ptr<Board> board_;
    const std::shared_ptr<Board> enemy_board_;
public:
    /**
     *
     * @param board la board del giocatore
     * @param enemy_board la board dell'avversario
     */
    Player(const std::shared_ptr<Board> &board,const std::shared_ptr<Board> &enemy_board);

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Player(Player &) = delete;

    /**
     * Viene cancellato l'operatore di assegnazione per evitare lo slicing
     */
    Player &operator=(const Player &) = delete;

    /**
     *
     * @return ritorna un puntatore ad un oggetto const Board
     */
    std::shared_ptr<const Board> get_board() const;

    /**
     * Metodo che permette di posizionare le navi nella board
     */
    virtual void place_ships_inside_board() = 0;

    /**
     * Metodo per eseguire una mossa
     */
    virtual void do_move() = 0;

    /**
     * Metodo per registrare un comando eseguibile dal giocatore
     * @param command puntatore all'istanza del comando
     */
    void register_command(const std::shared_ptr<Command> &command);

    /**
     * Metodo che permette di eseguire un comando data la stringa in input
     * @param command stringa del comando da eseguire
     * @return ritorna true se il comando viene eseguito correttamente false altrimenti
     */
    bool dispatch_command(const std::string &command);
};

#endif //PLAYER_H
