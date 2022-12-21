#include "ship/Ship.h"

Ship::Ship(const Point &position, int width, int height, unsigned int size, int health, int max_health,
           const std::shared_ptr<Board::Action> &action) : position_{position},
                                                           width_{width}, height_{height},
                                                           pieces_amount_{size},
                                                           health_{health},
                                                           max_health_{max_health} {

}

void Ship::set_health(unsigned short health) {
    this->health_ = health;
}

int Ship::get_health() const {
    return health_;
}

int Ship::get_max_health() const {
    return max_health_;
}

const Point &Ship::get_center() {
    return position_;
}

bool Ship::do_action(const Point &target) {
    return action->do_action(target);
}

void Ship::for_each_piece(const std::function<void(ShipPiece&)> &on_iteration) {
    for(auto & piece : pieces_) {
        on_iteration(piece);
    }
}

unsigned int Ship::get_pieces_amount() const {
    return pieces_amount_;
}
