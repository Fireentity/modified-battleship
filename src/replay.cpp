#include "player/ReplayPlayer.h"
#include <thread>
#include "Game.h"
int main(int argc, char *argv[]){

    if (argc != 2 && argc!=3) { //argc tiene conto anche del nome del programma stesso
        std::cout << "Argomento da riga di comando non dato o non nel numero richiesto" << std::endl;
        return 0;
    }
    std::vector<std::string> moves;
    Game a = Game::make_replay(moves);
    //TODO mettere le mosse in moves
    //TODO come stampare tutto su un file e non su console
    std::string command(argv[1]);
    if (command == "v") {
        Game game = Game::make_human_vs_ai();
        game.start_loop();
        std::this_thread::sleep_for(std::chrono::seconds(1)); //TODO dove metterlo?
        return 0;
    } else if (command == "f") {
        Game game = Game::make_ai_vs_ai();
        game.start_loop();
        return 0;
    } else {
        std::cout << "Argomento da riga di comando non riconosciuto" << std::endl;
        return 0;
    }
}
