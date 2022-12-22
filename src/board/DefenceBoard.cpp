#include "board/DefenceBoard.h"

DefenceBoard::DefenceBoard(const std::vector<std::shared_ptr<Ship>> &ships) : Board{BoardPiece{}} {
    for(const std::shared_ptr<Ship> &ship : ships) {
        ship->place(*this);
    }
}

std::ostream &operator<<(std::ostream &os, const DefenceBoard &board) {
    for(int i = 0; i < board.get_height(); i++) {
        for(int j = 0; j < board.get_width(); j++) {
            os << board.get_slot(i,j);
        }
    }

    return os;
}
