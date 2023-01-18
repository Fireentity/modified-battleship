//Lorenzo Croce 2034738

#ifndef MOVEANDHEALACTION_H
#define MOVEANDHEALACTION_H

#include "Point.h"
#include "ship/Ship.h"
#include "Action.h"

/**
 * Questa classe implementa il codice necessario a muovere il supporto e curare una curare una propria nave
 */
class MoveAndHealAction : public Action {
public:
    static const int range;
    MoveAndHealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //MOVEANDHEALACTION_H
