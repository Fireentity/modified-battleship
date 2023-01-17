//Marco Pavanetto 2032486

#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <thread>
#include <fstream>
#include "player/Player.h"
#include "player/Human.h"
#include "player/AI.h"
#include "commands/Command.h"
#include "commands/RemoveHitCommand.h"
#include "player/ReplayFilePlayer.h"
#include "player/ReplayConsolePlayer.h"
#include "logger/ConsoleLogger.h"
#include "logger/FileLogger.h"
#include "logger/Logger.h"

class Game {
public:
    //Si usa (static method factory design pattern) per creare le possibili configurazioni
    //di gioco: Human vs AI, AI vs AI ma si potrebbe implementare anche Human vs Human
    static Game make_human_vs_ai();

    static Game make_ai_vs_ai();

    static Game make_replay_console(const std::vector<std::string> &moves);
    
    static Game make_replay_file(const std::shared_ptr<FileLogger> &info_logger, const std::vector<std::string> &moves);

    void start_loop();

private:
    static const std::string logFileName;
    static const unsigned int maxMoves;
    //true turno del player 1
    bool turn_;
    int moves_ = 0;
    std::shared_ptr<Player> player_1_;
    std::shared_ptr<Player> player_2_;
    std::shared_ptr<Logger> info_logger_;

    Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &info_logger);

    Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<Logger> &moves_logger);

    Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<ConsoleLogger> &moves_logger,
         const std::shared_ptr<ConsoleLogger> &info_logger,
         const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
         const std::vector<std::string>::const_iterator &end_iterator);

    Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
         const std::shared_ptr<FileLogger> &moves_logger,
         const std::shared_ptr<FileLogger> &info_logger,
         const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
         const std::vector<std::string>::const_iterator &end_iterator);
};

#endif //GAME_H