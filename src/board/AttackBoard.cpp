
#include <algorithm>
#include "board/AttackBoard.h"

AttackBoard::AttackBoard() {
    for(auto & i : this->board_) {
        for(char & j : i) {
            j = AttackBoard::empty;
        }
    }
}

void AttackBoard::set_slot(int x, int y, char character) {
    board_[x][y] = character;
}




