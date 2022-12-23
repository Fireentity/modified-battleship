#include "ship/ShipPiece.h"

ShipPiece::ShipPiece(const Point &position, const std::shared_ptr<DefenceBoard> &defence_board,
                     const std::shared_ptr<Ship> &ship) : position_{position}, defence_board_{defence_board},
                                                          ship_{ship} {

}

void ShipPiece::move(int x, int y) {
    defence_board_->get_slot(x,y).set_ship(ship_);
    defence_board_->get_slot(position_.x_, position_.y_).remove_ship();
    position_.x_ = x;
    position_.y_ = y;
}

bool ShipPiece::can_move(int x, int y) {
    return defence_board_->get_slot(x,y).has_ship();
}

const Point &ShipPiece::get_position() {
    return position_;
}

bool ShipPiece::is_hit() {
    return hit_;
}

void ShipPiece::hit() {
    hit_ = true;
}
