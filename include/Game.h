#ifndef GAME_H
#define GAME_H

#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"

class Game {
private:
    std::unique_ptr<Player> player_1;
    std::unique_ptr<Player> player_2;
public:
    Game();

    void start_loop();
};

#endif //GAME_H