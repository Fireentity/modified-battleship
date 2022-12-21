#include "Game.h"


Game::Game(const AI &player_1, const Human &player_2) : player_1{std::make_shared<AI>(player_1)}, player_2{
        std::make_shared<Human>(player_2)} {

}

Game::Game(const AI &player_1, const AI &player_2) : player_1{std::make_shared<AI>(player_1)}, player_2{
        std::make_shared<AI>(player_2)} {

}

void Game::start_loop() {
    player_1->place_ships_inside_board();
    player_2->place_ships_inside_board();


}
