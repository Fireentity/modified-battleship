//
// Created by lorenzo on 12/21/22.
//
#include "ship/Supporter.h"

const unsigned short Supporter::range = 1;
const char Supporter::character = 'S';

Supporter::Supporter(const Point & point,
                     unsigned short width,
                     unsigned short height,
                     unsigned short health) : Ship(x, y, width, height, health) {

}

char Supporter::get_character() const {
    return Supporter::character;
}

template <int N>
void DefenceBoard::insert_into(const BoardPiece (&piece)[N][N]) const {
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


