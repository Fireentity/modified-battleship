#ifndef FINALE_AI_H
#define FINALE_AI_H

#include "action/MoveAndRevealAction.h"
#include "ship/ArmouredShip.h"
#include "ship/SupporterShip.h"
#include "board/Board.h"
#include "Player.h"

class AI : public Player {
public:
    AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);
    static bool instantiate_ship(Ship::Ships ship_type, const Point &bow, bool horizontal, const std::shared_ptr<Board> &board,
                                 const std::shared_ptr<Board> &enemy_board);
    void place_ships_inside_board() override;
    void do_move() override;
};

#endif //FINALE_AI_H
