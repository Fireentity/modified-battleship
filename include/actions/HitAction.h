#ifndef HITACTION_H
#define HITACTION_H

#include "Point.h"
#include "ship/Ship.h"
#include "board/Board.h"

/**
 * Questa classe permette eseguire un'azione che modifica lo stato interno delle navi e della board in modo
 * controllato senza rendere accessibili all'esterno metodi setter o getter (non const).
 * In particolare permette di colpire una nave avversaria
 */
class HitAction : public Board::Action {
public:

    HitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);
    bool do_action(const Point &ship_center, const Point &target) override;
};

#endif //HITACTION_H
