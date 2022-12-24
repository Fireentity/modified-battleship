#include "Player.h"

//Inizializzazione statica delle navi disponibili nella flotta
const std::vector<Player::Ships> Player::available_ships = {
        ARMOURED, ARMOURED, ARMOURED, SUBMARINE, SUBMARINE, SUPPORT, SUPPORT, SUPPORT
};

//Inizializzazione statica della factory
const std::unordered_map<Player::Ships, std::function<std::shared_ptr<Ship>(int, int, bool,std::shared_ptr<DefenceBoard>)>> Player::factory = {
        {
                Ships::ARMOURED,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return ArmouredShip::make_ship_or_null(x,y,horizontal, defence_board);
                }
        },
        {
                Ships::SUPPORT,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return Supporter::make_ship_or_null(x,y, horizontal,defence_board);
                }
        },
        {
                Ships::SUBMARINE,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return Submarine::make_ship_or_null(x,y,defence_board);
                }
        }
};
