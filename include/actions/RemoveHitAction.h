#ifndef REMOVEHITACTION_H
#define REMOVEHITACTION_H

#include "board/Board.h"
class RemoveHitAction : public Board::Action {
public:
    RemoveHitAction(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemyBoard);
    bool do_action(const Point &point) override;
};


#endif //REMOVEHITACTION_H
