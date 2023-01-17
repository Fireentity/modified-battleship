//Lorenzo Croce 2034738

#ifndef MOVEANDHEALACTION_H
#define MOVEANDHEALACTION_H

#include "Point.h"
#include "ship/Ship.h"
#include "Action.h"

/**
 * Questa classe permette eseguire un'azione che modifica lo stato interno delle navi e della board in modo
 * controllato senza rendere accessibili all'esterno metodi setter o getter (non const).
 * In particolare permette di curare una propria nave
 */
class MoveAndHealAction : public Action {
private:
    static const int range;
public:
    MoveAndHealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //MOVEANDHEALACTION_H
