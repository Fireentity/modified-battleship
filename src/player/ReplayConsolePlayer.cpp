//Alberto Bottari 2034728

#include "player/ReplayFilePlayer.h"

/**
 *
 * @param board la board del giocatore
 * @param enemy_board la board dell'avversario
 * @param moves_logger il logger delle mosse eseguite da questo giocatore
 * @param info_logger il logger della defence board e attackboard
 * @param change_turn la funzione che viene eseguita quando correttamente un'azione
 * @param moves_iterator puntatore all'iteratore delle mosse
 * @param end l'ultimo elemento dell'iteratore delle mosse
 */
ReplayFilePlayer::ReplayFilePlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                   const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &info_logger,
                                   const std::string &name, const std::function<void()> &change_turn,
                                   const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                                   const std::vector<std::string>::const_iterator &end)
        : Player{board, enemy_board, name}, place_command_{board, enemy_board, moves_logger},
          moves_iterator_{moves_iterator},end_iterator_{end},logger_{info_logger} {

    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}

void ReplayFilePlayer::place_ships_inside_board() {
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size() && *moves_iterator_ < end_iterator_) {
        logger_->log(name_ + " posiziona: ");
        if (place_command_.execute(**moves_iterator_)) {
            (*moves_iterator_)++;
            i++;
        } else {
            throw std::invalid_argument("Invalid move from file!");
        }
    }
    logger_->log(board_->to_string()).log("\n");
}

void ReplayFilePlayer::do_move() {
    //Controllo che le mosse non siano finite
    logger_->log(name_ + " esegue: ");
    if (*moves_iterator_ < end_iterator_) {
        if (dispatch_command(**moves_iterator_)) {
            //Incremento l'iteratore delle mosse dereferenziando il puntatore salvato come field
            (*moves_iterator_)++;
            logger_->log(board_->to_string()).log("\n");
        } else {
            throw std::invalid_argument("Invalid move from file!");
        }
    } else {
        throw std::invalid_argument{"Not enough moves in log file"};
    }

}
