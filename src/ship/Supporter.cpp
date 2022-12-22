#include "ship/Supporter.h"

const char Supporter::piece = 'S';
const char Supporter::damagedPiece = 's';
const unsigned short Supporter::range = 1;
//TODO comment the names of the variables
const unsigned short Supporter::breadth = 1;
const unsigned short Supporter::length = 3;
const unsigned short Supporter::max_health = 3;

Supporter::Supporter(unsigned int x, unsigned int y, bool horizontal) : LinearShip{x, y,
                                                                                   horizontal ? length : breadth,
                                                                                   horizontal ? breadth : length,
                                                                                   max_health,
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
