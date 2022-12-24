#include <memory>
#include "board/BoardSlot.h"

BoardSlot::BoardSlot(const std::shared_ptr<ShipPiece> &ship): ship_{ship}, state_{EMPTY} {

}

BoardSlot::BoardSlot(): ship_{}, state_{EMPTY} {

}

std::shared_ptr<ShipPiece> BoardSlot::get_ship_piece() const {
    return ship_;
}

void BoardSlot::set_ship_piece(const std::shared_ptr<ShipPiece> &ship) {
    ship_ = ship;
}

void BoardSlot::set_state(BoardSlot::State state) {
    state_ = state;
}

BoardSlot::State BoardSlot::get_state() const {
    return state_;
}

void BoardSlot::remove_ship_piece() {
    ship_ = nullptr;
}

bool BoardSlot::has_ship() const {
    return ship_ == nullptr;
}
