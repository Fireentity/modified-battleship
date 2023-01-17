//Alberto Bottari 2034728

#include "commands/ShipPlaceCommand.h"

const std::vector<ShipPlaceCommand::Ships> ShipPlaceCommand::availableShips = {
        Ships::ARMOURED, Ships::ARMOURED, Ships::ARMOURED, Ships::SUPPORT, Ships::SUPPORT,
        Ships::SUPPORT, Ships::SUBMARINE, Ships::SUBMARINE,
};

ShipPlaceCommand::ShipPlaceCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                   const std::shared_ptr<Logger> &logger) : ShipCommand(board, logger),
                                                                            enemy_board_{enemy_board},
                                                                            index_{0} {
}

bool ShipPlaceCommand::instantiate_ship(Ships ship_type, const Point &top_left_corner, bool horizontal,
                            const std::shared_ptr<Board> &board,
                            const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case ARMOURED:
            return board->insert_ship(std::make_shared<Armoured>(top_left_corner, horizontal, board, enemy_board));
        case SUPPORT:
            return board->insert_ship(std::make_shared<Supporter>(top_left_corner, horizontal, board, enemy_board));
        case SUBMARINE:
            return board->insert_ship(std::make_shared<Submarine>(top_left_corner, board, enemy_board));
    }
    throw std::invalid_argument("Invalid ship type");
}

bool ShipPlaceCommand::execute_action(const Point &bow, const Point &stern) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ships ship_type = availableShips[index_];

    int point_distance = get_length(ship_type) - 1;
    if (bow.squared_distance(stern) != std::pow(point_distance, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    if (Board::is_out(bow) || Board::is_out(stern)) {
        return false;
    }

    bool horizontal = bow.get_y() == stern.get_y();
    Point top_left_corner = Point{std::min(bow.get_x(), stern.get_x()), std::min(bow.get_y(), stern.get_y())};

    bool was_placed = instantiate_ship(ship_type, top_left_corner, horizontal, board_, enemy_board_);
    if (was_placed) {
        logger_->log(bow.to_string() + " " + stern.to_string()).log("\n");
        index_++;
    }
    return was_placed;
}

std::string ShipPlaceCommand::to_string(Ships ship) {
    switch (ship) {
        case ARMOURED: return "Corazzata";
        case SUBMARINE: return "Sottomarino";
        case SUPPORT: return "Supporto";
    }
    throw std::invalid_argument("Invalid ship type");
}

int ShipPlaceCommand::get_length(Ships ship) {
    switch (ship) {
        case ARMOURED: return Armoured::length;
        case SUBMARINE: return Submarine::length;
        case SUPPORT: return Supporter::length;
    }
    throw std::invalid_argument("Invalid ship type");
}

bool ShipPlaceCommand::execute_action(const Point &top_left_corner, bool horizontal) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ships ship_type = availableShips[index_];
    int point_distance = get_length(ship_type) - 1;
    Point stern = horizontal ? top_left_corner.add_x(point_distance) : top_left_corner.add_y(point_distance);
    std::shared_ptr<Board> board = board_;
    std::shared_ptr<Board> enemy_board = enemy_board_;
    bool was_placed = instantiate_ship(ship_type, top_left_corner, horizontal, board, enemy_board);
    if (was_placed) {
        logger_->log(top_left_corner.to_string() + " " + stern.to_string()).log("\n");
        index_++;
        return true;
    }
    return false;
}
