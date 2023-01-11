#include "player/ReplayPlayer.h"
#include "Game.h"



std::vector<std::string> get_vector(const std::string &name_file_log) {
    std::vector<std::string> moves;
    std::ifstream file(name_file_log);
    if (!file.good() || !file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return {}; //ritorna un vettore vuoto
    }
    std::string line;
    while (std::getline(file, line)) {
        moves.push_back(line);
    }
    file.close();
    return moves;
}

int main(int argc, char *argv[]) {

    std::regex regex{R"(([\w-_\.]+).txt)"};

    if (argc != 3 && argc != 4) { //argc tiene conto anche del nome del programma stesso
        std::cout << "Argomento da riga di comando non dato o non nel numero richiesto" << std::endl;
        return 0;
    }

    std::string command(argv[1]);

    if (command == "v" && argc == 3) {
        std::string name_file_log(argv[2]);
        std::vector<std::string> moves = get_vector(name_file_log);
        if (moves.empty()) {
            std::cout
                    << "C'è un problema nella lettura del file, riprovare inserendo come argomento il nome di un file valido"
                    << std::endl;
        } else {
            Game replay = Game::make_replay(moves, false, "");
            replay.start_loop();
        }
    } else if (command == "f" && argc == 4) {
        std::string name_file_log(argv[2]);
        std::string name_file_output_replay(argv[3]);
        if(name_file_output_replay.empty()){
            std::cout<<"Il file di output per il replay non è valido!"<<std::endl;
            return 0;
        }
        std::vector<std::string> moves = get_vector(name_file_log);
        if (moves.empty()) {
            std::cout
                    << "C'è un problema nella lettura del file, riprovare inserendo come argomento il nome di un file valido"
                    << std::endl;
        } else {
            Game replay = Game::make_replay(moves, true, name_file_output_replay);
            replay.start_loop();
        }
    } else {
        std::cout << "Argomento da riga di comando non riconosciuto" << std::endl;
    }
}
