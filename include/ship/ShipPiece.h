#ifndef SHIPPIECE_H
#define SHIPPIECE_H

class Board;
#include <memory>
#include "Point.h"

class ShipPiece {
private:
    Point position_;
    bool hit_ = false;
public:

    explicit ShipPiece(const Point &position);

    ShipPiece();

    void move_to(const Point &point);

    const Point &get_position() const;

    bool is_hit();

    void hit();
};

#endif //SHIPPIECE_H
