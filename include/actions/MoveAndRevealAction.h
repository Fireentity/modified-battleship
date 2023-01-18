//Lorenzo Croce 2034738

#ifndef MOVEANDREVEAL_H
#define MOVEANDREVEAL_H

#include "ship/Ship.h"
#include "board/Board.h"
#include "Action.h"

/**
 * Questa classe implementa la rivelazione di una nave avversaria
 */
class MoveAndRevealAction : public Action {
public:
    static const int range;
    MoveAndRevealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //MOVEANDREVEAL_H
