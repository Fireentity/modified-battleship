#ifndef GAME_H
#define GAME_H

#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"

class Game {
private:
    //Vengono utilizzati dei puntatori per evitare lo slicing.
    //Gli shared_ptr sostituiscono soltanto i raw pointers
    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;
    Game(const AI &player_1, const Human &player_2);
    Game(const AI &player_1, const AI &player_2);
public:

    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai() {
        return Game{AI{},Human{}};
    }

    static Game make_ai_vs_ai() {
        return Game{AI{},AI{}};
    }

    void start_loop();
};

#endif //GAME_H