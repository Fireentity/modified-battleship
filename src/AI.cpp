#include "AI.h"

std::shared_ptr<DefenceBoard> AI::place_ships_inside_board() {
    int i = 0;
    //Itero tutte le navi da piazzare fin quando non sono tutte posizionate
    while (i < available_ships.size()) {

        Ships ship_type = Player::available_ships[i];
        int x = rand() % defence_board->get_width();
        int y = rand() % defence_board->get_height();
        std::shared_ptr<Ship> ship = Player::factory.at(ship_type)(x, y, true, defence_board);

        //Incremento solo quando la nave è stata creata
        if(ship != nullptr) {
            i++;
        }

    }

    return defence_board;
}
