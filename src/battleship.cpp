#include <iostream>
#include "Game.h"

int main () {
    Game game = Game::make_human_vs_ai();
    game.start_loop();
}