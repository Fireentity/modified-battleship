#ifndef ORIENTABLESHIP_H
#define ORIENTABLESHIP_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "ship/Ship.h"
#include "ShipPiece.h"

class LinearShip : public Ship {
private:
    bool horizontal_;
protected:
    std::vector<std::shared_ptr<ShipPiece>> pieces_;
public:
    LinearShip(int x,
               int y,
               unsigned short width,
               unsigned short height,
               unsigned short health,
               unsigned short max_health,
               const std::shared_ptr<DefenceBoard> &defence_board,
               bool horizontal);



    bool is_horizontal() const;

    bool place() override;

    bool is_valid_position(int x, int y) override;

    void move(int x, int y) override;
};

#endif //ORIENTABLESHIP_H
