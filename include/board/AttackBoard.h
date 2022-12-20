#ifndef ATTACKBOARD_H
#define ATTACKBOARD_H

#include "../../src/board/Board.hpp"

class AttackBoard: public Board<char,12,12> {
public:
    static const char hit = 'X';
    static const char miss = 'O';
    static const char empty = ' ';

    AttackBoard();
};

#endif //ATTACKBOARD_H
