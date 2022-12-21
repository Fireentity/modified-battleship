#include "Game.h"

Game::Game() : player_1{std::unique_ptr<AI>()}, player_2{std::unique_ptr<Human>()} {

}

void Game::start_loop() {
    player_1->place_ships_inside_board();
    player_2->place_ships_inside_board();


}
