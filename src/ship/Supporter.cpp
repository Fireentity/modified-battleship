#include "ship/Supporter.h"

const char Supporter::damagedCharacter = 's';
const char Supporter::character = 'S';
const unsigned short Supporter::supporterShipLength = 3;
const int Supporter::breadth = 1;

Supporter::Supporter(const Point &point, bool horizontal, const std::shared_ptr<Board> &board,
                     const std::shared_ptr<Board> &enemy_board) : Ship(point,
                                                                       horizontal ? Supporter::supporterShipLength
                                                                                        : Supporter::breadth,
                                                                       horizontal ? Supporter::breadth
                                                                                        : Supporter::supporterShipLength,
                                                                       Supporter::supporterShipLength,
                                                                       std::make_shared<MoveAndHealAction>(board,enemy_board)) {

}

char Supporter::get_damaged_character() const {
    return damagedCharacter;
}

char Supporter::get_character() const {
    return character;
}
