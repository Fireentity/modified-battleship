#include "player/ReplayPlayer.h"

void ReplayPlayer::place_ships_inside_board() {
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size() && *moves_iterator_ != end_iterator_) {
        if (place_command_.execute(**moves_iterator_)) {
            (*moves_iterator_)++;
            i++;
        }
    }
    logger_->log(board_->to_string());
}

void ReplayPlayer::do_move() {
    while (*moves_iterator_ != end_iterator_) {
        if (dispatch_command(**moves_iterator_)) {
            (*moves_iterator_)++;
        } else {
            throw std::invalid_argument("Invalid move from file!");
        }
        logger_->log(board_->to_string());
    }
}

ReplayPlayer::ReplayPlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                           const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &output_logger,
                           const std::function<void()> &change_turn,
                           const std::shared_ptr<std::vector<std::string>::const_iterator> &begin,
                           const std::vector<std::string>::const_iterator &end) : Player{board, enemy_board},
                                                           place_command_{board, enemy_board, moves_logger},
                                                           moves_iterator_{begin},
                                                           end_iterator_{end},
                                                           logger_{moves_logger} {
    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}
