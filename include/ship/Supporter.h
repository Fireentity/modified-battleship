#ifndef SUPPORTER_H
#define SUPPORTER_H

#include "ship/LinearShip.h"

class Supporter : public LinearShip {
public:
    static const char piece;
    static const char damagedPiece;
    static const unsigned short range;
    //TODO comment the names of the variables
    static const unsigned short breadth;
    static const unsigned short length;
    static const unsigned short max_health;

    Supporter(int x, int y,bool horizontal, const std::shared_ptr<DefenceBoard> &defence_board);

    char get_damaged_character() const override;

    bool do_action(int x, int y) override;

    char get_character() const override;

    std::shared_ptr<LinearShip> get_shared_ptr() const override;
};

#endif //SUPPORTER_H
