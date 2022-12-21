#ifndef SHIP_H
#define SHIP_H

#include "board/BoardPiece.h"

class Ship {
private:
    std::pair<int, int> position_;
    const unsigned short width_;
    const unsigned short height_;
    unsigned short health_;
public:

    Ship(std::pair<int,int>, unsigned short width, unsigned short height, unsigned short health);

    unsigned short get_x() const;

    unsigned short get_y() const;

    unsigned short get_width() const;

    unsigned short get_height() const;

    unsigned short get_health() const;

    template <int N>
    void insert_into(const BoardPiece (& piece)[N][N]) const;

    virtual char get_character() const = 0;
};

#endif //SHIP_H
