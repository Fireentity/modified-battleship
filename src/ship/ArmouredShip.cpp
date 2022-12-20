#include <stdexcept>
#include "Point.h"
#include "board/DefenceBoard.h"
#include "ship/ArmouredShip.h"

const char ArmouredShip::character = 'C';

ArmouredShip::ArmouredShip(const Point &point, unsigned short width, unsigned short height,
                           unsigned short health) : Ship(point, width, height, health) {

}

char ArmouredShip::get_character() const {
    return ArmouredShip::character;
}

void ArmouredShip::place(const DefenceBoard &defence_board) const {
    int dim = std::max(this->get_height(), this->get_width());

    for (int i = 0; i < dim; i++) {
        Point position = Point{this->get_x(), this->get_y() - (dim / 2) + i};

        if (defence_board.get_slot(position.x_,position.y_) != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }
        defence_board.set_slot(position.x_,position.y_,std::make_shared<Ship>(this));
    }
}

