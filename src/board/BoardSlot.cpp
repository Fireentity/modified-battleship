#include "board/BoardSlot.h"
#include "ship/Ship.h"

BoardSlot::BoardSlot() = default;

BoardSlot::BoardSlot(const Point &position) : ship_{}, state_{EMPTY}, position_{position} {

}

void BoardSlot::set_ship(const std::shared_ptr<Ship> &ship) {
    if(ship_ != nullptr) {
        throw std::invalid_argument("Cannot replace a ship with another you have to delete it first");
    }
    ship_ = ship;
}

std::shared_ptr<const Ship> BoardSlot::get_ship() const {
    return ship_;
}

std::shared_ptr<Ship> BoardSlot::get_ship() {
    return ship_;
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

bool BoardSlot::has_ship() const {
    return ship_ != nullptr;
}

char BoardSlot::get_defence_char() const {
    return has_ship()? get_ship()->get_piece_character(position_) : to_character(EMPTY);
}

char BoardSlot::get_attack_char() const {
    return to_character(get_state());
}

char BoardSlot::to_character(State state) {
    switch (state) {
        case HIT: return 'X';
        case HIT_MISSED: return 'O';
        case REVEALED: return 'Y';
        case EMPTY: return ' ';
    }
    throw std::invalid_argument("Invalid BoardSlot state");
}
