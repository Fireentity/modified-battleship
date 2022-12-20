#ifndef SHIP_H
#define SHIP_H

#include "Point.h"
#include "board/BoardPiece.h"
#include "board/DefenceBoard.h"

class Ship {
private:
    Point position_;
    const unsigned short width_;
    const unsigned short height_;
    unsigned short health_;
public:

    Ship(const Point&, unsigned short width, unsigned short height, unsigned short health);

    unsigned int get_x() const;

    unsigned int get_y() const;

    unsigned short get_width() const;

    unsigned short get_height() const;

    unsigned short get_health() const;

    virtual char get_character() const = 0;

    virtual void place(const DefenceBoard &defence_board) const = 0;
};

#endif //SHIP_H
