#include <memory>
#include "board/BoardPiece.h"

BoardPiece::BoardPiece(const std::shared_ptr<Ship> &ship): ship_{ship}, hit_{false} {

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

std::ostream &operator<<(std::ostream &os, const BoardPiece &piece) {
    if(piece.get_ship() == nullptr) {
        return os << " ";
    }
    return os << (piece.is_hit() ? piece.get_ship()->get_damaged_character() : piece.get_ship()->get_character());
}
