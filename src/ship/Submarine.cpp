#include "ship/Submarine.h"

Submarine::Submarine(int x, int y, const std::shared_ptr<DefenceBoard> &defence_board) : Ship{Point{x, y}, thickness,
                                                                                              length,
                                                                                              max_health, max_health,
                                                                                              defence_board},
                                                                                         piece_{std::make_shared<ShipPiece>()} {
}

bool Submarine::place() {
    if (defence_board_->get_slot(this->get_center_x(), this->get_center_y()).get_ship_piece() != nullptr) {
        throw std::invalid_argument("Position already occupied by another ship");
    }

    defence_board_->set_slot(this->get_center_x(), this->get_center_y(), BoardSlot{this->piece_});
}

char Submarine::get_character() const {
    return piece;
}

char Submarine::get_damaged_character() const {
    return damagedPiece;
}

bool Submarine::do_action(int x, int y) {
    if (health_ == 0) {
        return false;
    }

    if (!is_valid_position(x, y)) {
        return false;
    }

    move(x, y);

    int center_x = get_center_x() - (range / 2);
    int center_y = get_center_x() - (range / 2);
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            const std::shared_ptr<Ship> &ship = defence_board_->get_slot(center_x + j, center_y + i)
                    .get_ship_piece()->get_ship();
            if (ship != nullptr) {
                defence_board_->get_slot(j, i).set_state(BoardSlot::REVEALED);
            }
        }
    }

    return true;

}

bool Submarine::is_valid_position(int x, int y) {
    return piece_->can_move(x, y);
}

void Submarine::move(int x, int y) {
    piece_->move(x, y);
}




