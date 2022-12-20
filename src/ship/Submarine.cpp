#include <stdexcept>
#include "Point.h"
#include "ship/Ship.h"
#include "ship/Submarine.h"

Submarine::Submarine(unsigned int x, unsigned int y) : Ship(Point{x,y},Submarine::thickness,Submarine::length,Submarine::full_health) {

}

void Submarine::place(const DefenceBoard &defence_board) const {
    if(defence_board.get_slot() == nullptr) {
        throw std::invalid_argument("Position already occupied by another ship");
    }

    defence_board.set_slot(this->get_x(),this->get_y(), std::make_shared<Ship>(this))
}
