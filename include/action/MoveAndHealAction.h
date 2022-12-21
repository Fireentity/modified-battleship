#ifndef MOVEANDHEALACTION_H
#define MOVEANDHEALACTION_H

#include "board/Board.h"
#include "Point.h"

class MoveAndHealAction : public Board::Action {
private:
    static const int range;
public:
    bool do_action(const Point &target) override;
};

#endif //MOVEANDHEALACTION_H
