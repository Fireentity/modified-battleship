#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <vector>
#include "ship/Ship.h"
#include "BoardPiece.h"
#include "board/Board.hpp"

class DefenceBoard: public Board<BoardPiece,12,12> {
public:
    explicit DefenceBoard(const std::vector<std::shared_ptr<Ship>>&);
};

#endif //DEFENCEBOARD_H
