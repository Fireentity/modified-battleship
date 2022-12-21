#include "ship/ArmouredShip.h"

const char ArmouredShip::character = 'C';

ArmouredShip::ArmouredShip(unsigned short x, unsigned short y, unsigned short width, unsigned short height,
                           unsigned short health) : Ship(x, y, width, height, health) {

}

char ArmouredShip::get_character() const {
    return ArmouredShip::character;
}

