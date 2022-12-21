//
// Created by lorenzo on 12/21/22.
//
#include "ship/Supporter.h"

const unsigned short Supporter::range = 1;
const char Supporter::character = 'S';

Supporter::Supporter(unsigned short x,
                     unsigned short y,
                     unsigned short width,
                     unsigned short height,
                     unsigned short health) : Ship(x, y, width, height, health) {

}

char Supporter::get_character() const {
    return Supporter::character;
}

