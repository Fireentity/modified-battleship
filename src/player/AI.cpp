#include "player/AI.h"

const std::unordered_map<Player::Ships, std::function<bool(Point, bool, std::shared_ptr<Board>)>> AI::factory = {
        {
                Player::Ships::ARMOURED,
                [](Point bow, bool horizontal, const std::shared_ptr<Board> &defence_board) {
                    if(horizontal) {
                        return ArmouredShip::make_ship_or_null(bow, {bow.get_x() + ArmouredShip::length, bow.get_y()},
                                                               defence_board);
                    } else {
                        return ArmouredShip::make_ship_or_null(bow, {bow.get_x(), bow.get_y() + ArmouredShip::length},
                                                               defence_board);
                    }
                }
        },
        {
                Player::Ships::SUPPORT,
                [](Point bow, bool horizontal, const std::shared_ptr<Board> &defence_board) {
                    if(horizontal) {
                        return Supporter::make_ship(bow,{bow.get_x() + ArmouredShip::length,bow.get_y()}, defence_board);
                    } else {
                        return Supporter::make_ship(bow,{bow.get_x(),bow.get_y() + ArmouredShip::length}, defence_board);
                    }
                }
        },
        {
                Player::Ships::SUBMARINE,
                [](Point bow, bool horizontal, const std::shared_ptr<Board> &defence_board) {
                    if(horizontal) {
                        return Submarine::make_ship(bow,{bow.get_x() + ArmouredShip::length,bow.get_y()}, defence_board);
                    } else {
                        return Submarine::make_ship(bow,{bow.get_x(),bow.get_y() + ArmouredShip::length}, defence_board);
                    }
                }
        }
};

std::shared_ptr<Board> AI::place_ships_inside_board() {
    int i = 0;
    //Itero tutte le navi da piazzare fin quando non sono tutte posizionate
    while (i < available_ships.size()) {

        Ships ship_type = Player::available_ships[i];

        Point bow{rand() % Board::width,rand() % Board::height};

        bool horizontal = rand()%2==0;

        if(AI::factory.at(ship_type)(bow, horizontal, board)) {
            i++;
        }
    }

    return board;
}

void AI::do_move(Board &enemy_board) {

}

