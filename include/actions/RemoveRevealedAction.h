#ifndef REMOVEREVEALEDACTION_H
#define REMOVEREVEALEDACTION_H


#include "board/Board.h"

class RemoveRevealedAction : public Board::Action{
public:
    bool do_action(const Point &target) override;
};


#endif //REMOVEREVEALEDACTION_H
