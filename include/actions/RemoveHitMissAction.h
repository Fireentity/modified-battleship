
#ifndef REMOVEMISSACTION_H
#define REMOVEMISSACTION_H


#include "board/Board.h"

class RemoveMissAction0 : public Board::Action{
public:
    bool do_action(const Point &target) override;
};


#endif //REMOVEMISSACTION_H
