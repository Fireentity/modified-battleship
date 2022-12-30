#include "Game.h"

const unsigned int Game::maxMoves = 30;

Game::Game(const std::shared_ptr<AI> &ai, const std::shared_ptr<Human> &human) : player_1{ai}, player_2{human}, turn(rand()%2) {

}

Game::Game(const std::shared_ptr<AI> &ai, const std::shared_ptr<AI> &human): player_1{ai}, player_2{human} {

}

void Game::start_loop() {
    player_1->place_ships_inside_board();
    player_1->get_board()->print_with_ships();
    player_2->place_ships_inside_board();
    unsigned int moves = 0;
    do {
        if (turn) {
            player_1->do_move();
        } else {
            player_2->do_move();
        }

        turn = !turn;
        moves++;
    } while (moves <= maxMoves && !player_1->available_ships.empty() && player_2->available_ships.empty());
}


