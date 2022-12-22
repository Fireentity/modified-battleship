#ifndef FINALE_AI_H
#define FINALE_AI_H

#include "action/MoveAndRevealAction.h"
#include "ship/ArmouredShip.h"
#include "ship/SupporterShip.h"
#include "board/Board.h"
#include "Player.h"

class AI : public Player {
private:
    std::vector<std::shared_ptr<Ship>> ships;
public:
    AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);
    static bool instantiate_ship(Player::Ships ship_type, const Point &bow, bool horizontal, const std::shared_ptr<Board> &board,
                                 const std::shared_ptr<Board> &enemy_board);
    void place_ships_inside_board() override;
    void do_move(Board &enemy_board) override;
};

#endif //FINALE_AI_H
