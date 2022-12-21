#include "ship/Ship.h"
#include "board/DefenceBoard.h"

Ship::Ship(std::pair<int,int> position,
           unsigned short width,
           unsigned short height,
           unsigned short health): position_{position},width_{width},height_{height},health_{health} {

}

unsigned short Ship::get_x() const {
    return x_;
}

unsigned short Ship::get_y() const {
    return y_;
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
    std::vector<std::pair<int,int>> occupied_position {};
    board[this->get_x()][this->get_y()] = get_character();
}
