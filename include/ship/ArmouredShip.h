#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include "Ship.h"

class ArmouredShip : public Ship {
private:
    static const char character;
public:
    ArmouredShip(const Point &point, unsigned short width, unsigned short height, unsigned short health);

    void place(const DefenceBoard &defence_board) const override;

    char get_character() const override;
};

#endif //ARMOUREDSHIP_H
