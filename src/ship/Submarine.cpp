#include "ship/Submarine.h"

const char Submarine::damagedCharacter = 'e';
const char Submarine::character = 'E';
const unsigned short Submarine::submarineLength = 1;
const int Submarine::breadth = 1;


Submarine::Submarine(const Point &point, const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board)
    : Ship(point, breadth, submarineLength, Submarine::submarineLength, std::make_shared<MoveAndRevealAction>(board, enemy_board)) {
}

char Submarine::get_damaged_character() const {
    return damagedCharacter;
}

char Submarine::get_character() const {
    return character;
}