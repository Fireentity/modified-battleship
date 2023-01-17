//Marco Pavanetto 2032486

#include "ship/Submarine.h"

const char Submarine::damagedCharacter = 'e';
const char Submarine::character = 'E';
const unsigned short Submarine::length = 1;
const int Submarine::breadth = 1;


Submarine::Submarine(const Point &point, const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
    : Ship(point, breadth, length, Submarine::length, std::make_shared<MoveAndRevealAction>(board, enemy_board)) {
}

char Submarine::get_damaged_character() const {
    return damagedCharacter;
}

char Submarine::get_character() const {
    return character;
}
