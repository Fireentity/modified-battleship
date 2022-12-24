#include "Game.h"

Game::Game() : player_1{std::make_shared<AI>()}, player_2{std::make_shared<>()} {

}
