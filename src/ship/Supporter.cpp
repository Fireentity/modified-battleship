#include <stdexcept>
#include "ship/Supporter.h"

Supporter::Supporter(unsigned int x, unsigned int y, bool horizontal) : Ship{Point{x,y},
                                                                 horizontal?length:breadth,
                                                                 horizontal?breadth:length,
                                                                 max_health} {
}

void Supporter::place(DefenceBoard &defence_board) const {
    int dim = std::max(this->get_height(), this->get_width());

    for (int i = 0; i < dim; i++) {
        Point position = Point{this->get_x(), this->get_y() - (dim / 2) + i};

        if (defence_board.get_slot(position.x_,position.y_).get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }

        defence_board.set_slot(position.x_,position.y_, BoardPiece{std::make_shared<Supporter>(*this)});
    }
}

char Supporter::get_character() const {
    return piece;
}

char Supporter::get_damaged_character() const {
    return damagedPiece;
}
