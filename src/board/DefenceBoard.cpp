
#include "board/DefenceBoard.h"
#include <algorithm>

DefenceBoard::DefenceBoard(const std::vector<std::shared_ptr<Ship>> &ships) {
    std::for_each(ships.begin(), ships.end(), [this](const std::shared_ptr<Ship> &ship) {
        unsigned short x = ship->get_x();
        unsigned short y = ship->get_y();
        this->board_[x][y].set_ship(ship);

    });
}
