#ifndef REPLAYPLAYER_H
#define REPLAYPLAYER_H

#include <fstream>
#include "ship/Armoured.h"
#include "ship/Supporter.h"
#include "board/Board.h"
#include "Player.h"
#include "commands/ShipPlaceCommand.h"
#include "commands/ShipActionCommand.h"
#include <thread>


class ReplayPlayer : public Player {
public:
    void place_ships_inside_board() override;

    void do_move() override;

    //TODO fix this
    ReplayPlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                 const std::shared_ptr<Logger> &logger, const std::shared_ptr<Logger> &output_logger,
                 const std::function<void()> &change_turn,
                 const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                 const std::vector<std::string>::const_iterator &end_iterator, const std::string &file_name);

private:
    std::shared_ptr<std::vector<std::string>::const_iterator> moves_iterator_;
    const std::vector<std::string>::const_iterator end_iterator_;
    ShipPlaceCommand place_command_;
    std::shared_ptr<Logger> logger_;
    const std::string file_name_;

    void print();
};


#endif //REPLAYPLAYER_H
