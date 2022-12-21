#ifndef SUPPORTER_H
#define SUPPORTER_H

#include "Ship.h"

class Supporter : public Ship {
private:
    static const unsigned short range;
    static const char character;
public:
    Supporter(unsigned short x, unsigned short y, unsigned short width, unsigned short height, unsigned short health);
    char get_character() const override;
};

#endif //SUPPORTER_H
