#include "ship/ArmouredShip.h"

const char ArmouredShip::damaged_character = 'c';
const char ArmouredShip::character = 'C';
const unsigned short ArmouredShip::armoured_ship_length = 5;
const int ArmouredShip::breadth = 1;


ArmouredShip::ArmouredShip(const Point &point, int width, int height, const std::shared_ptr<Board> &board,
                           const std::shared_ptr<Board> &enemy_board) : Ship(point, width, height,
                                                                             ArmouredShip::armoured_ship_length,
                                                                             std::make_shared<HitAction>(board,enemy_board)) {

}

char ArmouredShip::get_damaged_character() const {
    return damaged_character;
}

char ArmouredShip::get_character() const {
    return character;
}
