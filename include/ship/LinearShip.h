#ifndef ORIENTABLESHIP_H
#define ORIENTABLESHIP_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "board/BoardSlot.h"
#include "board/DefenceBoard.h"
#include "ShipPiece.h"

class LinearShip : public Ship {
private:
    bool horizontal_;
protected:
    std::vector<std::shared_ptr<ShipPiece>> pieces;
public:
    LinearShip(int x,
               int y,
               unsigned short width,
               unsigned short height,
               unsigned short health,
               unsigned short max_health,
               DefenceBoard &defence_board,
               bool horizontal);

    bool is_horizontal() const;

    void place() const override;

    bool can_move(int x, int y) override;

    void move(int x, int y) override;

    virtual std::shared_ptr<LinearShip> get_shared_ptr() const = 0;

};

#endif //ORIENTABLESHIP_H
