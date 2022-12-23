#include "ship/LinearShip.h"

LinearShip::LinearShip(int x,
                       int y,
                       unsigned short width,
                       unsigned short height,
                       unsigned short health,
                       unsigned short max_health,
                       DefenceBoard &defence_board,
                       bool horizontal) : Ship{Point{x, y}, width, height, health, max_health, defence_board},
                                          horizontal_{horizontal} {

}

bool LinearShip::is_horizontal() const {
    return horizontal_;
}


void LinearShip::move(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    for (auto &iterated_piece: pieces) {
        const Point &position = iterated_piece->get_position();
        iterated_piece->move(position.x_ + move_x, position.y_ + move_y);
    }
}

bool LinearShip::can_move(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    return std::all_of(pieces.begin(), pieces.end(), [move_x, move_y](const std::shared_ptr<ShipPiece> &piece) {
        return piece->can_move(piece->get_position().x_ + move_x, piece->get_position().y_ + move_y);
    });

}

void LinearShip::place() const {
    int dim = std::max(this->get_height(), this->get_width());

    Point positions[dim];

    for (int i = 0; i < dim; i++) {
        Point position = Point{this->get_center_x(), this->get_center_y()};

        if (is_horizontal()) {
            position.x_ += -(dim / 2) + i;
        } else {
            position.y_ += -(dim / 2) + i;
        }

        if (defence_board_.get_slot(position.x_, position.y_).get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }

        positions[i] = position;
    }

    for (int i = 0; i < dim; i++) {
        defence_board_.set_slot(positions[i].y_, positions[i].x_, BoardSlot{this->get_shared_ptr()});
    }
}
