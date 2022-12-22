#ifndef SUPPORTER_H
#define SUPPORTER_H

#include "board/DefenceBoard.h"

class Supporter : public Ship {
private:
    static const char piece = 'S';
    static const char damagedPiece = 's';
    static const unsigned short range = 1;
    //TODO comment the names of the variables
    static const unsigned short breadth = 1;
    static const unsigned short length = 3;
    static const unsigned short max_health = 3;

public:
    Supporter(unsigned int x, unsigned int y,bool horizontal);

    void place(DefenceBoard &defence_board) const override;

    char get_character() const override;

    char get_damaged_character() const override;

};

#endif //SUPPORTER_H
