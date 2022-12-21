#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <functional>
#include "ship/Ship.h"
#include "ship/ArmouredShip.h"

class Player {
public:
    enum Ships {
        ARMOURED,
        SUPPORT,
        SUBMARINE
    };

    static const std::vector<Ships> available_ships;
    static const std::unordered_map<Ships,std::function<std::shared_ptr<Ship>(int,int,bool,const std::shared_ptr<DefenceBoard> &)>> factory;
    virtual std::shared_ptr<DefenceBoard> place_ships_inside_board() = 0;

};

#endif //PLAYER_H
