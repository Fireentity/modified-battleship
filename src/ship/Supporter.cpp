#include "ship/Supporter.h"

const char Supporter::piece = 'S';
const char Supporter::damagedPiece = 's';
const unsigned short Supporter::range = 1;
//TODO comment the names of the variables
const unsigned short Supporter::breadth = 1;
const unsigned short Supporter::length = 3;
const unsigned short Supporter::max_health = 3;

Supporter::Supporter(int x, int y, bool horizontal, DefenceBoard &defence_board)
        : LinearShip{x, y,
                     horizontal? length: breadth,
                     horizontal? breadth: length,
                     max_health,
                     max_health,
                     defence_board,
                     horizontal} {
}

char Supporter::get_character() const {
    return piece;
}

char Supporter::get_damaged_character() const {
    return damagedPiece;
}

std::shared_ptr<LinearShip> Supporter::get_shared_ptr() const {
    return std::make_shared<Supporter>(*this);
}

bool Supporter::do_action(int x, int y) {
    if(health_ == 0) {
        return false;
    }

    if(can_move(x,y)) {
        return false;
    }

    move(x,y);

    int center_x = get_center_x() -(range/2);
    int center_y = get_center_x() -(range/2);
    for(int i = 0; i < range; i++) {
        for(int j = 0; j < range; j++) {
            const std::shared_ptr<Ship> &ship = defence_board_.get_slot(center_x + j,center_y + i).get_ship();
            if(ship != nullptr) {
                ship->set_health(ship->get_max_health());
            }
        }
    }

    return true;
}
