#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include "Ship.h"

class ArmouredShip : public Ship {
private:
    static const char character;
public:
    ArmouredShip(unsigned short x, unsigned short y, unsigned short width, unsigned short height, unsigned short health);
    char get_character() const override;
};

#endif //ARMOUREDSHIP_H
