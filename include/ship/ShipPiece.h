#ifndef SHIPPIECE_H
#define SHIPPIECE_H

#include <memory>
#include <ostream>
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

    bool is_hit() const;

    void hit();

    void heal();
};

#endif //SHIPPIECE_H
