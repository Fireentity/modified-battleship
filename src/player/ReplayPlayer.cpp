#include "player/ReplayPlayer.h"

void ReplayPlayer::place_ships_inside_board() {
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size() && *moves_iterator_ < end_iterator_) {
        if (place_command_.execute(**moves_iterator_)) {
            (*moves_iterator_)++;
            i++;
        }
    }
    logger_->log(board_->to_string()).log("\n");
}

void ReplayPlayer::do_move() {
    //Controllo che le mosse non siano finite
    if (*moves_iterator_ < end_iterator_) {
        if (dispatch_command(**moves_iterator_)) {
            //Incremento l'iteratore delle mosse dereferenziando il puntatore salvato come field
            (*moves_iterator_)++;
        } else {
            throw std::invalid_argument("Invalid move from file!");
        }
        //Loggo la mossa
        logger_->log(board_->to_string()).log("\n");
    }
}

ReplayPlayer::ReplayPlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                           const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &output_logger,
                           const std::function<void()> &change_turn,
                           const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                           const std::vector<std::string>::const_iterator &end)
        : Player{board, enemy_board}, place_command_{board, enemy_board, moves_logger}, moves_iterator_{moves_iterator},
          end_iterator_{end},
          logger_{output_logger} {
    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}
