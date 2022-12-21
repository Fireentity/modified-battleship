#include "player/AI.h"

AI::AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : Player{board, enemy_board} {

}

void AI::place_ships_inside_board() {
    int i = 0;
    //Itero tutte le navi da piazzare fin quando non sono tutte posizionate
    while (i < available_ships.size()) {

        Ships ship_type = Player::available_ships[i];

        Point bow{rand() % Board::width, rand() % Board::height};

        bool horizontal = rand() % 2 == 0;

        if (AI::instantiate_ship(ship_type, bow, horizontal, get_board(), get_enemy_board())) {
            i++;
        }
    }
}

void AI::do_move(Board &enemy_board) {
    const std::vector<std::shared_ptr<Ship>> &ships =get_board()->get_ships();
    int action = rand()%ships.size();
    Point target{rand()%get_board()->width,rand()%get_board()->height};
    while(ships[action]->do_action(target)) {
        target = {rand()%get_board()->width,rand()%get_board()->height};
    }
}

bool AI::instantiate_ship(Player::Ships ship_type, const Point &bow, bool horizontal, const std::shared_ptr<Board> &board,
                          const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case Player::Ships::ARMOURED: {
            Point stern = horizontal ? bow.add_x(Ship::armoured_ship_length) : bow.add_y(Ship::armoured_ship_length);
            return Player::instantiate_ship(ship_type, bow, stern, board, enemy_board);
        }
        case Player::Ships::SUPPORT: {
            Point stern = horizontal ? bow.add_x(Ship::support_ship_length) : bow.add_y(Ship::support_ship_length);
            return Player::instantiate_ship(ship_type, bow, stern, board, enemy_board);
        }
        case Player::Ships::SUBMARINE: {
            return Player::instantiate_ship(ship_type, bow, bow, board, enemy_board);
        }
    }
    throw std::invalid_argument("Invalid ship type");
}

