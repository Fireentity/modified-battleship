#ifndef HUMAN_H
#define HUMAN_H

#include "board/Board.h"
#include "Player.h"
#include "commands/ShipPlaceCommand.h"
#include "commands/ShipActionCommand.h"
#include "commands/ShipCommand.h"
#include "commands/RemoveHitCommand.h"
#include <iostream>
#include <regex>

class Human : public Player {
private:
    ShipPlaceCommand place_command_;
    const std::shared_ptr<Logger> logger_;
public:
    Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
          const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &output_logger,
          const std::function<void()> &change_turn);

    void do_move() override;

    void place_ships_inside_board() override;
};

#endif //HUMAN_H
