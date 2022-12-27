#include "ship/SupporterShip.h"

const char SupporterShip::damaged_character = 's';
const char SupporterShip::character = 'S';
const unsigned short SupporterShip::supporter_ship_length = 3;
const int SupporterShip::breadth = 1;


SupporterShip::SupporterShip(const Point &point, bool horizontal, const std::shared_ptr<Board> &board,
                           const std::shared_ptr<Board> &enemy_board) : Ship(point,
                                                                             horizontal ? SupporterShip::supporter_ship_length
                                                                                        : SupporterShip::breadth,
                                                                             horizontal ? SupporterShip::breadth
                                                                                        : SupporterShip::supporter_ship_length,
                                                                             SupporterShip::supporter_ship_length,
                                                                             std::make_shared<HitAction>(board,enemy_board)) {

}

char SupporterShip::get_damaged_character() const {
    return damaged_character;
}

char SupporterShip::get_character() const {
    return character;
}