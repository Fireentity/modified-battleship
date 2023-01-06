#include <chrono>
#include <thread>
#include "Game.h"

const unsigned int Game::maxMoves = 30;
const std::string Game::logName = "moves.txt";

Game::Game(GameType game_type, const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<Logger> &logger) : turn(rand() % 2), moves{0} {

    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn = !this->turn;
        //Incrementa il contatore delle mosse
        moves++;
    };

    switch (game_type) {
        case GameType::HUMAN_VS_AI: {
            player_1 = std::make_shared<AI>(board_1, board_2, logger, on_action_success);
            player_2 = std::make_shared<Human>(board_2, board_1, logger, on_action_success);
            break;
        }
        case GameType::AI_VS_AI: {
            player_1 = std::make_shared<AI>(board_1, board_2, logger, on_action_success);
            player_2 = std::make_shared<AI>(board_2, board_1, logger, on_action_success);
            break;
        }
    }

}

void Game::start_cc_loop() {
    player_1->place_ships_inside_board();
    player_1->get_board()->print_with_ships();
    player_2->place_ships_inside_board();
    player_2->get_board()->print_with_ships();
    do {
        if (turn) { //TODO sistemare la stampa
            player_1->do_move();
            std::cout<<"Player 1"<<std::endl;
            player_1->get_board()->print_with_ships();
            player_1->get_board()->print_without_ships();
        } else {
            player_2->do_move();
            std::cout<<"Player 2"<<std::endl;
            player_2->get_board()->print_with_ships();
            player_2->get_board()->print_without_ships();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //Il contatore delle mosse non viene incrementato qua ma nel comando che esegue l'azione
        //del giocatore
    } while (moves <= maxMoves);
}

void Game::start_pc_loop() {
    player_1->place_ships_inside_board();
    player_2->place_ships_inside_board();
    do {
        if (turn) {
            player_1->do_move();
        } else { //giocatore umano
            std::cout<<"È il tuo turno: "<<std::endl;
            player_2->get_board()->print_with_ships(); //TODO fare il cambio di griglia con il comando apposito
            player_2->get_board()->print_without_ships();
            player_2->do_move(); //TODO non funzionano le azioni per il player
            //std::cout<<"Player 2"<<std::endl;
            player_2->get_board()->print_with_ships();
            player_2->get_board()->print_without_ships();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        //Il contatore delle mosse non viene incrementato qua ma nel comando che esegue l'azione
        //del giocatore
    } while (moves <= maxMoves);

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




