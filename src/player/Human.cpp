#include "player/Human.h"
#include "commands/RemoveMissedCommand.h"
#include "commands/RemoveRevealedCommand.h"
#include "commands/PrintCommand.h"

/**
 *
 * @param board la board del giocatore
 * @param enemy_board la board dell'avversario
 * @param moves_logger il logger delle mosse eseguite da questo giocatore
 * @param info_logger il logger della defence board e attackboard
 * @param change_turn la funzione che viene eseguita quando correttamente un'azione
 */
Human::Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
             const std::shared_ptr<Logger> &moves_logger, const std::shared_ptr<Logger> &info_logger,
             const std::string &name, const std::function<void()> &change_turn) : Player{board, enemy_board, name},
                                                         place_command_{board, enemy_board, moves_logger},
                                                         logger_{info_logger} {

    register_command(std::make_shared<PrintCommand>(board, info_logger));
    register_command(std::make_shared<RemoveHitCommand>(board));
    register_command(std::make_shared<RemoveMissedCommand>(board));
    register_command(std::make_shared<RemoveRevealedCommand>(board));
    register_command(std::make_shared<ShipActionCommand>(board, moves_logger, change_turn));
}

void Human::place_ships_inside_board() {
    logger_->log(board_->to_string()).log("\n");
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size()) {
        std::cout << "Inserisci le coordinate della prua e della poppa ["
                  << ShipPlaceCommand::to_string(ShipPlaceCommand::availableShips[i])
                  << "]: ";

        std::string input;
        std::getline(std::cin, input);
        //Trasforma la stringa in uppercase
        std::transform(input.begin(), input.end(), input.begin(), toupper);
        if (place_command_.execute(input)) {
            i++;

            logger_->log(board_->to_string()).log("\n");
        } else {
            std::cout << "Posiziona orizzontalmente o verticalmente la nave usando le coordinate di poppa e prua "
                      << std::endl;
        }
    }
}

void Human::do_move() {
    std::string input;
    std::cout << "Inserisci le coordinate della nave e del target: ";
    std::getline(std::cin, input);
    std::transform(input.begin(), input.end(), input.begin(), toupper);
    dispatch_command(input);
}

