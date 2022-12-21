#ifndef PROGETTO_FINALE_BOARDPIECE_H
#define PROGETTO_FINALE_BOARDPIECE_H

#include <memory>
#include "ship/Ship.h"

class BoardPiece {
private:
    std::shared_ptr<Ship> ship_;
    bool hit_;
public:
    explicit BoardPiece(std::shared_ptr<Ship>);

    BoardPiece();

    const std::shared_ptr<Ship> &get_ship() const;

    void set_ship(const std::shared_ptr<Ship> &ship);

    bool is_hit() const;

    void set_hit(bool hit);
};

#endif //PROGETTO_FINALE_BOARDPIECE_H
