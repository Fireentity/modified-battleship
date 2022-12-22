#include <stdexcept>
#include "ship/ArmouredShip.h"

const char ArmouredShip::piece = 'C';
const char ArmouredShip::damagedPiece = 'c';
const unsigned short ArmouredShip::breadth = 1;
const unsigned short ArmouredShip::length = 5;
const unsigned short ArmouredShip::max_health = 5;

ArmouredShip::ArmouredShip(unsigned int x, unsigned int y, bool horizontal) : LinearShip{x, y,
                                                                                             horizontal ? length: breadth,
                                                                                             horizontal ? breadth: length,
                                                                                         max_health,
                                                                                         horizontal} {

}

char ArmouredShip::get_character() const {
    return piece;
}

char ArmouredShip::get_damaged_character() const {
    return damagedPiece;
}

void ArmouredShip::place(DefenceBoard &defence_board) const {
    int dim = std::max(this->get_height(), this->get_width());

    for (int i = 0; i < dim; i++) {
        Point position = Point{this->get_x(), this->get_y()};

        if (is_horizontal()) {
            position.x_ -= (dim / 2) + i;
        } else {
            position.y_ -= (dim / 2) + i;
        }

        if (defence_board.get_slot(position.x_, position.y_).get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }

        defence_board.set_slot(position.y_, position.x_, BoardPiece{std::make_shared<ArmouredShip>(*this)});
    }
}

std::shared_ptr<LinearShip> ArmouredShip::get_shared_ptr() const {
    return std::make_shared<ArmouredShip>(*this);
}

