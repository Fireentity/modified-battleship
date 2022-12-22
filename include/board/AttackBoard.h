#ifndef ATTACKBOARD_H
#define ATTACKBOARD_H

#include <ostream>
#include "../../src/board/Board.hpp"

class AttackBoard : public Board<char, 12, 12> {
public:
    static const char revealed;
    static const char hit;
    static const char miss;
    static const char empty;

    AttackBoard();
};

std::ostream &operator<<(std::ostream &os, const AttackBoard &board);

#endif //ATTACKBOARD_H
