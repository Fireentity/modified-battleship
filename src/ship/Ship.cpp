#include "ship/Ship.h"

Ship::Ship(const Point &position, int width, int height, int health, int max_health,
           const std::shared_ptr<Board> &defence_board) : position_{position}, width_{width}, height_{height},
                                                          health_{health}, max_health_{max_health},
                                                          defence_board_{defence_board} {

}

int Ship::get_center_x() const {
    return this->position_.get_x();
}

int Ship::get_center_y() const {
    return this->position_.get_y();
}

unsigned short Ship::get_health() const {
    return health_;
}

void Ship::set_health(unsigned short health) {
    this->health_ = health;
}

unsigned short Ship::get_max_health() const {
    return max_health_;
}
