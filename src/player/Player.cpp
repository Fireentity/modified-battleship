#include "player/Player.h"

/**
 *
 * @param board la board del giocatore
 * @param enemy_board la board dell'avversario
 */
Player::Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : board_{board},
                                                                                                 enemy_board_{
                                                                                                         enemy_board} {
}

/**
 *
 * @return ritorna un puntatore ad un oggetto const Board
 */
std::shared_ptr<const Board> Player::get_board() const {
    return board_;
}

/**
 * Metodo per registrare un comando eseguibile dal giocatore
 * @param command puntatore all'istanza del comando
 */
void Player::register_command(const std::shared_ptr<Command> &command) {
    commands_.push_back(command);
}

/**
 * Metodo che permette di eseguire un comando data la stringa in input
 * @param command stringa del comando da eseguire
 * @return ritorna true se il comando viene eseguito correttamente false altrimenti
 */
bool Player::dispatch_command(const std::string &command) {
    for (auto &iterated_command: commands_) {
        if (iterated_command->check_command(command)) {
            return iterated_command->execute(command);
        }
    }
    return false;
}
