#include "ship/Submarine.h"

Submarine::Submarine(const Point &center, const std::shared_ptr<Board> &defence_board) : Ship{center, breadth,
                                                                                              length,
                                                                                              max_health, max_health,
                                                                                              defence_board} {
    //TODO controllare se non si crea una dipendenza circolare
    std::shared_ptr<Submarine> shared_ptr{};
    shared_ptr.reset(this);
    piece_ = std::make_shared<ShipPiece>(center, defence_board, shared_ptr);
    if (!piece_->is_valid_position(position_)) {
        throw std::invalid_argument("Unable to place ship");
    }
}

bool Submarine::do_action(const Point &target, Board &enemy_board) {
    if (health_ == 0) {
        return false;
    }

    if (!is_valid_position(target)) {
        return false;
    }

    move(target);

    int center_x = get_center_x() - (range / 2);
    int center_y = get_center_x() - (range / 2);

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            if (!Board::is_out(j,i)) {
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

bool Submarine::make_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &defence_board) {
    if(bow == stern) {
        return false;
    }

    if(defence_board->is_out(bow)) {
        return false;
    }

    if(defence_board->get_slot(bow).has_ship()) {
        return false;
    }

    Submarine submarine{bow,defence_board};
    return true;
}

char Submarine::get_character() const {
    return piece;
}

char Submarine::get_damaged_character() const {
    return damagedPiece;
}

bool Submarine::is_valid_position(const Point &point) {
    return piece_->is_valid_position(point);
}

void Submarine::move(const Point &destination) {
    piece_->move_to(destination);
}




