#include "Game.h"

const unsigned int Game::maxMoves = 10;
const std::string Game::logFileName = "moves.txt";

Game::Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<Logger> &logger, const std::shared_ptr<Logger> &info_logger)
        : turn_(RandomNumber::get_instance().get_int(0, 1)), info_logger_{info_logger} {
    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn_ = !this->turn_;
        //Incrementa il contatore delle mosse
        moves_++;
    };

    player_1_ = std::make_shared<AI>(board_1, board_2, logger, "Computer", on_action_success);
    player_2_ = std::make_shared<Human>(board_2, board_1, logger, info_logger, "Umano", on_action_success);
}

Game::Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<Logger> &logger) : turn_(RandomNumber::get_instance().get_int(0, 1)), info_logger_{logger} {
    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn_ = !this->turn_;
        //Incrementa il contatore delle mosse
        moves_++;
    };

    player_1_ = std::make_shared<AI>(board_1, board_2, logger, "Computer 1", on_action_success);
    player_2_ = std::make_shared<AI>(board_2, board_1, logger, "Computer 2", on_action_success);
}

Game::Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<ConsoleLogger> &moves_logger,
           const std::shared_ptr<ConsoleLogger> &info_logger,
           const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
           const std::vector<std::string>::const_iterator &end_iterator) : turn_(true), info_logger_{info_logger} {

    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn_ = !this->turn_;
        //Incrementa il contatore delle mosse
        moves_++;
    };
    player_1_ = std::make_shared<ReplayConsolePlayer>(board_1, board_2, moves_logger, info_logger, "Giocatore 1",
                                                      on_action_success, moves_iterator, end_iterator);
    player_2_ = std::make_shared<ReplayConsolePlayer>(board_2, board_1, moves_logger, info_logger, "Giocatore 2",
                                                      on_action_success, moves_iterator, end_iterator);
}

Game::Game(const std::shared_ptr<Board> &board_1, const std::shared_ptr<Board> &board_2,
           const std::shared_ptr<FileLogger> &moves_logger,
           const std::shared_ptr<FileLogger> &info_logger,
           const std::shared_ptr<std::vector<std::string>::const_iterator> &moves_iterator,
           const std::vector<std::string>::const_iterator &end_iterator) : turn_(true), info_logger_{info_logger} {

    //Viene eseguito in caso di successo
    std::function<void()> on_action_success = [this]() {
        //Quando viene eseguito il comando action viene cambiato il turno
        this->turn_ = !this->turn_;
        //Incrementa il contatore delle mosse
        moves_++;
    };
    player_1_ = std::make_shared<ReplayFilePlayer>(board_1, board_2, moves_logger, info_logger, "Giocatore 1",
                                                   on_action_success, moves_iterator, end_iterator);
    player_2_ = std::make_shared<ReplayFilePlayer>(board_2, board_1, moves_logger, info_logger, "Giocatore 2",
                                                   on_action_success, moves_iterator, end_iterator);
}

void Game::start_loop() {
    if (turn_) {
        player_1_->place_ships_inside_board();
        player_2_->place_ships_inside_board();
    } else {
        player_2_->place_ships_inside_board();
        player_1_->place_ships_inside_board();
    }

    do {
        if (turn_) {
            player_1_->do_move();
        } else {
            player_2_->do_move();
        }

        if (!player_1_->get_board()->has_ships()) {
            std::cout << "Il player 1 vince" << std::endl;
            return;
        }
        if (!player_2_->get_board()->has_ships()) {
            std::cout << "Il player 2 vince" << std::endl;
            return;
        }

        //Il contatore delle mosse non viene incrementato qua ma nel comando che esegue l'azione
        //del giocatore
    } while (moves_ <= maxMoves);
    std::cout << "Le mosse sono finite quindi l'esito è un pareggio" << std::endl;
}

Game Game::make_human_vs_ai() {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    std::shared_ptr<Logger> moves_logger = std::make_shared<FileLogger>(logFileName);
    std::shared_ptr<Logger> info_logger = std::make_shared<ConsoleLogger>();
    return Game{board_1, board_2, moves_logger, info_logger};
}

Game Game::make_ai_vs_ai() {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    std::shared_ptr<Logger> logger = std::make_shared<FileLogger>(logFileName);
    return Game{board_1, board_2, logger};
}

Game Game::make_replay_console(const std::vector<std::string> &moves) {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    std::shared_ptr<ConsoleLogger> info_logger = std::make_shared<ConsoleLogger>();
    auto moves_iterator = std::make_shared<std::vector<std::string>::const_iterator>(moves.begin());
    return Game{board_1, board_2, info_logger, info_logger, moves_iterator, moves.end()};
}

Game Game::make_replay_file(const std::shared_ptr<FileLogger> &info_logger, const std::vector<std::string> &moves) {
    std::shared_ptr<Board> board_1 = std::make_shared<Board>();
    std::shared_ptr<Board> board_2 = std::make_shared<Board>();
    auto moves_iterator = std::make_shared<std::vector<std::string>::const_iterator>(moves.begin());
    return Game{board_1, board_2, info_logger, info_logger, moves_iterator, moves.end()};
}