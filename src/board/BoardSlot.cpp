#include <memory>
#include "board/BoardSlot.h"

BoardSlot::BoardSlot(const std::shared_ptr<Ship> &ship): ship_{ship}, state_{EMPTY} {

}

BoardSlot::BoardSlot(): ship_{}, state_{EMPTY} {

}

const std::shared_ptr <Ship> &BoardSlot::get_ship() const {
    return ship_;
}

void BoardSlot::set_ship(const std::shared_ptr <Ship> &ship) {
    ship_ = ship;
}

void BoardSlot::set_state(BoardSlot::State state) {
    state_ = state;
}

BoardSlot::State BoardSlot::get_state() const {
    return state_;
}

void BoardSlot::remove_ship() {
    ship_ = nullptr;
}

bool BoardSlot::has_ship() {
    return ship_ == nullptr;
}