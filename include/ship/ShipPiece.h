#ifndef SHIPPIECE_H
#define SHIPPIECE_H

#include "Point.h"
#include "board/DefenceBoard.h"

class ShipPiece {
private:
    std::shared_ptr<DefenceBoard> defence_board_;
    std::shared_ptr<Ship> ship_;
    Point position_;
    bool hit_;
public:
    ShipPiece(const Point &, const std::shared_ptr<DefenceBoard> &, const std::shared_ptr<Ship> &);

    bool can_move(int x, int y);

    void move(int x, int y);

    const Point &get_position();

    bool is_hit();

    void hit();
};

#endif //SHIPPIECE_H
