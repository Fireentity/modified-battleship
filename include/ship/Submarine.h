#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Point.h"
#include "ShipPiece.h"
#include "ship/Ship.h"
#include "actions/MoveAndRevealAction.h"

class Submarine: public Ship {
public:
    static const char damagedCharacter;
    static const char character;
    static const unsigned short length;
    static const int breadth;

    Submarine(const Point &point, const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    char get_damaged_character() const override;

    char get_character() const override;
};


#endif //SUBMARINE_H
