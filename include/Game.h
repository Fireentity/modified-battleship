#ifndef GAME_H
#define GAME_H

#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"
#include "commands/Command.h"

class Game {
private:
    std::vector<std::shared_ptr<Command>> commands;
    //Vengono utilizzati dei puntatori per evitare lo slicing.
    //Gli shared_ptr sostituiscono soltanto i raw pointers
    static const unsigned int maxMoves = 30;
    bool turn = rand()%2; //true turno del player 1
    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;
    Game(const AI &player_1, const Human &player_2);
    Game(const AI &player_1, const AI &player_2);
public:

    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai() {
        std::shared_ptr<Board> board_1 = std::make_shared<Board>();
        std::shared_ptr<Board> board_2 = std::make_shared<Board>();
        return Game{AI{board_1,board_2},Human{board_2,board_1}};
    }

    static Game make_ai_vs_ai() {
        std::shared_ptr<Board> board_1 = std::make_shared<Board>();
        std::shared_ptr<Board> board_2 = std::make_shared<Board>();
        return Game{AI{board_1,board_2},AI{board_2,board_1}};
    }

    void start_loop();
};

#endif //GAME_H