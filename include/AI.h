#ifndef FINALE_AI_H
#define FINALE_AI_H

#include "board/DefenceBoard.h"
#include "Player.h"

class AI : public Player {
private:
    std::shared_ptr<DefenceBoard> defence_board;
public:
    std::shared_ptr<DefenceBoard> place_ships_inside_board() override;
};

#endif //FINALE_AI_H
