#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Ship.h"

class Submarine : public Ship {
private:
    static const unsigned short thickness = 1;
    static const unsigned short length = 1;
    static const unsigned short full_health = 1;
    static const unsigned short range = 2;
    static const char character = 'E';
public:
    Submarine(unsigned int x, unsigned y);

    char get_character() const override;

    void place(const DefenceBoard &defence_board) const;
};

#endif //SUBMARINE_H
