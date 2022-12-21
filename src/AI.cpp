#include "AI.h"

std::shared_ptr<DefenceBoard> AI::place_ships_inside_board() {
    for (auto ship: Player::available_ships) {
        int x = rand() % defence_board->get_width();
        int y = rand() % defence_board->get_height();
        Player::factory.at(ship)(x, y, true, defence_board);
    }

    return defence_board;
}
