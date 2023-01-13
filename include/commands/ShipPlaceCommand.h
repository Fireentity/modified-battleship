#ifndef SHIPPLACECOMMAND_H
#define SHIPPLACECOMMAND_H

#include "ShipCommand.h"
#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "ship/Submarine.h"

class ShipPlaceCommand : public ShipCommand {
private:

    /**
     * Rappresenta il tipo di navi disponibili nella flotta di ciascun giocatore
     */
    enum Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };

    int index_;
    std::shared_ptr<Board> enemy_board_;

public:
    static const std::vector<Ships> availableShips;

    /**
     * Associa ad ogni tipo di nave una stringa. Poteva essere implementato anche con una mappa statica
     * e avrebbe avuto complessità O(1) ma lo si è ritenuto inutile
     * @param ship il tipo di nave di cui ottenere la stringa
     * @return ritorna la stringa associata al tipo di nave dato in input
     */
    static std::string to_string(Ships ship);

    /**
     * Associa ad ogni tipo di nave la lunghezza di essa. Poteva essere implementato anche con una mappa statica
     * e avrebbe avuto complessità O(1) ma lo si è ritenuto inutile
     * @param ship il tipo di nave di cui ottenere la lunghezza
     * @return ritorna la lunghezza associata al tipo di nave dato in input
     */
    static int get_length(Ships ship);

    /**
     * Permette di instanziare e posizionare una nave nella board in base al tipo di nave passato come parametro.
     * @param ship_type il tipo della nave da creare
     * @param top_left_corner il punto in alto a sinistra della nave
     * @param horizontal indica se si vuole posizionare la nave in orizzontale o in verticale
     * @param board la board all'interno della quale si intende posizionare la nave
     * @param enemy_board la board dell'avversario che serve per inizializzare l'azione che deve eseguire la nave
     * @return ritorna true se la nave è stata correttamente posizionata false altrimenti
     */
    static bool instantiate_ship(Ships ship_type, const Point &top_left_corner, bool horizontal,
                                 const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    /**
     *
     * @param board la board sulla quale posizionare la navi
     * @param enemy_board la board dell'avversario
     * @param logger il logger per loggare le azioni eseguite
     */
    ShipPlaceCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                     const std::shared_ptr<Logger> &logger);

    /**
     *
     * @param bow la prua della nave
     * @param stern la poppa della nave
     * @return ritorna true se la nave è posizionata correttamente false altrimenti
     */
    bool execute_action(const Point &bow, const Point &stern) override;

    /**
     *
     * @param top_left_corner il punto in alto a sinistra della nave
     * @param horizontal l'orientamento della nave
     * @return ritorna true se la nave è posizionata correttamente false altrimenti
     */
    bool execute_action(const Point &top_left_corner, bool horizontal);
};

#endif //SHIPPLACECOMMAND_H
