#include "ship/LinearShip.h"
class ArmouredShip;

LinearShip::LinearShip(int x, int y, unsigned short width, unsigned short height, unsigned short health,
                       unsigned short max_health, const std::shared_ptr<DefenceBoard> &defence_board, bool horizontal)
        : Ship{Point{x, y}, width, height, health, max_health, defence_board}, horizontal_{horizontal} {

    unsigned int length = std::max(width, height);
    std::vector<std::shared_ptr<ShipPiece>> pieces{length};
    for(int i = 0; i < length; i++) {
        Point position{this->get_center_x(), this->get_center_y()};

        if(is_horizontal()) {
            position.x_ += -(length/2) + i;
        } else {
            position.y_ += -(length/2) + i;
        }

        std::shared_ptr<LinearShip> shared_prt{};
        shared_prt.reset(this);
        pieces[i] = std::make_shared<ShipPiece>(position,defence_board,shared_prt);
    }

    bool can_place = std::all_of(pieces.begin(), pieces.end(),[](const std::shared_ptr<ShipPiece> &piece){
        return piece->can_move(piece->get_position().x_, piece->get_position().y_);
    });

    if(!can_place) {
        throw std::invalid_argument("Cannot place ship at that position");
    }

    this->move(x,y);
}

bool LinearShip::is_horizontal() const {
    return horizontal_;
}


void LinearShip::move(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    for (auto &iterated_piece: pieces_) {
        const Point &position = iterated_piece->get_position();
        iterated_piece->move(position.x_ + move_x, position.y_ + move_y);
    }
}

bool LinearShip::is_valid_position(int x, int y) {
    int move_x = x - get_center_x();
    int move_y = y - get_center_y();
    return std::all_of(pieces_.begin(), pieces_.end(), [move_x, move_y](const std::shared_ptr<ShipPiece> &piece) {
        return piece->can_move(piece->get_position().x_ + move_x, piece->get_position().y_ + move_y);
    });

}

bool LinearShip::place() {
    if(!this->is_valid_position(position_.x_, position_.y_)) {
        return false;
    }

    move(position_.x_,position_.y_);
}
