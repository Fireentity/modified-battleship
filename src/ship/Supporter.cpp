#include "ship/Supporter.h"

const char Supporter::damaged_character = 's';
const char Supporter::character = 'S';
const unsigned short Supporter::supporter_ship_length = 3;
const int Supporter::breadth = 1;

Supporter::Supporter(const Point &point, bool horizontal, const std::shared_ptr<Board> &board,
                     const std::shared_ptr<Board> &enemy_board) : Ship(point,
                                                                       horizontal ? Supporter::supporter_ship_length
                                                                                        : Supporter::breadth,
                                                                       horizontal ? Supporter::breadth
                                                                                        : Supporter::supporter_ship_length,
                                                                       Supporter::supporter_ship_length,
                                                                       std::make_shared<MoveAndHealAction>(board,enemy_board)) {

}

char Supporter::get_damaged_character() const {
    return damaged_character;
}

char Supporter::get_character() const {
    return character;
}