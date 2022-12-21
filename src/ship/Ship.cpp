#include "ship/Ship.h"
#include "board/DefenceBoard.h"
#include <algorithm>
#include <stdexcept>

Ship::Ship(const std::pair<int,int> &position,
           unsigned short width,
           unsigned short height,
           unsigned short health): position_{position},width_{width},height_{height},health_{health} {

}

unsigned short Ship::get_x() const {
    return this->position_.first;
}

unsigned short Ship::get_y() const {
    return this->position_.second;
}

unsigned short Ship::get_width() const {
    return width_;
}

unsigned short Ship::get_height() const {
    return height_;
}

unsigned short Ship::get_health() const {
    return health_;
}

//TODO move into hpp
template <int N>
void Ship::insert_into(const BoardPiece (& board) [N][N]) const {
    int dim = std::max(height_,width_);
    std::pair<int,int> occupied_position[dim];

    if(height_ == 1 && width_ == 1) {
        occupied_position[0] = position_;
    } else if(height_ == 1 || width_==1) {
        for(int i = 0; i < dim; i++) {
            occupied_position[i] = std::pair<int,int>{position_.first,position_.second-(dim/2)+i};
        }
    } else {
        throw std::invalid_argument("Invalid shape of ship");
    }

    for(auto position : occupied_position) {
        //Questa exception non dovrebbe mai essere lanciata salvo nel caso in cui il programmatore
        //usi male questa classe
        if(position.first > N || position.second > N || position.first < 0 || position.second < 0) {
            throw std::invalid_argument("Position out of the board");
        }
        if(board[position.first][position.second].get_ship() != nullptr) {
            throw std::invalid_argument("Position already occupied by another ship");
        }
        board[position.first][position.second].get_ship() = std::make_shared<Ship>(this);
    }
}
