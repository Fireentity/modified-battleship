#ifndef HUMAN_H
#define HUMAN_H

#include "board/Board.h"
#include "Player.h"
#include <iostream>
#include <regex>

class Human : public Player {
private:
    Board board_;

    bool place_board(Ships ship);
    bool ask_input(Board &enemy_board);
public:

    static const std::regex inputCharacterRegex;
    static const int firstUpperCaseLetter;
    //Le costanti vengono scritte in camel case invece che in maiuscolo per evitare di
    //avere conflitti con le macro. Tutti gli altri field sono scritti in snake case
    static const std::regex inputRegex;

    std::shared_ptr<Board> place_ships_inside_board() override;

    static int to_index(const std::string &slot);

    void do_move(Board &enemy_board);
};

#endif //HUMAN_H
