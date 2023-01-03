#ifndef GAME_H
#define GAME_H

#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"
#include "commands/Command.h"
#include "commands/RemoveHitCommand.h"


class Game {
public:
    enum GameType {
        AI_VS_AI,
        HUMAN_VS_AI
    };

    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai();

    static Game make_ai_vs_ai();

    void start_loop();

private:
    static const std::string logName;
    static const unsigned int maxMoves;
    //true turno del player 1
    bool turn;
    int moves;
    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;
    Game(GameType game_type, const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<Logger> &logger);
};

#endif //GAME_H