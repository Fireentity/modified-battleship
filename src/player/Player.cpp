#include "player/Player.h"

const int Player::firstUpperCaseLetter = 65;

//Inizializzazione statica delle navi disponibili nella flotta
//Non potendo usare file di configurazione la flotta è stata così implementata
const std::vector<Ship::Ships> Player::available_ships = {
        Ship::Ships::ARMOURED, Ship::Ships::SUBMARINE, Ship::Ships::SUPPORT, Ship::Ships::SUPPORT, Ship::Ships::SUPPORT
};

Player::Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : board_{board},
                                                                                                 enemy_board_{enemy_board} {

}

std::shared_ptr<Board> Player::get_board() const {
    return board_;
}

std::shared_ptr<Board> Player::get_enemy_board() const {
    return enemy_board_;
}
