#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include <functional>

//Class forwarding
class Ship;

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

    BoardSlot();

    static char to_character(State state);

    char get_piece(unsigned int x, unsigned int y) const;

    void set_ship(const std::shared_ptr<Ship> &ship);

    std::shared_ptr<const Ship> get_ship() const;

    std::shared_ptr<Ship> get_ship();

    void set_state(State state);

    State get_state() const;

    bool has_ship() const;

    void remove_ship();
//I field privati sono stati dichiarati sotto perché doveva essere prima definita l'enumerazione State
private:
    std::shared_ptr<Ship> ship_;
    State state_;
};

#endif //BOARDPIECE_H
