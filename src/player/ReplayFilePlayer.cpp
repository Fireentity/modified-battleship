#include "player/ReplayConsolePlayer.h"

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
ReplayConsolePlayer::ReplayConsolePlayer(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
                                         const std::shared_ptr<Logger> &moves_logger,
                                         const std::shared_ptr<Logger> &info_logger,
                                         const std::string &name, const std::function<void()> &change_turn,
                                         const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
                                         const std::vector<std::string>::const_iterator &end)
        : ReplayFilePlayer(board, enemy_board, moves_logger, info_logger, name, change_turn, moves_iterator, end) {

    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}

void ReplayConsolePlayer::do_move() {
    ReplayFilePlayer::do_move();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
