#include "player/AI.h"

//I comandi non vengono registrati perché il robot non ha bisogno di comandi differenti da eseguire ma esegue sempre
//prima il comando di posizionamento e dopo il comando per eseguire un'azione

AI::AI(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board,
       const std::shared_ptr<Logger> &moves_logger,
       const std::function<void()> &change_turn) : Player{board, enemy_board},
                                                   place_command_{board, enemy_board, moves_logger},
                                                   action_command_{board, moves_logger, change_turn} {

}

void AI::place_ships_inside_board() {
    srand(time(nullptr));
    int i = 0;
    while (i < ShipPlaceCommand::availableShips.size()) {
        Point bow{(rand() % Board::width) + 1, (rand() % Board::height) + 1};
        bool horizontal = rand() % 2 == 0;
        if (place_command_.execute_action(bow, horizontal)) {
            i++;
        }
    }
}

void AI::do_move() {
    const std::vector<std::shared_ptr<Ship>> &ships = board_->get_ships();
    Point target{(rand() % board_->width) + 1, (rand() % board_->height) + 1};
    action_command_.execute(ships[rand() % ships.size()]->get_center(), target);
}

