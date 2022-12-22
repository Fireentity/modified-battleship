#ifndef BOARDPIECE_H
#define BOARDPIECE_H

#include <memory>
#include <ostream>
#include "ship/Ship.h"

class Ship;

class BoardPiece {
private:
    std::shared_ptr<Ship> ship_;
    bool hit_;

public:
    explicit BoardPiece(const std::shared_ptr<Ship> &);

    BoardPiece();

    const std::shared_ptr<Ship> &get_ship() const;

    void set_ship(const std::shared_ptr<Ship> &ship);

    bool is_hit() const;

    void set_hit(bool hit);
};

std::ostream &operator<<(std::ostream &os, const BoardPiece &piece);

#endif //BOARDPIECE_H
