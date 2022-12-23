#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <stdexcept>
#include "ship/Ship.h"
#include "board/DefenceBoard.h"
#include "board/BoardSlot.h"
#include "ShipPiece.h"

class Submarine : public Ship {
private:
    ShipPiece &piece_;
public:
    //TODO explain why are these public
    static const unsigned short thickness = 1;
    static const unsigned short length = 1;
    static const unsigned short max_health = 1;
    static const unsigned short range = 2;
    static const char piece = 'E';
    static const char damagedPiece = 'e';

    Submarine(int x, int y, DefenceBoard &defence_board);

    char get_damaged_character() const override;

    bool do_action(int x, int y) override;

    char get_character() const override;

    bool can_move(int x, int y) override;

    void move(int x, int y) override;

    void place() const override;

};

#endif //SUBMARINE_H
