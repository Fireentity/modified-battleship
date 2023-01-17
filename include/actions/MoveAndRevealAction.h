//Lorenzo Croce 2034738

#ifndef MOVEANDREVEAL_H
#define MOVEANDREVEAL_H

#include "ship/Ship.h"
#include "board/Board.h"
#include "Action.h"

/**
 * Questa classe permette eseguire un'azione che modifica lo stato interno delle navi e della board in modo
 * controllato senza rendere accessibili all'esterno metodi setter o getter (non const).
 * In particolare permette di rivelare una nave avversaria
 */
class MoveAndRevealAction : public Action {
private:
    static const int range;
public:
    MoveAndRevealAction(const std::shared_ptr<Board> &board_, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //MOVEANDREVEAL_H
