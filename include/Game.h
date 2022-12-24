#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "AI.h"

class Game {
private:
    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;
public:
    Game();
};

#endif //GAME_H
