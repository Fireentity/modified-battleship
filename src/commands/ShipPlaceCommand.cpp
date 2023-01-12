#include "commands/ShipPlaceCommand.h"

const std::vector<Ship::Ships> ShipPlaceCommand::availableShips = {
        Ship::Ships::ARMOURED, Ship::Ships::SUBMARINE, Ship::Ships::SUPPORT
};

ShipPlaceCommand::ShipPlaceCommand(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                   const std::shared_ptr<Logger> &logger) : ShipCommand(board, logger),
                                                                            enemy_board_{enemy_board},
                                                                            index_{0} {
}

bool ShipPlaceCommand::execute_action(const Point &bow, const Point &stern) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ship::Ships ship_type = availableShips[index_];

    int point_distance = Ship::get_length(ship_type) - 1;
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

    bool was_placed = Ship::instantiate_ship(ship_type, top_left_corner, horizontal, board_, enemy_board_);
    if (was_placed) {
        logger_->log(bow.to_string() + " " + stern.to_string()).log("\n");
        index_++;
    }
    return was_placed;
}

bool ShipPlaceCommand::execute_action(const Point &top_left_corner, bool horizontal) {
    if (index_ >= availableShips.size()) {
        return false;
    }

    Ship::Ships ship_type = availableShips[index_];
    int point_distance = Ship::get_length(ship_type) - 1;
    Point stern = horizontal ? top_left_corner.add_x(point_distance) : top_left_corner.add_y(point_distance);
    std::shared_ptr<Board> board = board_;
    std::shared_ptr<Board> enemy_board = enemy_board_;
    bool was_placed = Ship::instantiate_ship(ship_type, top_left_corner, horizontal, board, enemy_board);
    if (was_placed) {
        logger_->log(top_left_corner.to_string() + " " + stern.to_string()).log("\n");
        index_++;
        return true;
    }
    return false;
}
