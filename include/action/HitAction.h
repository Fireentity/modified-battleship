#ifndef HITACTION_H
#define HITACTION_H

#include "board/Board.h"
#include "Point.h"

class HitAction : public Board::Action {
    bool do_action(const Point &target) override;
};

#endif //HITACTION_H
