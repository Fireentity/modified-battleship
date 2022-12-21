#ifndef MOVEANDREVEAL_H
#define MOVEANDREVEAL_H

#include "board/Board.h"

class MoveAndRevealAction : public Board::Action {
private:
    static const int range;
public:
    bool do_action(const Point &target) override;
};

#endif //MOVEANDREVEAL_H
