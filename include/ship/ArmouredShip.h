#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include <stdexcept>
#include <vector>
#include <functional>
#include "ship/LinearShip.h"
#include "ShipPiece.h"

class ArmouredShip : public LinearShip {
private:
    ArmouredShip(const std::vector<Point> &positions, const Point &center, int width, int height,
                 const std::shared_ptr<Board> &board);

public: //Le constanti statiche sono state rese pubbliche per semplificarne l'accesso in quanto non possono essere modificate
    //breadth e length rappresentano le dimensioni senza considerare l'orientamento della nave.
    //Non si sarebbe potuto usare width o height come nomi di queste variabili perché l'altezza della nave assume un valore
    //diverso in base all'orientamento
    static const int breadth;
    static const int length;
    static const int max_health;
    static const char damagedPiece;
    static const char piece;

    //Questo metodo impedisce chiamate inutili al costruttore. Il costruttore, non essendo direttamente invocabile, dovrà
    //essere sempre preceduto dai controlli implementati in make_ship_or_null.
    //Viene adottato un static method factory come design pattern
    static std::shared_ptr<Ship> make_ship_or_null(const Point &bow, const Point &stern, const std::shared_ptr<Board> &board);

    bool do_action(const Point &target, Board &enemy_board) override;

    char get_damaged_character() const override;

    char get_character() const override;

    //Viene cancellato l'operatore di assegnazione per evitare lo slicing
    ArmouredShip &operator=(ArmouredShip &) = delete;
};

#endif //ARMOUREDSHIP_H
