#include "ship/LinearShip.h"

class ArmouredShip;

LinearShip::LinearShip(const Point &center, int width, int height, int health, int max_health,
                       const std::shared_ptr<DefenceBoard> &defence_board) : Ship{center, width, height, health,
                                                                                  max_health, defence_board} {
}

void LinearShip::move(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    for (auto &iterated_piece: pieces_) {
        const Point &position = iterated_piece->get_position();
        iterated_piece->move_to(position.x + move_x, position.y + move_y);
    }
}

bool LinearShip::is_valid_position(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    return std::all_of(pieces_.begin(), pieces_.end(), [move_x, move_y](const std::shared_ptr<ShipPiece> &piece) {
        return piece->is_valid_position(piece->get_position().x + move_x, piece->get_position().y + move_y);
    });

}
