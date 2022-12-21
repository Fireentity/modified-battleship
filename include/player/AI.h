#ifndef FINALE_AI_H
#define FINALE_AI_H

#include "board/Board.h"
#include "Player.h"

class AI : public Player {
private:
    Board> board;
    std::vector<std::shared_ptr<Ship>> ships;
public:
    static const std::unordered_map<Ships,std::function<bool(Point,bool,std::shared_ptr<Board>)>> factory;
    std::shared_ptr<Board> place_ships_inside_board() override;
    void do_move(Board &enemy_board) override;
};

#endif //FINALE_AI_H
