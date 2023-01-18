//Lorenzo Croce 2034738

#ifndef HITACTION_H
#define HITACTION_H

#include "Point.h"
#include "ship/Ship.h"
#include "Action.h"

/**
 * Questa classe implementa il codice necessario a colpire una nave avversaria
 */
class HitAction : public Action {
public:

    HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //HITACTION_H
