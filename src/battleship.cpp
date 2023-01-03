#include "Game.h"

int main () {
    Game game = Game::make_ai_vs_ai();
    game.start_loop();
}