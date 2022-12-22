#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <vector>
#include <ostream>
#include <memory>
#include "ship/Ship.h"
#include "BoardPiece.h"
#include "../../src/board/Board.hpp"

class DefenceBoard: public Board<BoardPiece,12,12> {
public:
    explicit DefenceBoard(const std::vector<std::shared_ptr<Ship>> &ships);
};

std::ostream &operator<<(std::ostream &os, const DefenceBoard &board);

#endif //DEFENCEBOARD_H
