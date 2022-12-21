#ifndef MOVEANDHEALACTION_H
#define MOVEANDHEALACTION_H

#include "Point.h"
#include "ship/Ship.h"

class MoveAndHealAction : public Board::Action {
private:
    static const int range;
public:
    MoveAndHealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &target) override;
};

#endif //MOVEANDHEALACTION_H
