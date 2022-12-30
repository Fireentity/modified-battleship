#include "player/AI.h"

AI::AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : Player{board, enemy_board} {

}

void AI::place_ships_inside_board() {
    srand(time(nullptr));
    int i = 0;
    //Itero tutte le navi da piazzare fin quando non sono tutte posizionate
    while (i < available_ships.size()) {

        Ship::Ships ship_type = Player::available_ships[i];

        Point bow{rand() % Board::width, rand() % Board::height};

        bool horizontal = rand() % 2 == 0;

        if (AI::instantiate_ship(ship_type, bow, horizontal, board_, enemy_board_)) {
            i++;
        }
    }
}


void AI::do_move() {
    const std::vector<std::shared_ptr<Ship>> &ships =board_->get_ships();
    int action = rand()%ships.size();
    Point target{rand()%board_->width,rand()%board_->height};
    while(ships[action]->do_action(target)) {
        target = {rand()%board_->width,rand()%board_->height};
    }
}

bool AI::instantiate_ship(Ship::Ships ship_type, const Point &bow, bool horizontal, const std::shared_ptr<Board> &board,
                          const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case Ship::Ships::ARMOURED: {
            int point_distance = ArmouredShip::armoured_ship_length-1;
            Point stern = horizontal ? bow.add_x(point_distance) : bow.add_y(point_distance);
            return Ship::instantiate_ship(ship_type, bow, stern, board, enemy_board);
        }
        case Ship::Ships::SUPPORT: {
            int point_distance = SupporterShip::supporter_ship_length-1;
            Point stern = horizontal ? bow.add_x(point_distance) : bow.add_y(point_distance);
            return Ship::instantiate_ship(ship_type, bow, stern, board, enemy_board);
        }
        case Ship::Ships::SUBMARINE: {
            return Ship::instantiate_ship(ship_type, bow, bow, board, enemy_board);
        }
    }
    throw std::invalid_argument("Invalid ship type");
}

