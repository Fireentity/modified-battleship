#include "ship/LinearShip.h"

class ArmouredShip;

LinearShip::LinearShip(const Point &center, int width, int height, int health, int max_health,
                       const std::shared_ptr<Board> &defence_board) : Ship{center, width, height, health,
                                                                           max_health, defence_board} {
}

void LinearShip::move(const Point &destination) {
    Point translation  = destination - position_;
    for (auto &iterated_piece: pieces_) {
        iterated_piece->move_to(iterated_piece->get_position() + translation);
    }
}

bool LinearShip::is_valid_position(const Point &point) {
    Point translation  = point - position_;
    return std::all_of(pieces_.begin(), pieces_.end(), [translation](const std::shared_ptr<ShipPiece> &piece) {
        return piece->is_valid_position(piece->get_position() + translation);
    });

}
