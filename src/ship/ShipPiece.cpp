#include "ship/ShipPiece.h"

ShipPiece::ShipPiece(const Point &position) : position_{position} {

}

ShipPiece::ShipPiece() : position_{0,0}, hit_(false) {

}

void ShipPiece::move_to(const Point &point) {
    position_ = point;
}

const Point &ShipPiece::get_position() const {
    return position_;
}

bool ShipPiece::is_hit() {
    return hit_;
}

void ShipPiece::hit() {
    hit_ = true;
}
