#include "ship/LinearShip.h"

LinearShip::LinearShip(unsigned int x,
                       unsigned int y,
                       unsigned short width,
                       unsigned short height,
                       unsigned short health,
                       bool horizontal) : Ship{Point{x,y}, width, height, health}, horizontal_{horizontal} {

}

bool LinearShip::is_horizontal() const {
    return horizontal_;
}

void LinearShip::place(DefenceBoard &defence_board) const {
    int dim = std::max(this->get_height(), this->get_width());

    for (int i = 0; i < dim; i++) {
        Point position = Point{this->get_x(), this->get_y()};

        if(is_horizontal()) {
            position.x_ += -(dim / 2) + i;
        } else {
            position.y_ += -(dim / 2) + i;
        }

        if (defence_board.get_slot(position.x_, position.y_).get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }

        defence_board.set_slot(position.y_, position.x_, BoardPiece{this->get_shared_ptr()});
    }
}
