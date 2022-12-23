#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <ostream>
#include <memory>
#include "BoardSlot.h"
//TODO fix this include
#include "../../src/board/Board.hpp"

class DefenceBoard: public Board<BoardSlot,12,12> {
public:
    explicit DefenceBoard();
};

#endif //DEFENCEBOARD_H
