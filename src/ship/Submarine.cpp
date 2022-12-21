#include "ship/Submarine.h"

const unsigned short Submarine::range = 2;
const char Submarine::character = 'E';

Submarine::Submarine(unsigned short x, unsigned short y, unsigned short width, unsigned short height,
                     unsigned short health) : Ship(x, y, width, height, health) {

}

char Submarine::get_character() const {
    return character;
}

