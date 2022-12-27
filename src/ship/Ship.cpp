#include "ship/Ship.h"
#include "ship/SupporterShip.h"
#include "ship/Submarine.h"
#include "player/Player.h"

Ship::Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount,
           const std::shared_ptr<Board::Action> &action) : center_{top_left_corner + Point{width / 2, height / 2}},
                                                           pieces_amount_{pieces_amount},
                                                           pieces_{pieces_amount},
                                                           health_{pieces_amount},
                                                           width_{width},
                                                           height_{height},
                                                           max_health_{pieces_amount},
                                                           action_{action} {
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pieces_[index].move_to(top_left_corner + Point{j, i});
            index++;
        }
    }
}

bool Ship::make_and_place_armoured_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                        const std::shared_ptr<Board> &enemy_board) {
    int point_distance = ArmouredShip::armoured_ship_length - 1;
    if (bow.squared_distance(stern) != std::pow(point_distance, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    if (Board::is_out(bow) || Board::is_out(stern)) {
        return false;
    }
    //TODO inserire controllo per vedere che non si sovrappongano pezzi di nave

    bool horizontal = bow.get_x() != stern.get_x();
    Point top_left_corner = Point{std::min(bow.get_x(), stern.get_x()), std::min(bow.get_y(), stern.get_y())};
    return board->insert_ship(std::make_shared<ArmouredShip>(top_left_corner, horizontal, board, enemy_board));
}

bool Ship::make_and_place_support_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                       const std::shared_ptr<Board> &enemy_board) {
    int point_distance = SupporterShip::supporter_ship_length - 1;
    if (bow.squared_distance(stern) != std::pow(point_distance, 2)) {
        return false;
    }
    if (bow.get_x() != stern.get_x() && bow.get_y() != stern.get_y()) {
        return false;
    }
    bool horizontal = bow.get_x() != stern.get_x();
    Point top_left_corner = Point{std::min(bow.get_x(), stern.get_x()), std::min(bow.get_y(), stern.get_y())};
    return board->insert_ship(std::make_shared<SupporterShip>(top_left_corner, horizontal, board, enemy_board));
}

bool Ship::make_and_place_submarine(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board,
                                    const std::shared_ptr<Board> &enemy_board) {

    if (bow != stern) {
        return false;
    }

    return board->insert_ship(std::make_shared<Submarine>(bow.middle_point(stern), board, enemy_board));
}

bool Ship::instantiate_ship(Ship::Ships ship_type, const Point &bow, const Point &stern,
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

std::string Ship::to_string(Ship::Ships ship) {
    switch (ship) {
        case Ship::Ships::ARMOURED:
            return "Corazzata";
        case Ship::Ships::SUPPORT:
            return "Supporto";
        case Ship::Ships::SUBMARINE:
            return "Sottomarino";
    }
    throw std::invalid_argument("Invalid ship type");
}

void Ship::for_each_piece(const std::function<void(ShipPiece &)> &on_iteration) {
    for (auto &piece: pieces_) {
        on_iteration(piece);
    }
}

bool Ship::do_action(const Point &target) const {
    return action_->do_action(target);
}

unsigned int Ship::get_pieces_amount() const {
    return pieces_amount_;
}

void Ship::set_health(unsigned short health) {
    this->health_ = health;
}

int Ship::get_max_health() const {
    return max_health_;
}

const Point &Ship::get_center() {
    return center_;
}

int Ship::get_health() const {
    return health_;
}

char Ship::get_piece_character(unsigned int x, unsigned int y) const {
    for (auto &piece: pieces_) {
        if (piece.get_position().get_x() == x && piece.get_position().get_y() == y) {
            return piece.is_hit() ? get_damaged_character() : get_character();
        }
    }
    throw std::invalid_argument("Unable to find piece for that point");
}

const std::vector<ShipPiece> &Ship::get_pieces() const {
    return pieces_;
}
