#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include "ship/Ship.h"

class Ship;

class BoardSlot {

public:

    enum State {
        HIT,
        HIT_MISSED,
        REVEALED,
        EMPTY
    };

    explicit BoardSlot(const std::shared_ptr<Ship> &);

    BoardSlot();

    const std::shared_ptr<Ship> &get_ship() const;

    void set_ship(const std::shared_ptr<Ship> &ship);

    void set_state(State state);

    State get_state() const;

    void remove_ship();

    bool has_ship();

//I field privati sono stati dichiarati sotto perché doveva essere prima definita l'enumerazione State
private:
    std::shared_ptr<Ship> ship_;
    State state_;
};

#endif //BOARDPIECE_H
