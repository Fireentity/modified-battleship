#include "board/Board.h"

bool Board::is_out(unsigned int x, unsigned int y) {
    return x > Board::width || y > Board::height;
}

bool Board::is_out(const Point &point) {
    return point.get_x() > width || point.get_y() > height;
}

BoardSlot &Board::get_slot(unsigned int x, unsigned int y) {
    if (is_out(x, y)) {
        throw std::invalid_argument("Position out of bounds");
    }
    //Le coordinate sono invertite perché si usano i normali assi cartesiani e non le coordinate delle matrici
    return this->board_[y][x];
}

BoardSlot &Board::get_slot(const Point &point) {
    return get_slot(point.get_x(), point.get_y());
}

void Board::set_slot(int i, int j, const BoardSlot &object) {
    if (j >= Board::width || i >= Board::height) {
        throw std::invalid_argument("Position out of bounds");
    }

    board_[i][j] = BoardSlot{object};
}
