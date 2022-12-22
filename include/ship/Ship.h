#ifndef SHIP_H
#define SHIP_H

#include "Point.h"

class DefenceBoard;

class Ship {
private:
    Point position_;
    const unsigned short width_ = 1;
    const unsigned short height_ = 1;
    unsigned short health_;
public:

    Ship(const Point&, unsigned short width, unsigned short height, unsigned short health);

    unsigned int get_x() const;

    unsigned int get_y() const;

    unsigned short get_width() const;

    unsigned short get_height() const;

    unsigned short get_health() const;

    virtual char get_character() const = 0;

    virtual char get_damaged_character() const = 0;

    virtual void place(DefenceBoard &defence_board) const = 0;
};

#endif //SHIP_H
