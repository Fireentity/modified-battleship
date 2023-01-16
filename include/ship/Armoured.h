#ifndef ARMOUREDSHIP_H
#define ARMOUREDSHIP_H

#include "Point.h"
#include "ShipPiece.h"
#include "ship/Ship.h"
#include "actions/HitAction.h"

class Armoured : public Ship {
public:
    static const char damagedCharacter;
    static const char character;
    static const unsigned short length;
    static const int breadth;

    /**
     *
     * @param top_left_corner il punto in alto a sinistra di una nave di qualsiasi forma
     * @param width la larghezza della nave
     * @param height l'altezza della nave
     * @param pieces_amount il numero di pezzi della nave
     * @param action l'azione che può eseguire la nave
     */
    Armoured(const Point &top_left_corner, bool horizontal, const std::shared_ptr<Board> &board,
             const std::shared_ptr<Board> &enemy_board);

    char get_damaged_character() const override;

    char get_character() const override;
};

#endif //ARMOUREDSHIP_H
