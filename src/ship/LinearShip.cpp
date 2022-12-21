#include "ship/LinearShip.h"

class ArmouredShip;

LinearShip::LinearShip(int x, int y, unsigned short width, unsigned short height, unsigned short health,
                       unsigned short max_health, const std::shared_ptr<DefenceBoard> &defence_board, bool horizontal)
        : Ship{Point{x, y}, width, height, health, max_health, defence_board}, horizontal_{horizontal} {
}

bool LinearShip::is_horizontal() const {
    return horizontal_;
}

void LinearShip::move(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    for (auto &iterated_piece: pieces_) {
        const Point &position = iterated_piece->get_position();
        iterated_piece->move(position.x_ + move_x, position.y_ + move_y);
    }
}

bool LinearShip::is_valid_position(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    return std::all_of(pieces_.begin(), pieces_.end(), [move_x, move_y](const std::shared_ptr<ShipPiece> &piece) {
        return piece->is_valid_position(piece->get_position().x_ + move_x, piece->get_position().y_ + move_y);
    });

}

bool LinearShip::place() {
    if (!this->is_valid_position(position_.x_, position_.y_)) {
        return false;
    }

    move(position_.x_, position_.y_);
}
