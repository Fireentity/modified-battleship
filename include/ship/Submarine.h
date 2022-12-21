#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <stdexcept>
#include "ship/Ship.h"
#include "ShipPiece.h"

class Submarine : public Ship {
private:
    std::shared_ptr<ShipPiece> piece_;
public:
    //breadth e length rappresentano le dimensioni senza considerare l'orientamento della nave.
    //Non si sarebbe potuto usare width o height in quando l'altezza della nave assume un valore diverso in base
    //a se questa è disposta orizzontalmente o verticalmente. Si sono quindi scelti questi nomi per salvare le
    //dimensioni della nave corazzata
    static const int breadth = 1;
    static const int length = 1;
    static const int max_health = 1;
    static const int range = 2;
    static const char piece = 'E';
    static const char damagedPiece = 'e';

    Submarine(const Point &center, const std::shared_ptr<Board> &defence_board);

    static bool make_ship(const Point &bow, const Point &stern, const std::shared_ptr<Board> &defence_board);

    bool do_action(const Point &target, Board &enemy_board) override;

    bool is_valid_position(const Point &point) override;

    char get_damaged_character() const override;

    char get_character() const override;

    void move(const Point &destination) override;

    //Viene cancellato l'operatore di assegnazione per evitare lo slicing
    Submarine &operator=(Submarine &) = delete;

};

#endif //SUBMARINE_H
