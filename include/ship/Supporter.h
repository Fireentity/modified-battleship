//Marco Pavanetto 2032486

#ifndef SUPPORTERSHIP_H
#define SUPPORTERSHIP_H

#include "Point.h"
#include "ShipPiece.h"
#include "ship/Ship.h"
#include "actions/MoveAndHealAction.h"

class Supporter : public Ship {
public:
    static const char damagedCharacter;
    static const char character;
    static const unsigned short length;
    static const int breadth;

    Supporter(const Point &top_left_corner, bool horizontal, const std::shared_ptr<Board> &board,
              const std::shared_ptr<Board> &enemy_board);

    char get_damaged_character() const override;

    char get_character() const override;
};

#endif //SUPPORTERSHIP_H
