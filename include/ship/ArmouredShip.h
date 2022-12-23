#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include <stdexcept>
#include <vector>
#include "board/DefenceBoard.h"
#include "ship/LinearShip.h"
#include "ShipPiece.h"

class ArmouredShip : public LinearShip {
public:
    static const char piece;
    static const char damagedPiece;
    static const unsigned short breadth;
    static const unsigned short length;
    static const unsigned short max_health;

    ArmouredShip(int x, int y, bool horizontal, DefenceBoard &defence_board);

    std::shared_ptr<LinearShip> get_shared_ptr() const override;

    char get_damaged_character() const override;

    bool do_action(int x, int y) override;

    char get_character() const override;

    ArmouredShip & operator=(ArmouredShip &) = delete;
};

#endif //ARMOUREDSHIP_H
