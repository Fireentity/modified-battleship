#include <iterator>
#include "player/ReplayPlayer.h"
#include "Game.h"


std::vector<std::string> get_moves_or_empty(const std::string &name_file_log) {
    std::ifstream file(name_file_log);
    if (!file.good() || !file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return {}; //ritorna un vettore vuoto
    }
    std::vector<std::string> moves;
    std::string line;
    while (std::getline(file, line)) {
        moves.push_back(line);
    }
    file.close();
    return moves;
}

int main(int argc, char *argv[]) {

    //TESTING: *****************************************************
    std::vector<std::string> moves = get_moves_or_empty("moves.txt");
    if (moves.empty()) {
        std::cout
                << "C'è un problema nella lettura del file, riprovare inserendo come argomento il nome di un file valido"
                << std::endl;
    } else {
        Game replay = Game::make_replay(std::make_shared<FileLogger>("uscita.txt"), moves);
        std::cout << "Moves" << std::endl;
        replay.start_loop();
    }


    //*****************************************************************

    std::regex regex{R"(([\w\-_\.]+).txt)"};

    if (argc != 3 && argc != 4) { //argc tiene conto anche del nome del programma stesso
        std::cout << "Argomento da riga di comando non dato o non nel numero richiesto" << std::endl;
        return 0;
    }

    std::string command(argv[1]);

    if (command == "v" && argc == 3) {
        std::string name_file_log(argv[2]);
        std::vector<std::string> moves = get_moves_or_empty(name_file_log);
        if (moves.empty()) {
            std::cout
                    << "C'è un problema nella lettura del file, riprovare inserendo come argomento il nome di un file valido"
                    << std::endl;
        } else {
            Game replay = Game::make_replay(std::make_shared<ConsoleLogger>(), moves);
            replay.start_loop();
        }
    } else if (command == "f" && argc == 4) {
        std::string name_file_log(argv[2]);
        std::string name_file_output_replay(argv[3]);
        if (name_file_output_replay.empty()) {
            std::cout << "Il file di output per il replay non è valido!" << std::endl;
            return 0;
        }
        std::vector<std::string> moves = get_moves_or_empty(name_file_log);
        if (moves.empty()) {
            std::cout
                    << "C'è un problema nella lettura del file, riprovare inserendo come argomento il nome di un file valido"
                    << std::endl;
        } else {
            Game replay = Game::make_replay(std::make_shared<FileLogger>(name_file_output_replay), moves);
            replay.start_loop();
        }
    } else {
        std::cout << "Argomento da riga di comando non riconosciuto" << std::endl;
    }
}
