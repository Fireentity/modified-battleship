#ifndef HITACTION_H
#define HITACTION_H

#include "Point.h"
#include "ship/Ship.h"
#include "board/Board.h"

class HitAction : public Board::Action {
public:
    HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //HITACTION_H
