#include "ship/ArmouredShip.h"

const char ArmouredShip::piece = 'C';
const char ArmouredShip::damagedPiece = 'c';
const unsigned short ArmouredShip::breadth = 1;
const unsigned short ArmouredShip::length = 5;
const unsigned short ArmouredShip::max_health = 5;

ArmouredShip::ArmouredShip(int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board)
        : LinearShip{x, y, horizontal ? length : breadth, horizontal ? breadth : length, max_health, max_health,
                     defence_board, horizontal} {
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


