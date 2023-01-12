#include "player/Human.h"
#include "commands/RemoveMissedCommand.h"
#include "commands/RemoveRevealedCommand.h"
#include "commands/PrintCommand.h"

//Il comando ShipPlaceCommand non viene registrato perché registrare i comandi serve unicamente
//per semplificare e incapsulare la scelta del comando corretto in base all'input a runtime.
//In questo caso il comando viene usato una sola volta.
Human::Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
             const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &output_logger,
             const std::function<void()> &change_turn) : Player{board, enemy_board},
                                                         place_command_{board, enemy_board, moves_logger},
                                                         logger_{output_logger} {

    register_command(std::make_shared<PrintCommand>(board,output_logger));
    register_command(std::make_shared<RemoveHitCommand>(board));
    register_command(std::make_shared<RemoveMissedCommand>(board));
    register_command(std::make_shared<RemoveRevealedCommand>(board));
    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}

void Human::place_ships_inside_board() {
    logger_->log(board_->to_string());

    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size()) {
        std::cout << "Inserisci le coordinate della prua e della poppa ["
                  << Ship::to_string(ShipPlaceCommand::availableShips[i])
                  << "]: ";

        std::string input;
        std::getline(std::cin, input);
        //Trasforma la stringa in uppercase
        std::transform(input.begin(), input.end(), input.begin(), toupper);
        if (place_command_.execute(input)) {
            i++;
            logger_->log(board_->to_string());
        } else {
            std::cout << "Posiziona orizzontalmente o verticalmente la nave usando le coordinate di poppa e prua "
                      << std::endl;
        }
    }
}

void Human::do_move() {
    std::string input;
    do {
        std::cout << "Inserisci le coordinate della nave e del target: ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), toupper);
    } while (!dispatch_command(input));
}

