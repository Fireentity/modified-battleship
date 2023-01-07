#include <chrono>
#include <thread>
#include "Game.h"

const unsigned int Game::maxMoves = 30;
const std::string Game::logName = "moves_.txt";

Game::Game(GameType game_type, const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<Logger> &logger) : turn_(false), moves_{0} {

    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn_ = !this->turn_;
        //Incrementa il contatore delle mosse
        moves_++;
    };

    switch (game_type) {
        case GameType::HUMAN_VS_AI: {
            player_1_ = std::make_shared<AI>(board_1, board_2, logger, on_action_success);
            player_2_ = std::make_shared<Human>(board_2, board_1, logger, on_action_success);
            break;
        }
        case GameType::AI_VS_AI: {
            player_1_ = std::make_shared<AI>(board_1, board_2, logger, on_action_success);
            player_2_ = std::make_shared<AI>(board_2, board_1, logger, on_action_success);
            break;
        }
    }
}

void Game::start_loop() {
    player_1_->place_ships_inside_board();
    player_2_->place_ships_inside_board();
    do {
        if (turn_) {
            player_1_->do_move();
        } else {
            player_2_->do_move();
        }
        //Il contatore delle mosse non viene incrementato qua ma nel comando che esegue l'azione
        //del giocatore
    } while (moves_ <= maxMoves);
}

Game Game::make_human_vs_ai() {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    std::shared_ptr<Logger> logger = std::make_shared<Logger>(logName);
    return Game{GameType::HUMAN_VS_AI, board_1, board_2, logger};
}

Game Game::make_ai_vs_ai() {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    std::shared_ptr<Logger> logger = std::make_shared<Logger>(logName);
    return Game{GameType::AI_VS_AI, board_1, board_2, logger};
}




