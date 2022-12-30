#ifndef HUMAN_H
#define HUMAN_H

#include "board/Board.h"
#include "Player.h"
#include <iostream>
#include <regex>

class Human : public Player {
private:
    bool place_in_board(Ship::Ships ship);
    bool ask_action();
public:
    Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    void do_move() override;

    void place_ships_inside_board() override;
};

#endif //HUMAN_H
