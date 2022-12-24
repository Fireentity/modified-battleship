#include "ship/Submarine.h"

Submarine::Submarine(const Point &center, const std::shared_ptr<DefenceBoard> &defence_board) : Ship{center, breadth,
                                                                                              length,
                                                                                              max_health, max_health,
                                                                                              defence_board} {
    std::shared_ptr<Submarine> shared_ptr{};
    shared_ptr.reset(this);
    piece_ = std::make_shared<ShipPiece>(center, defence_board, shared_ptr);
    if (!piece_->is_valid_position(position_.x, position_.y)) {
        throw std::invalid_argument("Unable to place ship");
    }
}

bool Submarine::do_action(int x, int y, DefenceBoard &enemy_board) {
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
            if (!enemy_board.is_out(x, y)) {
                const std::shared_ptr<Ship> &ship = enemy_board.get_slot(center_x + j, center_y + i)
                        .get_ship_piece()->get_ship();
                if (ship != nullptr) {
                    enemy_board.get_slot(j, i).set_state(BoardSlot::REVEALED);
                }
            }
        }
    }

    return true;

}

std::shared_ptr<Submarine> Submarine::make_ship_or_null(int x, int y, const std::shared_ptr<DefenceBoard> &defence_board) {
    Point center{x,y};
    if(defence_board->is_out(center)) {
        return nullptr;
    }

    if(defence_board->get_slot(center).has_ship()) {
        return nullptr;
    }

    return std::make_shared<Submarine>(center,defence_board);
}

char Submarine::get_character() const {
    return piece;
}

char Submarine::get_damaged_character() const {
    return damagedPiece;
}

bool Submarine::is_valid_position(int x, int y) {
    return piece_->is_valid_position(x, y);
}

void Submarine::move(int x, int y) {
    piece_->move_to(x, y);
}




