#include "ship/ArmouredShip.h"

const char ArmouredShip::piece = 'C';
const char ArmouredShip::damagedPiece = 'c';
const unsigned short ArmouredShip::breadth = 1;
const unsigned short ArmouredShip::length = 5;
const unsigned short ArmouredShip::max_health = 5;

ArmouredShip::ArmouredShip(int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board)
        : LinearShip{x, y, horizontal ? length : breadth, horizontal ? breadth : length, max_health, max_health,
                     defence_board, horizontal} {
    Point position{get_center_x(), get_center_y()};

    for(int i = 0; i < length; i++) {
        if(horizontal) {
            position .x_ += - (length/2) + i;
        } else {
            position .y_ += - (length/2) + i;
        }

        std::shared_ptr<ArmouredShip> shared_ptr{};
        shared_ptr.reset(this);
        pieces_[i] = std::make_shared<ShipPiece>(position,defence_board,shared_ptr);
    }

    bool can_place = std::any_of(pieces_.begin(), pieces_.end(),[](const std::shared_ptr<ShipPiece> &piece) {
        return !piece->is_valid_position(piece->get_position().x_, piece->get_position().y_);
    });

    if(!can_place) {
        throw std::invalid_argument("Unable to place ship");
    }
}


char ArmouredShip::get_character() const {
    return piece;
}

char ArmouredShip::get_damaged_character() const {
    return damagedPiece;
}

bool ArmouredShip::do_action(int x, int y) {
    if (health_ == 0) {
        return false;
    }

    std::shared_ptr<Ship> ship = this->defence_board_->get_slot(x, y).get_ship_piece()->get_ship();
    if (ship == nullptr) {
        defence_board_->get_slot(x, y).set_state(BoardSlot::HIT_MISSED);
    } else {
        ship->set_health(ship->get_health() - 1);
    }

    return true;
}


