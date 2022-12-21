#include "player/Player.h"

//Inizializzazione statica delle navi disponibili nella flotta
//Non potendo usare file di configurazione la flotta è stata così implementata
const std::vector<Player::Ships> Player::available_ships = {
        Ships::ARMOURED, Ships::ARMOURED, Ships::ARMOURED, Ships::SUBMARINE, Ships::SUBMARINE, Ships::SUPPORT, Ships::SUPPORT, Ships::SUPPORT
};

std::string Player::to_string(Ships ship) {
    switch (ship) {
        case Ships::ARMOURED:
            return "Corazzata";
        case Ships::SUPPORT:
            return "Supporto";
        case Ships::SUBMARINE:
            return "Sottomarino";
    }

    throw std::invalid_argument("Invalid ship type");
}

Player::Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : board_{board},
                                                                                                 enemy_board_{enemy_board} {

}

bool Player::make_and_place_armoured_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                          const std::shared_ptr<Board> &enemy_board) {
    if (bow.squared_distance(stern) != std::pow(Ship::armoured_ship_length, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    bool horizontal = bow.get_x() == stern.get_x();
    Ship ship{bow.middle_point(stern),
              horizontal ? Ship::armoured_ship_length : Ship::breadth,
              horizontal ? Ship::breadth : Ship::armoured_ship_length,
              Ship::armoured_ship_length,
              Ship::armoured_ship_length,
              Ship::armoured_ship_length,
              std::make_shared<MoveAndHealAction>(board, enemy_board)};
    board->insert_ship(ship);


    return true;
}

bool Player::make_and_place_support_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                         const std::shared_ptr<Board> &enemy_board) {
    if (bow.squared_distance(stern) != std::pow(Ship::armoured_ship_length, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    bool horizontal = bow.get_x() == stern.get_x();
    Ship ship{bow.middle_point(stern),
              horizontal ? Ship::support_ship_length : Ship::breadth,
              horizontal ? Ship::breadth : Ship::support_ship_length,
              Ship::support_ship_length,
              Ship::support_ship_length,
              Ship::support_ship_length,
              std::make_shared<MoveAndHealAction>(board, enemy_board)};
    board->insert_ship(ship);


    return true;
}

bool Player::make_and_place_submarine(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                      const std::shared_ptr<Board> &enemy_board) {

    if (bow == stern) {
        return false;
    }

    Ship ship{bow.middle_point(stern),
              Ship::breadth,
              Ship::submarine_length,
              Ship::submarine_length,
              Ship::submarine_length,
              Ship::submarine_length,
              std::make_shared<MoveAndRevealAction>(board, enemy_board)};
    board->insert_ship(ship);
    return true;
}

bool Player::instantiate_ship(Player::Ships ship_type, const Point &bow, const Point &stern,
                              const std::shared_ptr<Board> &board,
                              const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case Ships::ARMOURED:
            return make_and_place_armoured_ship(bow, stern, board, enemy_board);
        case Ships::SUPPORT:
            return make_and_place_support_ship(bow, stern, board, enemy_board);
        case Ships::SUBMARINE:
            return make_and_place_submarine(bow, stern, board, enemy_board);
    }

    throw std::invalid_argument("Invalid ship type");
}

std::shared_ptr<Board> Player::get_board() const {
    return board_;
}

std::shared_ptr<Board> Player::get_enemy_board() const {
    return enemy_board_;
}
