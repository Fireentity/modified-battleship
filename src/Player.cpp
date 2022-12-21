#include "Player.h"

const std::vector<Player::Ships> Player::available_ships = {
        ARMOURED, ARMOURED, ARMOURED, SUBMARINE, SUBMARINE, SUPPORT
};

const std::unordered_map<Player::Ships, std::function<std::shared_ptr<Ship>(int, int, bool,const std::shared_ptr<DefenceBoard> &)>> Player::factory = {
        {
                Ships::ARMOURED,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return std::make_shared<ArmouredShip>(x, y, horizontal, defence_board);
                }
        },
        {
                Ships::SUPPORT,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return std::make_shared<ArmouredShip>(x, y, horizontal, defence_board);
                }
        },
        {
                Ships::SUBMARINE,
                [](int x, int y, bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board) {
                    return std::make_shared<ArmouredShip>(x, y, horizontal, defence_board);
                }
        }
};
