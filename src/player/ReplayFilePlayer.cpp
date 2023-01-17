//Alberto Bottari 2034728

#include "player/ReplayConsolePlayer.h"

ReplayConsolePlayer::ReplayConsolePlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                         const std::shared_ptr<Logger> &moves_logger,
                                         const std::shared_ptr<Logger> &info_logger,
                                         const std::string &name, const std::function<void()> &change_turn,
                                         const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                                         const std::vector<std::string>::const_iterator &end)
        : ReplayFilePlayer(board, enemy_board, moves_logger, info_logger, name, change_turn, moves_iterator, end) {

    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}

void ReplayConsolePlayer::place_ships_inside_board() {
    ReplayFilePlayer::place_ships_inside_board();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ReplayConsolePlayer::do_move() {
    ReplayFilePlayer::do_move();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
