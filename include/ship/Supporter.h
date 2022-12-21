#ifndef SUPPORTER_H
#define SUPPORTER_H

#include "ship/LinearShip.h"

class Supporter : public LinearShip {
private:
    Supporter(const std::vector<Point> &positions, const Point &center, int width, int height,
              const std::shared_ptr<Board> &board);

public:
    //breadth e length rappresentano le dimensioni senza considerare l'orientamento della nave.
    //Non si sarebbe potuto usare width o height in quando l'altezza della nave assume un valore diverso in base
    //a se questa è disposta orizzontalmente o verticalmente. Si sono quindi scelti questi nomi per salvare le
    //dimensioni della nave di supporto
    static const unsigned short breadth;
    static const unsigned short length;
    static const char piece;
    static const char damagedPiece;
    static const unsigned short range;
    static const unsigned short max_health;

    static std::shared_ptr<Ship> make_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board);

    bool do_action(const Point &target, Board &enemy_board) override;

    char get_damaged_character() const override;

    char get_character() const override;

    //Viene cancellato l'operatore di assegnazione per evitare lo slicing
    Supporter &operator=(Supporter &) = delete;
};

#endif //SUPPORTER_H
