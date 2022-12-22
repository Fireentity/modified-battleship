#include "ship/Ship.h"

Ship::Ship(const Point &position,
           unsigned short width,
           unsigned short height,
           unsigned short health) : position_{position}, width_{width}, height_{height}, health_{health} {

}

unsigned int Ship::get_x() const {
    return this->position_.x_;
}

unsigned int Ship::get_y() const {
    return this->position_.y_;
}

unsigned short Ship::get_width() const {
    return width_;
}

unsigned short Ship::get_height() const {
    return height_;
}

unsigned short Ship::get_health() const {
    return health_;
}