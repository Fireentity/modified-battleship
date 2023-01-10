#include "Game.h"

int main(int argc, char *argv[]) {

    Game game = Game::make_human_vs_ai();
    game.start_loop();

    /*
    if (argc != 2) { //argc tiene conto anche del nome del programma stesso
        std::cout << "Argomento da riga di comando non dato o non nel numero richiesto" << std::endl;
        return 0;
    }
    //TODO controllare cosa succede se la stringa non è null-terminated
    std::string command(argv[1]);
    if (command == "pc") {
        Game game = Game::make_human_vs_ai();
        game.start_loop();
        return 0;
    } else if (command == "cc") {
        Game game = Game::make_ai_vs_ai();
        game.start_loop();
        return 0;
    } else {
        std::cout << "Argomento da riga di comando non riconosciuto" << std::endl;
        return 0;
    }*/
}