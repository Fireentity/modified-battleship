#include "ship/Ship.h"
#include "ship/Supporter.h"
#include "ship/Submarine.h"
#include "player/Player.h"

Ship::Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount,
           const std::shared_ptr<Board::Action> &action) : center_{top_left_corner + Point{width / 2, height / 2}},
                                                           pieces_amount_{pieces_amount},
                                                           pieces_{pieces_amount},
                                                           health_{pieces_amount},
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

bool Ship::instantiate_ship(Ship::Ships ship_type, const Point &top_left_corner, bool horizontal,
                            const std::shared_ptr<Board> &board,
                            const std::shared_ptr<Board> &enemy_board) {
    switch (ship_type) {
        case Ships::ARMOURED: {
            return board->insert_ship(std::make_shared<Armoured>(top_left_corner, horizontal, board, enemy_board));
        }
        case Ships::SUPPORT:
            return board->insert_ship(std::make_shared<Supporter>(top_left_corner, horizontal, board, enemy_board));
        case Ships::SUBMARINE:
            return board->insert_ship(std::make_shared<Submarine>(top_left_corner, board, enemy_board));
    }
    throw std::invalid_argument("Invalid ship type");
}

int Ship::get_length(Ship::Ships ship_type) {
    switch (ship_type) {
        case Ship::Ships::ARMOURED:
            return Armoured::armouredShipLength;
        case Ship::Ships::SUPPORT:
            return Supporter::supporterShipLength;
        case Ship::Ships::SUBMARINE:
            return Submarine::submarineLength;
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
    return action_->do_action(get_center(), target);
}

unsigned int Ship::get_pieces_amount() const {
    return pieces_amount_;
}

const Point &Ship::get_center() const {
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

void Ship::set_center(const Point &center) {
    center_ = center;
}

void Ship::hit(const Point &point) {
    for(auto &piece : pieces_) {
        if(piece.get_position() == point) {
            piece.hit();
            health_--;
            return;
        }
    }
    throw std::invalid_argument("Unable to find piece for that point");
}

void Ship::heal() {
    for(auto &piece : pieces_) {
        piece.heal();
    }
    health_ = max_health_;
}
