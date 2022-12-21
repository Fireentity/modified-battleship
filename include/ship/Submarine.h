#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship {
private:
    static const unsigned short range;
    static const char character;
public:

    Submarine(unsigned short x, unsigned short y, unsigned short width, unsigned short height, unsigned short health);

    char get_character() const override;
};

#endif //SUBMARINE_H
