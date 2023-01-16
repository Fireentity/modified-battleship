#include "ship/Ship.h"

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
    return (*get_piece(x, y)).is_hit() ? get_damaged_character() : get_character();
}

char Ship::get_piece_character(const Point &position) const {
    return get_piece_character(position.get_x(), position.get_y());
}

std::vector<ShipPiece> &Ship::get_pieces() {
    return pieces_;
}

void Ship::set_center(const Point &center) {
    center_ = center;
}

void Ship::hit(const Point &point) {
    pieces_[get_piece(point.get_x(), point.get_y())-pieces_.begin()].hit();
    health_--;
}

void Ship::heal() {
    for (auto &piece: pieces_) {
        piece.heal();
    }
    health_ = max_health_;
}

std::vector<ShipPiece>::const_iterator Ship::get_piece(unsigned int x, unsigned int y) const {
    auto iter = std::find_if(pieces_.begin(), pieces_.end(), [x, y](const ShipPiece &piece) {
        return piece.get_position().get_x() == x && piece.get_position().get_y() == y;
    });
    if(iter!=pieces_.end()){
        return iter;
    }
    throw std::invalid_argument("Unable to find piece for that point");
}
