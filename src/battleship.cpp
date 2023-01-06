#include "Game.h"

int main (int argc, char *argv[]) {

    /*
     * TODO togliere navi quando hanno vita a zero!
     * TODO classe Replay
     * TODO sistemare e decidere come fare la parte grafica, tipo la visualizzazione delle navi a schermo quando giocano le due AI o quella del giocatore
     * */
    Game game = Game::make_human_vs_ai(); //solo test
    game.start_pc_loop();
    if(argc!=2){ //argc tiene conto anche del nome del programma stesso
        std::cout<<"Argomento da riga di comando non dato o non nel numero richiesto"<<std::endl;
        return 0;
    }
    std::string command(argv[1]);
    if(command == "pc"){
        Game game = Game::make_human_vs_ai();
        game.start_pc_loop();
    } else if(command == "cc"){
        Game game = Game::make_ai_vs_ai();
        game.start_cc_loop();
    } else{
        std::cout<<"Argomento da riga di comando non riconosciuto"<<std::endl;
        return 0;
    }

}