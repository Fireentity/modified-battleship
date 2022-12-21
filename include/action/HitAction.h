#ifndef HITACTION_H
#define HITACTION_H

#include "Point.h"
#include "ship/Ship.h"


class HitAction : public Board::Action {
    bool do_action(const Point &target) override;
};

#endif //HITACTION_H
