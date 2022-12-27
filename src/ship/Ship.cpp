#include "ship/Ship.h"

Ship::Ship(const Point &top_left_corner, int width, int height, unsigned short pieces_amount,
           const std::shared_ptr<Board::Action> &action) : center_{top_left_corner+Point{width/2,height/2}},
                                                           pieces_amount_{pieces_amount},
                                                           pieces_{pieces_amount},
                                                           health_{pieces_amount},
                                                           width_{width},
                                                           height_{height},
                                                           max_health_{pieces_amount},
                                                           action_{action} {
    int index = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pieces_[index].move_to(top_left_corner + Point{j,i});
            index++;
        }
    }
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
    for(auto &piece : pieces_) {
        if(piece.get_position().get_x() == x && piece.get_position().get_y() == y) {
            return piece.is_hit()?get_damaged_character():get_character();
        }
    }
    throw std::invalid_argument("Unable to find piece for that point");
}

const std::vector<ShipPiece> &Ship::get_pieces() const {
    return pieces_;
}
