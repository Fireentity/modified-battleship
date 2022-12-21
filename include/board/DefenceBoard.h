#ifndef DEFENCEBOARD_H
#define DEFENCEBOARD_H

#include <vector>
#include "BoardPiece.h"

class DefenceBoard {
public:
    static const unsigned short dim = 12;
    explicit DefenceBoard(const std::vector<std::shared_ptr<Ship>>&);
private:
    BoardPiece board_[dim][dim];
};

#endif //DEFENCEBOARD_H
