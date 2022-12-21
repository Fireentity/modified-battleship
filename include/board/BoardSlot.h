#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include "ship/Ship.h"

class ShipPiece;

//Rappresenta uno slot della board_ di gioco. Contiene un'associazione tra un pezzo della nave alle coordinate (x_,y_)
//e lo stato di ciò che vede il giocatore avversario.
//Si è preferito creare una sola board_ per evitare di dover aggiornare oggetti in parallelo.
class BoardSlot {

public:

    enum State {
        HIT,
        HIT_MISSED,
        REVEALED,
        EMPTY
    };

    explicit BoardSlot(const std::shared_ptr<ShipPiece> &);

    BoardSlot();

    std::shared_ptr<ShipPiece> get_ship_piece() const;

    void set_ship_piece(const std::shared_ptr<ShipPiece> &ship);

    void set_state(State state);

    State get_state() const;

    void remove_ship_piece();

    bool has_ship() const;

//I field privati sono stati dichiarati sotto perché doveva essere prima definita l'enumerazione State
private:
    std::shared_ptr<ShipPiece> ship_;
    State state_;
};

#endif //BOARDPIECE_H
