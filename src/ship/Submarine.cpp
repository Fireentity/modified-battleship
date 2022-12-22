#include <stdexcept>
#include "ship/Submarine.h"

Submarine::Submarine(unsigned int x, unsigned int y) : Ship{Point{x,y},thickness,length,full_health} {

}

void Submarine::place(DefenceBoard &defence_board) const {
    if(defence_board.get_slot(this->get_x(),this->get_y()).get_ship() == nullptr) {
        throw std::invalid_argument("Position already occupied by another ship");
    }

    defence_board.set_slot(this->get_x(),this->get_y(), BoardPiece{std::make_shared<Submarine>(*this)});
}

char Submarine::get_character() const {
    return piece;
}

char Submarine::get_damaged_character() const {
    return damagedPiece;
}


