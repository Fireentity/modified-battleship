#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "board/DefenceBoard.h"

class Submarine : public Ship {
public:
    //TODO explain why are these public
    static const unsigned short thickness = 1;
    static const unsigned short length = 1;
    static const unsigned short full_health = 1;
    static const unsigned short range = 2;
    static const char piece = 'E';
    static const char damagedPiece = 'e';

    Submarine(unsigned int x, unsigned y);

    char get_character() const override;

    char get_damaged_character() const override;

    void place(DefenceBoard &defence_board) const override;
};

#endif //SUBMARINE_H
