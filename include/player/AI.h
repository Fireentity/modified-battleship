#ifndef FINALE_AI_H
#define FINALE_AI_H

#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "board/Board.h"
#include "Player.h"
#include "commands/ShipPlaceCommand.h"
#include "commands/ShipActionCommand.h"
#include "logger/ConsoleLogger.h"
#include "RandomNumber.h"

class AI : public Player {
private:
    ShipPlaceCommand place_command_;
    ShipActionCommand action_command_;
    RandomNumber random_numbers;
public:
    AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
       const std::shared_ptr<Logger> &moves_logger, const std::function<void()> &change_turn);

    void place_ships_inside_board() override;

    void do_move() override;
};

#endif //FINALE_AI_H
