#ifndef HUMAN_H
#define HUMAN_H

#include "board/Board.h"
#include "Player.h"
#include <iostream>
#include <regex>

class Human : public Player {
private:
    bool place_in_board(Ship::Ships ship);
    bool ask_action();
public:
    //Le costanti vengono scritte in camel case invece che in maiuscolo per evitare di
    //avere conflitti con le macro. Tutti gli altri field sono scritti in snake case.
    //Le regex permettono di controllare che l'input dell'utente sia del formato corretto
    static const std::regex inputCharacterRegex;
    static const std::regex inputRegex ;

    Human(const std::shared_ptr<Board> &board, const std::shared_ptr<Board> &enemy_board);

    static int to_index(const std::string &slot);

    void do_move() override;

    void place_ships_inside_board() override;
};

#endif //HUMAN_H
