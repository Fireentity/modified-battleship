#ifndef GAME_H
#define GAME_H

#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"
#include "commands/Command.h"

class Game {
private:
    static const unsigned int maxMoves;
    //true turno del player 1
    bool turn;
    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;
    Game(const std::shared_ptr<AI> &ai, const std::shared_ptr<Human> &human);
    Game(const std::shared_ptr<AI> &ai, const std::shared_ptr<AI> &human);
public:

    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai() {
        std::shared_ptr<Board> board_1 = std::make_shared<Board>();
        std::shared_ptr<Board> board_2 = std::make_shared<Board>();
        return Game{std::make_shared<AI>(board_1,board_2),std::make_shared<Human>(board_2,board_1)};
    }

    static Game make_ai_vs_ai() {
        std::shared_ptr<Board> board_1 = std::make_shared<Board>();
        std::shared_ptr<Board> board_2 = std::make_shared<Board>();
        return Game{std::make_shared<AI>(board_1,board_2),std::make_shared<AI>(board_2,board_1)};
    }

    void start_loop();
};

#endif //GAME_H