#include "board/AttackBoard.h"

const char AttackBoard::empty = ' ';
const char AttackBoard::miss = 'O';
const char AttackBoard::hit = 'X';
const char AttackBoard::revealed = 'Y';

AttackBoard::AttackBoard() : Board{empty} {

}

std::ostream &operator<<(std::ostream &os, const AttackBoard &board) {
    for(int i = 0; i < board.get_height(); i++) {
        for(int j = 0; j < board.get_width(); j++) {
            os << board.get_slot(i,j);
        }
    }
    return os;
}
