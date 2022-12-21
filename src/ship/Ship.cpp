#include "ship/Ship.h"

const unsigned short Ship::armoured_ship_length = 5;
const unsigned short Ship::support_ship_length = 3;
const unsigned short Ship::submarine_length = 1;
const int Ship::breadth = 1;


Ship::Ship(const Point &position, int width, int height, unsigned int size, int health, int max_health,
           const std::shared_ptr<Board::Action> &action) : position_{position},
                                                           width_{width}, height_{height},
                                                           pieces_amount_{size},
                                                           health_{health},
                                                           max_health_{max_health} {

}

void Ship::for_each_piece(const std::function<void(ShipPiece&)> &on_iteration) {
    for(auto & piece : pieces_) {
        on_iteration(piece);
    }
}

bool Ship::do_action(const Point &target) const {
    return action->do_action(target);
}

unsigned int Ship::get_pieces_amount() const {
    return pieces_amount_;
}

void Ship::set_health(unsigned short health) {
    this->health_ = health;
}

int Ship::get_max_health() const {
    return max_health_;
}

const Point &Ship::get_center() {
    return position_;
}

int Ship::get_health() const {
    return health_;
}
