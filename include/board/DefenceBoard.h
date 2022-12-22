#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <vector>
#include <ostream>
#include <memory>
#include "ship/Ship.h"
#include "BoardPiece.h"
//TODO fix this include
#include "../../src/board/Board.hpp"

class DefenceBoard: public Board<BoardPiece,12,12> {
public:
    explicit DefenceBoard(const std::vector<std::shared_ptr<Ship>> &ships);
};

#endif //DEFENCEBOARD_H
