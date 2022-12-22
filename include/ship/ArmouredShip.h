#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include "board/DefenceBoard.h"

class ArmouredShip : public Ship {
public:
    static const char piece;
    static const char damagedPiece;
    static const unsigned short breadth;
    static const unsigned short length;
    static const unsigned short max_health;

    ArmouredShip(unsigned int x, unsigned int y, bool horizontal);

    void place(DefenceBoard &defence_board) const override;

    char get_character() const override;

    char get_damaged_character() const override;
};

#endif //ARMOUREDSHIP_H
