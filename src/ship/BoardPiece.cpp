#include <memory>
#include "board/BoardPiece.h"

BoardPiece::BoardPiece(std::shared_ptr<Ship> ship): ship_{ship}, hit_{false} {

}

BoardPiece::BoardPiece(): ship_{}, hit_{false} {

}

const std::shared_ptr <Ship> &BoardPiece::get_ship() const {
    return ship_;
}

void BoardPiece::set_ship(const std::shared_ptr <Ship> &ship) {
    ship_ = ship;
}

bool BoardPiece::is_hit() const {
    return hit_;
}

void BoardPiece::set_hit(bool hit) {
    hit_ = hit;
}
