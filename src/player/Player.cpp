#include "player/Player.h"

//Inizializzazione statica delle navi disponibili nella flotta
//Non potendo usare file_ di configurazione la flotta è stata così implementata
const std::vector<Ship::Ships> Player::available_ships = {
        Ship::Ships::ARMOURED, Ship::Ships::SUBMARINE, Ship::Ships::SUPPORT, Ship::Ships::SUPPORT, Ship::Ships::SUPPORT
};

Player::Player(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board) : board_{board},
                                                                                                 enemy_board_{enemy_board} {

}

std::shared_ptr<const Board> Player::get_board() const{
    return board_;
}
