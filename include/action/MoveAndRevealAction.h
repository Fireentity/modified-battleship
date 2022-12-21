#ifndef MOVEANDREVEAL_H
#define MOVEANDREVEAL_H

#include "ship/Ship.h"

class MoveAndRevealAction : public Board::Action {
private:
    static const int range;
public:
    MoveAndRevealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &target) override;
};

#endif //MOVEANDREVEAL_H
