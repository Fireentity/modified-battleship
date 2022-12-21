#include "player/Player.h"

//Inizializzazione statica delle navi disponibili nella flotta
//Non potendo usare file di configurazione la flotta è stata così implementata
const std::vector<Player::Ships> Player::available_ships = {
        ARMOURED, ARMOURED, ARMOURED, SUBMARINE, SUBMARINE, SUPPORT, SUPPORT, SUPPORT
};

//Inizializzazione statica della factory
const std::unordered_map<Player::Ships, std::function<std::shared_ptr<Ship>(Point, Point, std::shared_ptr<Board>)>> Player::factory = {
        {
                Player::Ships::ARMOURED,
                [](Point bow, Point stern, const std::shared_ptr<Board> &defence_board) {
                    return ArmouredShip::make_ship_or_null(bow, stern, defence_board);
                }
        },
        {
                Player::Ships::SUPPORT,
                [](Point bow, Point stern, const std::shared_ptr<Board> &defence_board) {
                    return Supporter::make_ship(bow, stern, defence_board);
                }
        },
        {
                Player::Ships::SUBMARINE,
                [](Point bow,Point stern, const std::shared_ptr<Board> &defence_board) {
                    return Submarine::make_ship(bow, stern, defence_board);
                }
        }
};

std::string Player::to_string(Ships ship) {
    switch (ship) {
        case Ships::ARMOURED:
            return "Corazzata";
        case Ships::SUPPORT:
            return "Supporto";
        case Ships::SUBMARINE:
            return "Sottomarino";
    }

    throw std::invalid_argument("Invalid ship type");
}
