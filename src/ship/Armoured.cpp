#include "ship/Armoured.h"

const char Armoured::damagedCharacter = 'c';
const char Armoured::character = 'C';
const unsigned short Armoured::length = 5;
const int Armoured::breadth = 1;

Armoured::Armoured(const Point &top_left_corner, bool horizontal, const std::shared_ptr<Board> &board,
                   const std::shared_ptr<Board> &enemy_board) : Ship(top_left_corner,
                                                                     horizontal ? Armoured::length
                                                                                : Armoured::breadth,
                                                                     horizontal ? Armoured::breadth
                                                                                : Armoured::length,
                                                                     Armoured::length,
                                                                     std::make_shared<HitAction>(board, enemy_board)) {
}

char Armoured::get_damaged_character() const {
    return damagedCharacter;
}

char Armoured::get_character() const {
    return character;
}

