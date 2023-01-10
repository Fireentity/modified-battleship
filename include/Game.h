#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <thread>
#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"
#include "commands/Command.h"
#include "commands/RemoveHitCommand.h"
#include "player/ReplayPlayer.h"


class Game {
public:
    enum GameType {
        AI_VS_AI,
        HUMAN_VS_AI //HUMAN è il player_2
    };

    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai();

    static Game make_ai_vs_ai();

    static Game
    make_replay(const std::vector<std::string> &moves, bool print_in_terminal, const std::string &file_name);

    void start_loop();

private:
    static const std::string logFileName;
    static const unsigned int maxMoves;
    //true turno del player 1
    bool turn_;
    int moves_;
    std::shared_ptr<Player> player_1_;
    std::shared_ptr<Player> player_2_;

    Game(GameType game_type, const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<Logger> &logger);

    Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<Logger> &logger,
         const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
         const std::vector<std::string>::const_iterator &end_iterator, bool print_in_terminal,
         const std::string &file_name);
};

#endif //GAME_H