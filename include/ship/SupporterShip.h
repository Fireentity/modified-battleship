#ifndef SUPPORTERSHIP_H
#define SUPPORTERSHIP_H

#include "Point.h"
#include "ShipPiece.h"
#include "ship/Ship.h"
#include "action/HitAction.h"

class SupporterShip: public Ship {
public:
    static const char damaged_character;
    static const char character;
    static const unsigned short supporter_ship_length;
    static const int breadth;

    SupporterShip(const Point &point, int width, int height, const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    char get_damaged_character() const override;

    char get_character() const override;
};

#endif //SUPPORTERSHIP_H
